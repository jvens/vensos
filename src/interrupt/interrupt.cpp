/*
 * interrupt.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vens
 */


#include "regs.h"
#include <stdio.h>

namespace vensos {
namespace core {
namespace interrupt{
#define BASE_ADDRESS (volatile intc_reg_t * const)0x01C20400
volatile intc_reg_t * const intc = BASE_ADDRESS;


extern "C" unsigned int __interrupt_table_start__;
extern "C" unsigned int __interrupt_table_end__;


extern "C" {
	typedef void (*isr_vector)(void);

	void __isr_undefined(void ) __attribute__((interrupt ("IRQ")));
	void __isr_undefined(void)
	{
		printf("__isr_undefined()\r\n");
		// do nothing.
	}

#define ISR_T(name) void name(void) __attribute__ ((weak, alias("__isr_undefined")))

	ISR_T( isr_ExternalNMI );
	ISR_T( isr_UART1 );
	ISR_T( isr_UART3 );
	ISR_T( isr_IR );
	ISR_T( isr_TWI0 );
	ISR_T( isr_TWI1 );
	ISR_T( isr_TWI2 );
	ISR_T( isr_SPI0 );
	ISR_T( isr_SPI1 );
	ISR_T( isr_SPI2 );
	ISR_T( isr_Timer0 );
	ISR_T( isr_Timer1 );
	ISR_T( isr_Timer2 );
	ISR_T( isr_Timer3 );
	ISR_T( isr_DMA );
	ISR_T( isr_PIO );
	ISR_T( isr_TouchPanel );
	ISR_T( isr_AudioCodec );
	ISR_T( isr_LRADC );
	ISR_T( isr_SD_MMC_0 );
	ISR_T( isr_SD_MMC_1 );
	ISR_T( isr_SD_MMC_2 );
	ISR_T( isr_NAND );
	ISR_T( isr_USB_OTG );
	ISR_T( isr_USB_EHCI );
	ISR_T( isr_USB_OHCI );
	ISR_T( isr_CSI );
	ISR_T( isr_LCD_Controller );
	ISR_T( isr_DE_FE_DE_BE );
	ISR_T( isr_PMU );
	ISR_T( isr_VE );
	ISR_T( isr_CE );
	ISR_T( isr_PLE_PERFMU );
	ISR_T( isr_Timer4 );
	ISR_T( isr_Timer5 );
	ISR_T( isr_GPU_GP );
	ISR_T( isr_GPU_GPMMU );
	ISR_T( isr_GPU_PP0 );
	ISR_T( isr_GPU_PPMMU0 );
	ISR_T( isr_GPU_PMU );
	ISR_T( isr_GPU_RSV0 );
	ISR_T( isr_GPU_RSV1 );
	ISR_T( isr_GPU_RSV2 );
	ISR_T( isr_GPU_RSV3 );
	ISR_T( isr_GPU_RSV4 );
	ISR_T( isr_GPU_RSV5 );
	ISR_T( isr_GPU_RSV6 );
	ISR_T( isr_SyncTimer0 );
	ISR_T( isr_SyncTimer1 );
	ISR_T( isr_Invalid );
}


void print_int_ctrler (void);
extern "C" {
	void _reset_vect(void) {
		printf("_reset_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

	void _undefined_instruction_vect(void) __attribute__((interrupt ("IRQ")));
	void _undefined_instruction_vect(void) {
		printf("_undefined_instruction_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		intc->FORCE_bits.Timer2 = 0;
		isr_Timer2();
		printf("After isr_Timer2() call\r\n");
		while(1);
	}

	void _software_interrupt_vect(void) __attribute__((interrupt ("IRQ")));
	void _software_interrupt_vect(void) {
		printf("_software_interrupt_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}


	void _prefetch_abort_vect(void) {
		printf("_prefetch_abort_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

	void _data_abort_vect(void) {
		printf("_data_abort_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

	void _unused_handler_vect(void) {
		printf("_unused_handler_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

	void _interrupt_vect(void) {
		printf("_interrupt_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

	void _fast_interrupt_vect(void) {
		printf("_fast_interrupt_vect()\r\n");
		vensos::core::interrupt::print_int_ctrler ();
		while(1);
	}

}






void print_int_ctrler (void)
{
	//int * i = (int*) BASE_ADDRESS;
	int i;
	printf("Table Start: 0x%08X, End: 0x%08X, Size: %d\r\n", (unsigned int)&__interrupt_table_start__,
				(unsigned int)&__interrupt_table_end__, (unsigned int)&__interrupt_table_end__ - (unsigned int)&__interrupt_table_start__);

	for(i = 0;i<=0x0094;i+=4){
		printf("0x%04X: 0x%08X\r\n",i,*((int*)(0x01c20400 + i)));
	}
}


#define offset(x) (x)/4

//#define __disable_interrupt() asm volatile ("msr     CPSR_c, #0x9F")
//#define __enable_interrupt() asm volatile ("msr     CPSR_c, #0x1F")

extern "C" {
	extern void _enable_interrupts(void);
}



void init_interrupts()
{
//	volatile int * reg_list = (volatile int*) BASE_ADDRESS;

	printf("Table Start: 0x%08X, End: 0x%08X, Size: %d\r\n", (unsigned int)&__interrupt_table_start__,
				(unsigned int)&__interrupt_table_end__, (unsigned int)&__interrupt_table_end__ - (unsigned int)&__interrupt_table_start__);

	intc->BASE_ADDR = (unsigned int)&__interrupt_table_start__;

	intc->MASK_bits.Timer2 = 1;
	intc->PRIO_bits.Timer2 = 3;
//	intc->SEL_bits.Timer2 = 1;
	intc->EN_bits.Timer2 = 1;
	intc->FORCE_bits.Timer2 = 1;

//	reg_list[offset(0x0004)] = (unsigned int)&__interrupt_table_start__;
//	reg_list[offset(0x0040)] |= 1 << 24;
//	reg_list[offset(0x0050)] |= 1 << 24;
	_enable_interrupts();
}
}
}
}
