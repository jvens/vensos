#pragma once

#include "int.h"

namespace vensos {
namespace core {
namespace interrupt{

void print_int_ctrler (void);
void init_interrupts(void);

	//const void * BASE_ADDRESS = 0x01c20400;

	enum class vector{
		/// External Non-Mask Interrpt.
		/// Power module battery/VDD/VDDIO/VDD18/VDD25
		/// brownout detect.
		ExternalNMI = 	0x0000,
		/// UART 1 Interrupt.
		UART1		=	0x0008,
		/// UART 3 Interrupt.
		UART3		=	0x0010,
		/// IR 0 Interrupt.
		IR0			=	0x0014,
		/// Two Wire Interface 0 Interrupt.
		TWI0		=	0x001C,
		/// Two Wire Interface 1 Interrupt.
		TWI1		=	0x0020,
		/// Two Wire Interface 2 Interrupt.
		TWI2		=	0x0024,
		/// SPI 0 Interrupt.
		SPI0		=	0x0028,
		/// SPI 1 Interrupt.
		SPI1		=	0x002C,
		/// SPI 2 Interrupt.
		SPI2		=	0x0030,
		/// Timer 0 Interrupt.
		Timer0		=	0x0058,
		/// Timer 1 Interrupt.
		Timer1		=	0x005C,
		/// Timer 2 Interrupt.
		/// Shared with vector::Alarm and vector::WatchDog.
		Timer2		=	0x0060,
		/// Alarm Interrupt.
		/// Shared with vector::Timer2 and vector::WatchDog.
		Alarm		=	0x0060,
		/// Watchdog Timer Interrupt.
		/// Shared with vector::Timer2 and vector::Alarm.
		WatchDog	=	0x0060,
		/// Timer 3 Interrupt.
		Timer3		=	0x0064,
		DMA			=	0x006C,
		PIO			=	0x0070,
		TouchPanel	=	0x0074,
		AudioCodec	=	0x0078,
		LRADC		=	0x007C,
		SD_MMC0		=	0x0080,
		SD_MMC1		=	0x0084,
		SD_MMC2		=	0x0088,
		NAND		=	0x0094,
		USB_OTG		=	0x0098,
		USB_EHCI	=	0x009C,
		USB_OHCI	=	0x00A0,
		CSI			=	0x00A8,
		LCD_Ctrler	=	0x00B0,
		DE_FE_DE_BE	=	0x00BC,
		PMU			=	0x00C4,
		VE			=	0x00D4,
		CE			=	0x00D8,
		PLE			=	0x0108,
		PERFMU		=	0x0108,
		Timer4		=	0x010C,
		Timer5		=	0x0110,
		GPU_GP		=	0x0114,
		GPU_GPMMU	=	0x0118,
		GPU_PPO		=	0x011C,
		GPU_PPMMU0	=	0x0120,
		GPU_PMU		=	0x0124,
		GPU_RSV0	=	0x0128,
		GPU_RSV1	=	0x012C,
		GPU_RSV2	=	0x0130,
		GPU_RSV3	=	0x0134,
		GPU_RSV4	=	0x0138,
		GPU_RSV5	=	0x013C,
		GPU_RSV6	=	0x0140,
		SyncTimer0	=	0x0148,
		SyncTimer1	=	0x014C
	};


