//#include <iostream>
#include <stdlib.h>
#include <stdio.h>

//#include <string>
#include "int.h"
#include "interrupt/regs.h"
#include "timer/timer.h"

#include "interrupt/interrupt.h"
struct RegList {
	int Reg[16];
	int APSR;
};

using namespace vensos::timer;

volatile int flag = 0;

ISR(Timer2) {
	printf("Timer 2\r\n");
	flag++;
}


/*ISR(UART1) {
	// test
}*/

/*FIQ_ISR(UART3){

}*/




volatile struct REGISTERS  * const TimerReg = (volatile struct REGISTERS *) 0x01C20C00;//__attribute__((section (".timer")));


void func(void){
	printf("test\r\n");
}

struct fp_test{
	void (*fp1)(void);
	void (*fp2)(void);
	void (*fp3)(void);
	void (*fp4)(void);
};

union u{
	struct {
		unsigned a : 1;
		unsigned b : 3;
		unsigned c : 4;
		unsigned d : 24;
		unsigned e : 1;
		unsigned f : 7;
		unsigned g : 8;
		unsigned h : 16;
		unsigned i : 32;
	};
	uint32_t data[3];
} var;

#define split(i) (unsigned int)(((i)>>16)&0xFFFF), (unsigned int)((i)&0xFFFF)
void pdata(const union u * d) {
	printf("data[0] = 0x%04X%04X\r\n", split(d->data[0]));
	printf("data[1] = 0x%04X%04X\r\n", split(d->data[1]));
	printf("data[2] = 0x%04X%04X\r\n", split(d->data[2]));
}

using namespace vensos::core::interrupt;

extern "C" unsigned int __exception_table_start__;

