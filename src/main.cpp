
#include "uart/uart.h"
//#include <string>
#include "int.h"
#define UART_BASE 0x01C28400

//-------------------------------------------------------------------
//-------------------------------------------------------------------

extern void PUT32 ( unsigned int, unsigned int ) __asm__("PUT32");
extern unsigned int GET32 ( unsigned int ) __asm__("GET32");
extern void ASMDELAY ( unsigned int ) __asm__("ASMDELAY");
extern unsigned int MIDR ( void ) __asm__("MIDR");
extern unsigned int ID_PFR0 ( void ) __asm__("ID_PFR0");
extern unsigned int ID_PFR1 ( void ) __asm__("ID_PFR1");
extern unsigned int ID_DFR0 ( void ) __asm__("ID_DFR0");
extern unsigned int ID_AFR0 ( void ) __asm__("ID_AFR0");
extern unsigned int CPACR ( void ) __asm__("CPACR");
extern unsigned int FPSID ( void ) __asm__("FPSID");
extern unsigned int ID_ISAR0 ( void ) __asm__("ID_ISAR0");

//-------------------------------------------------------------------------
using namespace Serial;


Uart u(UART_BASE);


int main ( void )
{
   	unsigned int * i;
   	//std::string test = "hello";
   	u.puts("puts\n\r");
   	//printf("Hello, World from Printf\n\r");
   	//std::cout << "Hello World!\n\r";
   	
   	union {
   		struct {
	   		reg_rw var1;
	   		struct {
	   			unsigned b1 : 1;
	   			unsigned b2 : 1;
	   			unsigned b3 : 3;
	   			bit_ro   b4 : 1;
	   			unsigned b5 : 2;
	   		}var2;
	   	}s;
	   	u32 d[2];
	} test;
	u.puts("step 1\n\r");
	test.d[0] = 0;
	test.d[1] = 0;
	u.hexstring(test.d[0]);
	u.hexstring(test.d[1]);
   	
   	test.s.var1 = 0xAA;
   	test.s.var2.b1 = 0x1;
   	u.puts("step 2\n\r");
	u.hexstring(test.d[0]);
	u.hexstring(test.d[1]);
   	
   	test.s.var1 = 0x42;
   	test.s.var2.b3 = 0x5;
   	test.s.var2.b5 = 0x1;
   	u.puts("step 3\n\r");
	u.hexstring(test.d[0]);
	u.hexstring(test.d[1]);
   	
   	test.s.var1 = 0x24;
   	test.s.var2.b4 = 0x1;
   	test.s.var2.b1 = 0x0;
   	u.puts("step 4\n\r");
	u.hexstring(test.d[0]);
	u.hexstring(test.d[1]);
   	
   	while(1);
   	u.puts("Divisor: ");
   	u.hexstring(u.GetDivisor());
   	
    u.hexstring(0x12345678);
    
    for(i=(unsigned int*)UART_BASE; i<=(unsigned int*)(UART_BASE + 0xA4); i++)
    {
    	u.hexstring(*i);
    }
    //u.hexstring(0);
    //u.hexstring(MIDR());
    //u.hexstring(ID_PFR0());
    //u.hexstring(ID_PFR1());
    //u.hexstring(ID_DFR0());
    //u.hexstring(ID_AFR0());
    //u.hexstring(CPACR());
    //u.hexstring(ID_ISAR0());
    //u.hexstring(FPSID());
    u.hexstring(0x12345678);
    while (1);
    return(0);
}
//-------------------------------------------------------------------

//-------------------------------------------------------------------
//-------------------------------------------------------------------