	struct __attribute__((packed)) INTC_BITFIELD {
		bit_rw	ExternalNMI		: 1;// 0
		bit_fil					: 1;// 1
		bit_rw	UART1			: 1;// 2
		bit_fil					: 1;// 3
		bit_rw	UART3			: 1;// 4
		bit_rw	IR				: 1;// 5
		bit_fil					: 1;// 6
		bit_rw	TWI0			: 1;// 7
		bit_rw	TWI1			: 1;// 8
		bit_rw	TWI2			: 1;// 9
		bit_rw	SPI0			: 1;// 10
		bit_rw	SPI1			: 1;// 11
		bit_rw	SPI2			: 1;// 12
		bit_fil					: 9;// 13-21
		bit_rw	Timer0			: 1;// 22
		bit_rw	Timer1			: 1;// 23
		//union {
			bit_rw	Timer2		: 1;// 24
		//	bit_rw	Alarm		: 1;// 24
		//	bit_rw	WDOG		: 1;// 24
		//};
		bit_rw	Timer3			: 1;// 25
		bit_fil					: 1;// 26
		bit_rw	DMA				: 1;// 27
		bit_rw	PIO				: 1;// 28
		bit_rw	TouchPanel		: 1;// 29
		bit_rw	AudioCodec		: 1;// 30
		bit_rw	LRADC			: 1;// 31
		bit_rw	SD_MMC_0		: 1;// 32
		bit_rw	SD_MMC_1		: 1;// 33
		bit_rw	SD_MMC_2		: 1;// 34
		bit_fil					: 2;// 35-36
		bit_rw	NAND			: 1;// 37
		bit_rw	USB_OTG			: 1;// 38
		bit_rw	USB_EHCI		: 1;// 39
		bit_rw	USB_OHCI		: 1;// 40
		bit_fil					: 1;// 41
		bit_rw	CSI				: 1;// 42
		bit_fil					: 1;// 43
		bit_rw	LcdController	: 1;// 44
		bit_fil					: 2;// 45-46
		//union {
			bit_rw	DE_FE		: 1;// 47
		//	bit_rw	DE_BE		: 1;// 47
		//};
		bit_fil					: 1;// 48
		bit_rw	PMU				: 1;// 49
		bit_fil					: 3;// 50-52
		bit_rw	VE				: 1;// 53
		bit_rw	CE				: 1;// 54
		bit_fil					: 9;// 55-63
		bit_fil					: 2;// 64-65
		//union {
			bit_rw	PLE			: 1;// 66
		//	bit_rw	PERFMU		: 1;// 66
		//};
		bit_rw	Timer4			: 1;// 67
		bit_rw	Timer5			: 1;// 68
		//struct {
			bit_rw	GP			: 1;// 69
			bit_rw	GPMMU		: 1;// 70
			bit_rw	PP0			: 1;// 71
			bit_rw	PPMMU0		: 1;// 72
			bit_rw	GPU_PMU			: 1;// 73
			bit_rw	RSV0		: 1;// 74
			bit_rw	RSV1		: 1;// 75
			bit_rw	RSV2		: 1;// 76
			bit_rw	RSV3		: 1;// 77
			bit_rw	RSV4		: 1;// 78
			bit_rw	RSV5		: 1;// 79
			bit_rw	RSV6		: 1;// 80
		//}GPU;
		bit_fil					: 1;// 81
		bit_rw	SyncTimer0		: 1;// 82
		bit_rw	SyncTimer1		: 1;// 83
		bit_fil					: 12;// 84-95
	};