int main ( int argc, char ** argv )
{
	printf("\r\n================================================================\r\n");
	struct {
		uint32_t main_id;
		uint32_t cache_type;
		uint32_t tcm_type;
		uint32_t tlb_type;
		uint32_t multiprocessor_id;
		uint32_t processor_feature_0;
		uint32_t processor_feature_1;
		uint32_t debug_feature;
		uint32_t aux_feature;
		uint32_t mem_model_feature_0;
		uint32_t mem_model_feature_1;
		uint32_t mem_model_feature_2;
		uint32_t mem_model_feature_3;
		uint32_t inst_set_attribute_0;
		uint32_t inst_set_attribute_1;
		uint32_t inst_set_attribute_2;
		uint32_t inst_set_attribute_3;
		uint32_t inst_set_attribute_4;
		uint32_t cache_level_id;
		uint32_t silicon_id;
		uint32_t cache_size_id;
		uint32_t cache_size_sel;
		//uint32_t control;
		//uint32_t aux_control;
		//uint32_t coprocessor_access_control;
		//uint32_t secure_config;
		//uint32_t secure_debug_enable;
		//uint32_t nonsecure_access_control;
		//uint32_t translation_table_base_0;
		//uint32_t translition_table_base_1;
		//uint32_t translation_table_base_control;
		//uint32_t domain_access_control;
		//uint32_t data_fault_status;
		//uint32_t instruction_fault_status;
		//uint32_t auxiliary_fault_status;
		//uint32_t data_fault_address;
		//uint32_t instruction_fault_address;
		//uint32_t ;

	}c0;



	asm volatile (" mrc p15, 0, %0, c0, c0, 0" : "=r" (c0.main_id) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c0, 1" : "=r" (c0.cache_type) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c0, 2" : "=r" (c0.tcm_type) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c0, 3" : "=r" (c0.tlb_type) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c0, 5" : "=r" (c0.multiprocessor_id) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 0" : "=r" (c0.processor_feature_0) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 1" : "=r" (c0.processor_feature_1) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 2" : "=r" (c0.debug_feature) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 3" : "=r" (c0.aux_feature) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 4" : "=r" (c0.mem_model_feature_0) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 5" : "=r" (c0.mem_model_feature_1) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 6" : "=r" (c0.mem_model_feature_2) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c1, 7" : "=r" (c0.mem_model_feature_3) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c2, 0" : "=r" (c0.inst_set_attribute_0) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c2, 1" : "=r" (c0.inst_set_attribute_1) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c2, 2" : "=r" (c0.inst_set_attribute_2) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c2, 3" : "=r" (c0.inst_set_attribute_3) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c0, c2, 4" : "=r" (c0.inst_set_attribute_4) : /* no inputs */);
	asm volatile (" mrc p15, 1, %0, c0, c0, 1" : "=r" (c0.cache_level_id) : /* no inputs */);
	asm volatile (" mrc p15, 1, %0, c0, c0, 7" : "=r" (c0.silicon_id) : /* no inputs */);
	asm volatile (" mrc p15, 1, %0, c0, c0, 0" : "=r" (c0.cache_size_id) : /* no inputs */);
	asm volatile (" mrc p15, 2, %0, c0, c0, 0" : "=r" (c0.cache_size_sel) : /* no inputs */);

	printf("C0:\r\n");
	printf("    main_id:              0x%08lX\r\n", c0.main_id);
	printf("    cache_type:           0x%08lX\r\n", c0.cache_type);
	printf("    tcm_type:             0x%08lX\r\n", c0.tcm_type);
	printf("    tlb_type:             0x%08lX\r\n", c0.tlb_type);
	printf("    multiprocessor_id:    0x%08lX\r\n", c0.multiprocessor_id);
	printf("    processor_feature_0:  0x%08lX\r\n", c0.processor_feature_0);
	printf("    processor_feature_1:  0x%08lX\r\n", c0.processor_feature_1);
	printf("    debug_feature:        0x%08lX\r\n", c0.debug_feature);
	printf("    aux_feature:          0x%08lX\r\n", c0.aux_feature);
	printf("    mem_model_feature_0:  0x%08lX\r\n", c0.mem_model_feature_0);
	printf("    mem_model_feature_1:  0x%08lX\r\n", c0.mem_model_feature_1);
	printf("    mem_model_feature_2:  0x%08lX\r\n", c0.mem_model_feature_2);
	printf("    mem_model_feature_3:  0x%08lX\r\n", c0.mem_model_feature_3);
	printf("    inst_set_attribute_0: 0x%08lX\r\n", c0.inst_set_attribute_0);
	printf("    inst_set_attribute_1: 0x%08lX\r\n", c0.inst_set_attribute_1);
	printf("    inst_set_attribute_2: 0x%08lX\r\n", c0.inst_set_attribute_2);
	printf("    inst_set_attribute_3: 0x%08lX\r\n", c0.inst_set_attribute_3);
	printf("    inst_set_attribute_4: 0x%08lX\r\n", c0.inst_set_attribute_4);
	printf("    cache_level_id:       0x%08lX\r\n", c0.cache_level_id);
	printf("    silicon_id:           0x%08lX\r\n", c0.silicon_id);
	printf("    cache_size_id:        0x%08lX\r\n", c0.cache_size_id);
	printf("    cache_size_sel:       0x%08lX\r\n", c0.cache_size_sel);


	uint32_t secure_nonsecure_vector_base_address;
	uint32_t monitor_vector_base_address;
	uint32_t interrupt_status;
	uint32_t base_address = (unsigned int)&__exception_table_start__;
	asm volatile (" mcr p15, 0, %0, c12, c0, 0" : "=r" (base_address) : );

	asm volatile (" mrc p15, 0, %0, c12, c0, 0" : "=r" (secure_nonsecure_vector_base_address) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c12, c0, 1" : "=r" (monitor_vector_base_address) : /* no inputs */);
	asm volatile (" mrc p15, 0, %0, c12, c1, 0" : "=r" (interrupt_status) : /* no inputs */);

	printf("C12:\r\n");
	printf("    vector_base_address:  0x%08lX\r\n", secure_nonsecure_vector_base_address);
	printf("    monitor_base_address: 0x%08lX\r\n", monitor_vector_base_address);
	printf("    interrupt_status:     0x%08lX\r\n", interrupt_status);




	printf("Inside Main\r\n");

	printf("sizeof(intc_reg_t) = %u\r\n", sizeof(intc_reg_t));
	printf("sizeof(struct INTC_BITFIELD) = %u\r\n", sizeof(struct INTC_BITFIELD));


	try {
		printf("in throw\r\n");
		throw 20;
	} catch (int e) {
		printf("caught exception %d\r\n", e);
	}


	printf("after throw/catch\r\n");

	printf("TimerReg = %p\n\r", TimerReg);
   	
	struct fp_test tst = {
			func, func, func, func
	};

	unsigned int k;
	unsigned int *ptr = (unsigned int*)&tst;
	for (k=0;k<sizeof(struct fp_test)/4; k++){
		printf("tst[%d]: 0x%08X\r\n", k, ptr[k]);
	}



	var.data[0] = 0;
	var.data[1] = 0;
	var.data[2] = 0;
/*
	printf("All zeros\r\n");
	pdata(&var);

	printf("\r\na=0x1\r\n");
	var.a=1;
	pdata(&var);
	printf("\r\nb=0x7\r\n");
	var.b=7;
	pdata(&var);
	printf("\r\nc=0xf\r\n");
	var.c=15;
	pdata(&var);

	printf("\r\nd=0x00A\r\n");
	var.d=0x00A;
	pdata(&var);
	printf("\r\nd=0x0AF\r\n");
	var.d=0x0AF;
	pdata(&var);
	printf("\r\nd=0xAFF\r\n");
	var.d=0xAFF;
	pdata(&var);

	printf("\r\ne=0x1\r\n");
	var.e=0x1;
	pdata(&var);

	printf("\r\nf=0x7F\r\n");
	var.f=0x7F;
	pdata(&var);

	printf("\r\ng=0xC3\r\n");
	var.g=0xC3;
	pdata(&var);

	printf("\r\nh=0x000A\r\n");
	var.h=0x000A;
	pdata(&var);

	printf("\r\nh=0x00AF\r\n");
	var.h=0x00AF;
	pdata(&var);

	printf("\r\nh=0x0AFF\r\n");
	var.h=0x0AFF;
	pdata(&var);

	printf("\r\nh=0xAFFF\r\n");
	var.h=0xAFFF;
	pdata(&var);

	printf("\r\ni=0xFEDCBA98\r\n");
	var.i=0xFEDCBA98;
	pdata(&var);
*/

	unsigned int cpsr;
	asm volatile (" mrs %0, cpsr" : "=r" (cpsr) : /* no inputs */);
	printf("CPSR=0x%08X\r\n", cpsr);




	vensos::core::interrupt::init_interrupts();

	asm volatile (" mrs %0, cpsr" : "=r" (cpsr) : /* no inputs */);
	printf("CPSR=0x%08X\r\n", cpsr);

	TimerReg->IRQ_EN_bits.TMR2_INT_EN = 1;

	TimerReg->TMR2_INTV_VALUE = 0x1000;
	TimerReg->TMR2_CTRL_bits.EN = 1;

	//while(1);

	int pre = TimerReg->TMR2_CTRL_bits.CLK_PRES;
	int src = TimerReg->TMR2_CTRL_bits.CLK_SRC;
	int en = TimerReg->TMR2_CTRL_bits.EN;
	int mode = TimerReg->TMR2_CTRL_bits.MODE;
	int reload = TimerReg->TMR2_CTRL_bits.RELOAD;
	int interval = TimerReg->TMR2_INTV_VALUE;
	int cur = TimerReg->TMR2_CUR_VALUE;
	int ctrl = TimerReg->TMR2_CTRL;

	printf("pre=%X, src=%X, en=%X, mode=%X, reload=%X, interval=%X, cur=%X, ctrl=%X\r\n",
			pre, src, en, mode, reload, interval, cur, ctrl);


	int cnt = 0;
	while(1) {
		printf("Value = 0x%08X, Flag = 0x%08X\r\n", (unsigned int)TimerReg->TMR2_CUR_VALUE, flag);
		cnt++;
		if(cnt > 30){
			printf("pend=%X\r\n", TimerReg->IRQ_STATUS_bits.TMR2_IRQ_PEND);
			vensos::core::interrupt::print_int_ctrler();
			while (1);
		}
	}

	//vensos::core::interrupt::print_int_ctrler();
	int last_flag = 0;
	while(1) {
		while (last_flag == flag);
		last_flag = flag;
		printf("%d\n\r", last_flag);
	}

    while (1);
    return(0);
}

