
#include "int.h"


namespace vensos {
namespace timer {

struct REGISTERS {
	// offset 0
	union {
		reg_rw	IRQ_EN;
		struct {
			bit_rw	TMR0_INT_EN		: 1;
			bit_rw	TMR1_INT_EN		: 1;
			bit_rw	TMR2_INT_EN		: 1;
			bit_rw	TMR3_INT_EN		: 1;
			bit_rw	TMR4_INT_EN		: 1;
			bit_rw	TMR5_INT_EN		: 1;
			bit_fil					: 2;
			bit_rw	WDOG_INT_EN		: 1;
			bit_fil					: 23;
		}IRQ_EN_bits;
	};
	// offset 4
	union {
		reg_rw	IRQ_STATUS;
		struct {
			bit_rw	TMR0_IRQ_PEND	: 1;
			bit_rw	TMR1_IRQ_PEND	: 1;
			bit_rw	TMR2_IRQ_PEND	: 1;
			bit_rw	TMR3_IRQ_PEND	: 1;
			bit_rw	TMR4_IRQ_PEND	: 1;
			bit_rw	TMR5_IRQ_PEND	: 1;
			bit_fil					: 2;
			bit_rw	WDOG_IRQ_PEND	: 1;
			bit_fil					: 23;
		}IRQ_STATUS_bits;
	};
	// offset 8
	bit_fil : 32;
	// offset C
	bit_fil : 32;
	// offset 10
	union {
		reg_rw	TMR0_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RELOAD		: 1;
			bit_rw	CLK_SRC		: 2;
			bit_rw	CLK_PRES	: 2;
			bit_rw	MODE		: 1;
			bit_fil				: 24;
		} TMR0_CTRL_bits;
	};
	// offset 14
	reg_rw	TMR0_INTV_VALUE;
	// offset 18
	reg_rw	TMR0_CUR_VALUE;
	// offset 1C
	bit_fil	: 32;
	// offset 20
	union {
		reg_rw	TMR1_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RELOAD		: 1;
			bit_rw	CLK_SRC		: 2;
			bit_rw	CLK_PRES	: 2;
			bit_rw	MODE		: 1;
			bit_fil				: 24;
		} TMR1_CTRL_bits;
	};
	// offset 24
	reg_rw	TMR1_INTV_VALUE;
	// offset 28
	reg_rw	TMR1_CUR_VALUE;
	// offset 2C
	bit_fil	: 32;
	// offset 30
	union {
		reg_rw	TMR2_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RELOAD		: 1;
			bit_rw	CLK_SRC		: 2;
			bit_rw	CLK_PRES	: 2;
			bit_rw	MODE		: 1;
			bit_fil				: 24;
		} TMR2_CTRL_bits;
	};
	// offset 34
	reg_rw	TMR2_INTV_VALUE;
	// offset 38
	reg_rw	TMR2_CUR_VALUE;
	// offset 3C
	bit_fil	: 32;
	// offset 40
	union {
		reg_rw	TMR3_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_fil				: 1;
			bit_rw	CLK_PRES	: 2;
			bit_rw	CLK_MODE	: 1;
			bit_fil				: 2;
			bit_rw	CLK_SRC		: 1;
			bit_fil				: 24;
		} TMR3_CTRL_bits;
	};
	// offset 44
	reg_rw	TMR3_INTV_VALUE;
	// offset 48
	bit_fil : 32;
	// offset 4C
	bit_fil	: 32;
	// offset 50
	union {
		reg_rw	TMR4_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RELOAD		: 1;
			bit_rw	CLK_SRC		: 2;
			bit_rw	CLK_PRES	: 2;
			bit_rw	MODE		: 1;
			bit_fil				: 24;
		} TMR4_CTRL_bits;
	};
	// offset 54
	reg_rw	TMR4_INTV_VALUE;
	// offset 58
	reg_rw	TMR4_CUR_VALUE;
	// offset 5C
	bit_fil	: 32;
	// offset 60
	union {
		reg_rw	TMR5_CTRL;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RELOAD		: 1;
			bit_rw	CLK_SRC		: 2;
			bit_rw	CLK_PRES	: 2;
			bit_rw	MODE		: 1;
			bit_fil				: 24;
		} TMR6_CTRL_bits;
	};
	// offset 64
	reg_rw	TMR5_INTV_VALUE;
	// offset 68
	reg_rw	TMR5_CUR_VALUE;
	// offset 6C
	bit_fil	: 32;
	// offset 70
	bit_fil : 32;
	// offset 74
	bit_fil	: 32;
	// offset 7c
	bit_fil : 32;
	// offset 80
	union {
		reg_rw	AVS_CNT_CTL;
		struct {
			bit_rw	AVS_CNT0_EN	: 1;
			bit_rw	AVS_CNT1_EN	: 1;
			bit_fil				: 6;
			bit_rw	AVS_CNT0_PS	: 1;
			bit_ro	AVS_CNT1_PS	: 1;
		}AVS_CNT_CTL_bits;
	};
	// offset 84
	reg_rw	AVS_CNT0;
	// offset 88
	reg_rw	AVS_CNT1;
	// offset 8C
	union {
		reg_rw	AVS_CNT_DIVISOR;
		struct {
			bit_rw	AVS_CNT0_D	: 12;
			bit_fil				: 4;
			bit_rw	AVS_CNT1_D	: 12;
			bit_fil				: 4;
		}AVS_CNT_DIVISOR_bits;
	};
	// offset 90
	union {
		reg_rw	WDOG_CTRL;
		struct {
			bit_rw	WDOG_RESTART	: 1;
			bit_rw	KEY_FIELD	: 12;
			bit_fil				: 19;
		}WDOG_CTRL_bits;
	};
	// offset 94
	union {
		reg_rw	WDOG_MODE;
		struct {
			bit_rw	EN			: 1;
			bit_rw	RST_EN		: 1;
			bit_fil				: 1;
			bit_rw	INTV_VALUE	: 4;
			bit_fil				: 24;
			bit_rw	TEST_MODE	: 1;
		}WDOG_MODE_bits;
	};
	// offset 98
	bit_fil : 32;
	// offset 9C
	bit_fil : 32;
	// offset A0
	union {
		reg_rw	COUNTER64_CTRL;
		struct {
			bit_rw	CLR_EN		: 1;
			bit_rw	RLATCH_EN	: 1;
			bit_rw	CLK_SRC_SEL	: 1;
			bit_fil				: 29;
		}COUNTER64_CTRL_bits;
	};
	// offset A4
	reg_rw	COUNTER64_LOW;
	// offset A8
	reg_rw	COUNTER64_HIGH;
	// offset AC - 138
	int fil[(0x013C-0x00AC)/4];
	// offset 13C
	union {
		reg_rw	CPU_CFG;
		struct {
			bit_rw	L2_INVALID_RST_EN	: 1;
			bit_rw	L1_INVALID_RST_EN	: 1;
			bit_fil						: 30;
		}CPU_CFG_bits;
	};
};

}
}
