#pragma once

#define IIF(c) PRIMITIVE_CAT(IIF_, c)
#define IIF_0(t, ...) __VA_ARGS__
#define IIF_1(t, ...) t
#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define COMPL(b) PRIMITIVE_CAT(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0
#define BITAND(x) PRIMITIVE_CAT(BITAND_, x)
#define BITAND_0(y) 0
#define BITAND_1(y) y

#define BITOR(x) PRIMITIVE_CAT(BITOR_, x)
#define BITOR_0(y) y
#define BITOR_1(y) 1

#define CHECK_N(x, n, ...) n
#define CHECK(...) CHECK_N(__VA_ARGS__, 0,)
#define IS_PAREN(x) CHECK(IS_PAREN_PROBE x)
#define IS_PAREN_PROBE(...) PROBE(~)
#define PROBE(x) x, 1,
#define EAT(...)

#define WHILE_INDIRECT() WHILE
#define PRIMITIVE_COMPARE(x, y) IS_PAREN \
( \
COMPARE_ ## x ( COMPARE_ ## y) (())  \
)
#define IS_COMPARABLE(x) IS_PAREN( CAT(COMPARE_, x) (()) )

#define NOT_EQUAL(x, y) \
IIF(BITAND(IS_COMPARABLE(x))(IS_COMPARABLE(y)) ) \
( \
   PRIMITIVE_COMPARE, \
   1 EAT \
)(x, y)
#define EQUAL(x, y) COMPL(NOT_EQUAL(x, y))


#define COMPARE_ExternalNMI(x) x
#define COMPARE_UART1(x) x
#define COMPARE_UART3(x) x
#define COMPARE_IR(x) x
#define COMPARE_TWI0(x) x
#define COMPARE_TWI1(x) x
#define COMPARE_TWI2(x) x
#define COMPARE_SPI0(x) x
#define COMPARE_SPI1(x) x
#define COMPARE_SPI2(x) x
#define COMPARE_Timer0(x) x
#define COMPARE_Timer1(x) x
#define COMPARE_Timer2(x) x
#define COMPARE_Timer3(x) x
#define COMPARE_DMA(x) x
#define COMPARE_PIO(x) x
#define COMPARE_TouchPanel(x) x
#define COMPARE_AudioCodec(x) x
#define COMPARE_LRADC(x) x
#define COMPARE_SD_MMC_0(x) x
#define COMPARE_SD_MMC_1(x) x
#define COMPARE_SD_MMC_2(x) x
#define COMPARE_NAND(x) x
#define COMPARE_USB_OTG(x) x
#define COMPARE_USB_EHCI(x) x
#define COMPARE_USB_OHCI(x) x
#define COMPARE_CSI(x) x
#define COMPARE_LCD_Controller(x) x
#define COMPARE_DE_FE_DE_BE(x) x
#define COMPARE_PMU(x) x
#define COMPARE_VE(x) x
#define COMPARE_CE(x) x
#define COMPARE_PLE_PERFMU(x) x
#define COMPARE_Timer4(x) x
#define COMPARE_Timer5(x) x
#define COMPARE_GPU_GP(x) x
#define COMPARE_GPU_GPMMU(x) x
#define COMPARE_GPU_PP0(x) x
#define COMPARE_GPU_PPMMU0(x) x
#define COMPARE_GPU_PMU(x) x
#define COMPARE_GPU_RSV0(x) x
#define COMPARE_GPU_RSV1(x) x
#define COMPARE_GPU_RSV2(x) x
#define COMPARE_GPU_RSV3(x) x
#define COMPARE_GPU_RSV4(x) x
#define COMPARE_GPU_RSV5(x) x
#define COMPARE_GPU_RSV6(x) x
#define COMPARE_SyncTimer0(x) x
#define COMPARE_SyncTimer1(x) x

