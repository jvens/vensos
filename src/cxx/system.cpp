#include <errno.h>
#include <sys/stat.h>
#include "uart/uart.h"

/// Used to define functions as needing C linkage instead of C++
#define C_LINK extern "C"

/// The base address of the UART 1
#define UART_BASE 0x01C28400

static Serial::Uart* stream;

// undefine the errno macro
#undef errno
// link in the actual errno value
C_LINK {extern int errno;}



C_LINK {
	/// The default environment.
	char * __env[1] = { 0 };
	/// The current environment should default to the default environment.
	char **environ = __env;
}



/**
 * This function is called between running the pre_init_array and the init_array functions.
 * @details
 * This sets up the C and C++ runtime, performing operations like setting up stdin and stdout.
 */
C_LINK void _init(void)
{
	stream = new Serial::Uart(UART_BASE);
	return;
}



C_LINK void _fini(void)
{
	return;
}



/**
 * Called when the program wants to end without cleaning up files.
 * This doesn't make any sense in the OS, so eventually this should throw a
 * panic of some sort.  For now hang.
 */
C_LINK void _exit(void)
{
	while (1);
}




/**
 * Open a file.
 */
C_LINK int _open_r ( struct _reent *reent, const char * file, int flags, int mode )
{
	return 0;
}

/**
 * Close a file.
 */
C_LINK long _close_r ( struct _reent *reent, int fd )
{
	return 0;
}

/**
 * Read data from an open file.
 */
C_LINK long _read_r ( struct _reent *reent, int fd, void * buf, size_t cnt )
{
	size_t i;
	char * byte = (char *)buf;
	for ( i=0; i<cnt; i++ ) {
		*byte = stream->ReadByte();
		byte++;
	}
	return cnt;
}

/**
 * Write data to an open file.
 */
C_LINK long _write_r ( struct _reent *reent, int fd, const void * buf, size_t cnt )
{
	size_t i;
	const char * byte = (const char *)buf;
	for ( i=0; i<cnt; i++ ) {
		stream->WriteByte(*byte);
		byte ++;
	}
	return cnt;
}

/**
 * Set position in a file
 */
C_LINK int _lseek_r( struct _reent *reent, int fd, int ptr, int dir ) {
	return 0;
}

/**
 * Get the status of an open file.
 */
C_LINK int _fstat_r(struct _reent *reent, int fd, struct stat *pstat)
{
	pstat->st_mode = S_IFCHR;
  	return 0;
}

/**
 * Get the status of a file by name.
 */
C_LINK int _stat_r(struct _reent *reent, char * file, struct stat *pstat)
{
	pstat->st_mode = S_IFCHR;
	return 0;
}

/**
 * Query whether output stream is a terminal.
 */
C_LINK int _isatty_r(void *reent, int fd)
{
	return 1;
}

/**
 * Establish a new name for an existing file.
 */
C_LINK int _link_r ( struct _reent *reent, char * old_name, char * new_name)
{
	reent->_errno = EMLINK;
	return -1;
}

/**
 * Remove a file's directory entry.
 */
C_LINK int _unlink_r ( struct _reent *reent, char * name )
{
	reent->_errno = ENOENT;
	return -1;
}

/**
 * Create a new process.
 */
C_LINK int _fork_r ( struct _reent *reent )
{
	reent->_errno = EAGAIN;
	return -1;
}

/**
 * Transfer control to a new process.
 */
C_LINK int _execve ( char * name, char ** argv, char ** env )
{
	errno = ENOMEM;
	return -1;
}

/**
 * Get the ID of this process.
 */
C_LINK int _getpid(void) {
  return 1;
}

/**
 * Timing information for current process.
 */
C_LINK int _times ( struct tms * buf )
{
	return -1;
}

/**
 * Wait for a child process.
 */
C_LINK int _wait_r ( struct _reent * reent, int * status)
{
	reent->_errno = ECHILD;
	return -1;
}

/**
 * Send a signal to a process.
 */
C_LINK int _kill ( int pid, int sig )
{
	errno = EINVAL;
	return -1;
}




#define HEAPSIZE 1024*1024// 1MB heap
unsigned char _heap[HEAPSIZE]; 
C_LINK caddr_t _sbrk_r ( int incr )
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


