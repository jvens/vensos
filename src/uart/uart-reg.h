#pragma once

#include "int.h"

#include "../cpu/mmap.h"
using namespace cpu;

namespace Serial{

typedef enum UART_ADDR_ENUM {
	UART0 = 0,//mmap::uart_0,
	UART1 = 1,//mmap::uart_1,
	UART2 = 2,//mmap::uart_2,
	UART3 = 3,//mmap::uart_3
} UartAddress;

typedef struct UART_REG_STRUCT {
	union{
		reg_ro RBR;	///< Receive buffer register
		reg_wo THR;	///< Transmit holding buffer register
		reg_rw DLL;	///< Divisor latch low register
	};
	union{
		reg_rw DLH;	///< Divisor latch high register
		union{
			reg_rw IER;	///< Interrupt enable register
			struct {
				bit_rw 	ERBFI	: 1;
				bit_rw 	ETBEI	: 1;
				bit_rw 	ELSI	: 1;
				bit_rw 	EDSSI	: 1;
				bit_fil			: 3;
				bit_rw	PTIME	: 1;
			}IERbits;
		};
	};
	union{
		union {
			reg_ro IIR;	///< Interrupt identity register
			struct {
				bit_ro	IID		: 4;
				bit_fil			: 2;
				bit_ro	FEFLAG	: 2;
			}IIRbits;
		};
		union {
			reg_wo FCR;	///< FIFO Control register
			struct {
				bit_wo	FIFOE	: 1;
				bit_wo	RFIFOR	: 1;
				bit_wo	XFIFOR	: 1;
				bit_wo	DMAM	: 1;
				bit_wo	TFT		: 2;
				bit_wo	RT		: 2;
			}FCRbits;
		};
	};
	union {
		reg_rw LCR;	///< Line Control register
		struct {
			bit_rw	DLS		: 2;
			bit_rw	STOP	: 1;
			bit_rw	PEN		: 1;
			bit_rw	EPS		: 1;
			bit_fil			: 1;
			bit_rw	BC		: 1;
			bit_rw	DLAB	: 1;
		}LCRbits;
	};
	union {
		reg_rw MCR;	///< Modem control register
		struct {
			bit_rw	DTR		: 1;
			bit_rw	RTS		: 1;
			bit_fil			: 2;
			bit_rw	LOOP	: 1;
			bit_rw	AFCE	: 1;
			bit_rw	SIRE	: 1;
			bit_fil			: 1;
		}MCRbits;
	};
	union {
		reg_ro LSR;	///< Line status register
		struct {
			bit_ro	DR		: 1;
			bit_ro	OE		: 1;
			bit_ro	PE		: 1;
			bit_ro	FE		: 1;
			bit_ro	BI		: 1;
			bit_ro	THRE	: 1;
			bit_ro	TEMT	: 1;
			bit_ro	FIFOERR	: 1;
		}LSRbits;
	};
	union {
		reg_ro MSR;	///< Modem status register
		struct {
			bit_ro	DCTS	: 1;
			bit_ro	DDSR	: 1;
			bit_ro	TERI	: 1;
			bit_ro	DDCD	: 1;
			bit_ro	CTS		: 1;
			bit_ro	DSR		: 1;
			bit_ro	RI		: 1;
			bit_ro	DCD		: 1;
		}MSRbits;
	};
	reg_rw SCH;	///< Scratch register
	union {
		reg_ro USR;	///< Status register
		struct {
			bit_ro	BUSY	: 1;
			bit_ro	TFNF	: 1;
			bit_ro	TFE		: 1;
			bit_ro	RFNE	: 1;
			bit_ro	RFF		: 1;
			bit_fil			: 3;
		}USRbits;
	};
	reg_ro TFL;	///< Transmit FIFO level
	reg_ro RFL;	///< Receive FIFO level
	union {
		reg_rw HALT;	///< Halt TX register
		struct {
			bit_rw	HALT	: 1;
			bit_fil			: 3;
			bit_rw	SIR_TX	: 1;
			bit_rw	SIR_RX	: 1;
			bit_fil			: 2;
		}HALTbits;
	};
}uart_reg_t;
};