#define ISR(vector) IIF(\
						BITOR(EQUAL(vector, ExternalNMI))\
						(BITOR(EQUAL(vector, UART1))\
						(BITOR(EQUAL(vector, UART3))\
						(BITOR(EQUAL(vector, IR))\
						(BITOR(EQUAL(vector, TWI0))\
						(BITOR(EQUAL(vector, TWI1))\
						(BITOR(EQUAL(vector, TWI2))\
						(BITOR(EQUAL(vector, SPI0))\
						(BITOR(EQUAL(vector, SPI1))\
						(BITOR(EQUAL(vector, SPI2))\
						(BITOR(EQUAL(vector, Timer0))\
						(BITOR(EQUAL(vector, Timer1))\
						(BITOR(EQUAL(vector, Timer2))\
						(BITOR(EQUAL(vector, Timer3))\
						(BITOR(EQUAL(vector, DMA))\
						(BITOR(EQUAL(vector, PIO))\
						(BITOR(EQUAL(vector, TouchPanel))\
						(BITOR(EQUAL(vector, AudioCodec))\
						(BITOR(EQUAL(vector, LRADC))\
						(BITOR(EQUAL(vector, SD_MMC_0))\
						(BITOR(EQUAL(vector, SD_MMC_1))\
						(BITOR(EQUAL(vector, SD_MMC_2))\
						(BITOR(EQUAL(vector, NAND))\
						(BITOR(EQUAL(vector, USB_OTG))\
						(BITOR(EQUAL(vector, USB_EHCI))\
						(BITOR(EQUAL(vector, USB_OHCI))\
						(BITOR(EQUAL(vector, CSI))\
						(BITOR(EQUAL(vector, LCD_Controller))\
						(BITOR(EQUAL(vector, DE_FE_DE_BE))\
						(BITOR(EQUAL(vector, PMU))\
						(BITOR(EQUAL(vector, VE))\
						(BITOR(EQUAL(vector, CE))\
						(BITOR(EQUAL(vector, PLE_PERFMU))\
						(BITOR(EQUAL(vector, Timer4))\
						(BITOR(EQUAL(vector, Timer5))\
						(BITOR(EQUAL(vector, GPU_GP))\
						(BITOR(EQUAL(vector, GPU_GPMMU))\
						(BITOR(EQUAL(vector, GPU_PP0))\
						(BITOR(EQUAL(vector, GPU_PPMMU0))\
						(BITOR(EQUAL(vector, GPU_PMU))\
						(BITOR(EQUAL(vector, GPU_RSV0))\
						(BITOR(EQUAL(vector, GPU_RSV1))\
						(BITOR(EQUAL(vector, GPU_RSV2))\
						(BITOR(EQUAL(vector, GPU_RSV3))\
						(BITOR(EQUAL(vector, GPU_RSV4))\
						(BITOR(EQUAL(vector, GPU_RSV5))\
						(BITOR(EQUAL(vector, GPU_RSV6))\
						(BITOR(EQUAL(vector, SyncTimer0))\
						(BITOR(EQUAL(vector, SyncTimer1))\
						)))))))))))))))))))))))))))))))))))))))))))))))))(\
								extern "C" void CAT(isr_, vector)(void) __attribute__((interrupt ("IRQ"))); extern "C" void CAT(isr_, vector)(void), \
								"Invalid ISR Vector Name"  \
						)


#define FIQ_ISR(vector) IIF(\
						BITOR(EQUAL(vector, ExternalNMI))\
						(BITOR(EQUAL(vector, UART1))\
						(BITOR(EQUAL(vector, UART3))\
						(BITOR(EQUAL(vector, IR))\
						(BITOR(EQUAL(vector, TWI0))\
						(BITOR(EQUAL(vector, TWI1))\
						(BITOR(EQUAL(vector, TWI2))\
						(BITOR(EQUAL(vector, SPI0))\
						(BITOR(EQUAL(vector, SPI1))\
						(BITOR(EQUAL(vector, SPI2))\
						(BITOR(EQUAL(vector, Timer0))\
						(BITOR(EQUAL(vector, Timer1))\
						(BITOR(EQUAL(vector, Timer2))\
						(BITOR(EQUAL(vector, Timer3))\
						(BITOR(EQUAL(vector, DMA))\
						(BITOR(EQUAL(vector, PIO))\
						(BITOR(EQUAL(vector, TouchPanel))\
						(BITOR(EQUAL(vector, AudioCodec))\
						(BITOR(EQUAL(vector, LRADC))\
						(BITOR(EQUAL(vector, SD_MMC_0))\
						(BITOR(EQUAL(vector, SD_MMC_1))\
						(BITOR(EQUAL(vector, SD_MMC_2))\
						(BITOR(EQUAL(vector, NAND))\
						(BITOR(EQUAL(vector, USB_OTG))\
						(BITOR(EQUAL(vector, USB_EHCI))\
						(BITOR(EQUAL(vector, USB_OHCI))\
						(BITOR(EQUAL(vector, CSI))\
						(BITOR(EQUAL(vector, LCD_Controller))\
						(BITOR(EQUAL(vector, DE_FE_DE_BE))\
						(BITOR(EQUAL(vector, PMU))\
						(BITOR(EQUAL(vector, VE))\
						(BITOR(EQUAL(vector, CE))\
						(BITOR(EQUAL(vector, PLE_PERFMU))\
						(BITOR(EQUAL(vector, Timer4))\
						(BITOR(EQUAL(vector, Timer5))\
						(BITOR(EQUAL(vector, GPU_GP))\
						(BITOR(EQUAL(vector, GPU_GPMMU))\
						(BITOR(EQUAL(vector, GPU_PP0))\
						(BITOR(EQUAL(vector, GPU_PPMMU0))\
						(BITOR(EQUAL(vector, GPU_PMU))\
						(BITOR(EQUAL(vector, GPU_RSV0))\
						(BITOR(EQUAL(vector, GPU_RSV1))\
						(BITOR(EQUAL(vector, GPU_RSV2))\
						(BITOR(EQUAL(vector, GPU_RSV3))\
						(BITOR(EQUAL(vector, GPU_RSV4))\
						(BITOR(EQUAL(vector, GPU_RSV5))\
						(BITOR(EQUAL(vector, GPU_RSV6))\
						(BITOR(EQUAL(vector, SyncTimer0))\
						(BITOR(EQUAL(vector, SyncTimer1))\
						)))))))))))))))))))))))))))))))))))))))))))))))))(\
								extern "C" void CAT(isr_, vector)(void) __attribute__((interrupt ("FIQ"))); extern "C" void CAT(isr_, vector)(void), \
								"Invalid ISR Vector Name"  \
						)

