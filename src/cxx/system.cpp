#include <errno.h>
#include <sys/stat.h>
#include "uart/uart.h"
#define UART_BASE 0x01C28400
Serial::Uart stream(UART_BASE);

// http://www.billgatliff.com/newlib.html

extern "C"{


int _fork_r ( struct _reent *ptr )
{
	//ptr->errno = ENOTSUP;
	return -1;
}

long _write_r ( struct _reent *ptr, int fd, const void * buf, size_t cnt )
{
	size_t i;
	const char * byte = (const char *)buf;
	for ( i=0; i<cnt; i++ ) {
		stream.WriteByte(*byte);
		byte ++;
	}
	return cnt;
}

long _read_r ( struct _reent *ptr, int fd, void * buf, size_t cnt )
{
	size_t i;
	char * byte = (char *)buf;
	for ( i=0; i<cnt; i++ ) {
		*byte = stream.ReadByte();
		byte++;
	}
	return cnt;
}

int _open_r ( struct _reent *ptr, const char * file, int flags, int mode )
{
	return 0;
}

long _close ( struct _reent *ptr, int fd )
{
	return 0;
}

#define HEAPSIZE 1024*1024// 1MB heap
unsigned char _heap[HEAPSIZE]; 
caddr_t _sbrk_r ( int incr )
{
	static unsigned char *heap_end = 0;
	unsigned char *prev_heap_end;
	
	if ( heap_end == 0 ) heap_end = 0;
	
	prev_heap_end = heap_end;
	
	if (heap_end + incr - _heap > HEAPSIZE) {
		//write (2, "Heap overflow!\n\r", 15);
		//abort();
		return 0;
	}
	
	heap_end += incr;
	
	return (caddr_t) prev_heap_end;
}

void _exit(void)
{
	while (1);
}

int _fstat_r(void *reent, int fd, struct stat *pstat)
{
	pstat->st_mode = S_IFCHR;
  	return 0;
}

int _isatty_r(void *reent, int fd) 
{
	return 1;
}

int _lseek_r(void *reent, int fd, int ptr, int dir) {
	return 0;
}

//int lseek(int file, int ptr, int dir) {
//  	return 0;
//}

//int isatty(int file) {
//  	return 1;
//}


}