	typedef struct INTC_REG_STRUCT {
		reg_ro	VECTOR;
		reg_rw	BASE_ADDR;
		union {
			reg_rw	PROTECT;
			struct {
				/// Enables or disables protected register access.
				///   - 0: Disable protection mode
				///   - 1: Enable protection mode
				/// If enabled, only privileged mode access can access the
				/// registers.  This register can only be accessed in privileged mode.
				bit_rw	EN		: 1;
				bit_fil			: 31;
			}PROTECT_bits;
		};
		union {
			reg_rw	NMII_CTRL;
			struct {
				/// External NMI Interrupt Source Type.
				///   - 00: Low level sensitive
				///   - 01: Negative edge triggered
				///   - 10: High level sensitive
				///   - 11: Positive edge triggered
				bit_rw	NMI_SRC_TYPE	: 2;
				bit_fil					: 30;
			}NMII_CTRL_bits;
		};
		union {
			struct {
				reg_ro	IRQ_PEND_0;
				reg_ro	IRQ_PEND_1;
				reg_ro	IRQ_PEND_2;
			};
			reg_ro	IRQ_PEND[3];
			struct INTC_BITFIELD IRQ_PEND_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	FIQ_PEND_0;
				reg_ro	FIQ_PEND_1;
				reg_ro	FIQ_PEND_2;
			};
			reg_ro	FIQ_PEND[3];
			struct INTC_BITFIELD FIQ_PEND_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	SEL_0;
				reg_ro	SEL_1;
				reg_ro	SEL_2;
			};
			reg_ro	SEL[3];
			struct INTC_BITFIELD SEL_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	EN_0;
				reg_ro	EN_1;
				reg_ro	EN_2;
			};
			reg_ro	EN[3];
			struct INTC_BITFIELD EN_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	MASK_0;
				reg_ro	MASK_1;
				reg_ro	MASK_2;
			};
			reg_ro	MASK[3];
			struct INTC_BITFIELD MASK_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	RESP_0;
				reg_ro	RESP_1;
				reg_ro	RESP_2;
			};
			reg_ro	RESP[3];
			struct INTC_BITFIELD RESP_bits;
		};
		bit_fil	: 32;
		union {
			struct {
				reg_ro	FORCE_0;
				reg_ro	FORCE_1;
				reg_ro	FORCE_2;
			};
			reg_ro	FORCE[3];
			struct INTC_BITFIELD FORCE_bits;
		};
		bit_fil	: 32;
		union {
			struct{
				reg_rw	PRIO_0;
				reg_rw	PRIO_1;
				reg_rw	PRIO_2;
				reg_rw	PRIO_3;
				reg_rw	PRIO_4;
				reg_rw	PRIO_5;
			};
			reg_rw	PRIO[6];
			struct __attribute__((packed)){
				bit_fil					: 2;// 0 // start 0
				bit_fil					: 2;// 1
				bit_rw	UART1			: 2;// 2
				bit_fil					: 2;// 3
				bit_rw	UART3			: 2;// 4
				bit_rw	IR				: 2;// 5
				bit_fil					: 2;// 6
				bit_rw	TWI0			: 2;// 7
				bit_rw	TWI1			: 2;// 8
				bit_rw	TWI2			: 2;// 9
				bit_rw	SPI0			: 2;// 10
				bit_rw	SPI1			: 2;// 11
				bit_rw	SPI2			: 2;// 12
				bit_fil					: 6;// 13-15
				bit_fil					: 12;// 16-21 // start 1
				bit_rw	Timer0			: 2;// 22
				bit_rw	Timer1			: 2;// 23
			//	union {
					bit_rw	Timer2		: 2;// 24
			//		bit_rw	Alarm		: 2;
			//		bit_rw	WDOG		: 2;
			//	};
				bit_rw	Timer3			: 2;// 25
				bit_fil					: 2;// 26
				bit_rw	DMA				: 2;// 27
				bit_rw	PIO				: 2;// 28
				bit_rw	TouchPanel		: 2;// 29
				bit_rw	AudioCodec		: 2;// 30
				bit_rw	LRADC			: 2;// 31
				bit_rw	SD_MMC_0		: 2;// 32 // start 2
				bit_rw	SD_MMC_1		: 2;// 33
				bit_rw	SD_MMC_2		: 2;// 34
				bit_fil					: 4;// 35-36
				bit_rw	NAND			: 2;// 37
				bit_rw	USB_OTG			: 2;// 38
				bit_rw	USB_EHCI		: 2;// 39
				bit_rw	USB_OHCI		: 2;// 40
				bit_fil					: 2;// 41
				bit_rw	CSI				: 2;// 42
				bit_fil					: 2;// 43
				bit_rw	LcdController	: 2;// 44
				bit_fil					: 4;// 45-46
			//	union {
					bit_rw	DE_FE		: 2;// 47
			//		bit_rw	DE_BE		: 2;
			//	};
				bit_fil					: 2;// 48 // start 3
				bit_rw	PMU				: 2;// 49
				bit_fil					: 6;// 50-52
				bit_rw	VE				: 2;// 53
				bit_rw	CE				: 2;// 54
				bit_fil					: 18;// 55-63
				bit_fil					: 4; // 64-65 // start 4
			//	union {
					bit_rw	PLE			: 2;// 66
			//		bit_rw	PERFMU		: 2;
			//	};
				bit_rw	Timer4			: 2;// 67
				bit_rw	Timer5			: 2;// 68
				//struct {
					bit_rw	GP			: 2;// 69
					bit_rw	GPMMU		: 2;// 70
					bit_rw	PP0			: 2;// 71
					bit_rw	PPMMU0		: 2;// 72
					bit_rw	GPU_PMU			: 2;// 73
					bit_rw	RSV0		: 2;// 74
					bit_rw	RSV1		: 2;// 75
					bit_rw	RSV2		: 2;// 76
					bit_rw	RSV3		: 2;// 77
					bit_rw	RSV4		: 2;// 78
					bit_rw	RSV5		: 2;// 79
					bit_rw	RSV6		: 2;// 80 // start 5
				//}GPU;
				bit_fil					: 2;// 81
				bit_rw	SyncTimer0		: 2;// 82
				bit_rw	SyncTimer1		: 2;// 83
				bit_fil					: 24;// 84-95
			}PRIO_bits;
		};
	}intc_reg_t;

}
}
}
