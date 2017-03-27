

.section .exception_table
_exception_table:

	ldr pc, =_reset_vect
	ldr pc, =_undefined_instruction_vect
	ldr pc, =_software_interrupt_vect
	ldr pc, =_prefetch_abort_vect
	ldr pc, =_data_abort_vect
	ldr pc, =_unused_handler_vect
	ldr pc, =_interrupt_vect
	ldr pc, =_fast_interrupt_vect



.section .interrupt_table
_interrupt_table:
	b isr_ExternalNMI
	b isr_Invalid
	b isr_UART1
	b isr_Invalid
	b isr_UART3
	b isr_IR
	b isr_Invalid
	b isr_TWI0
	b isr_TWI1
	b isr_TWI2
	b isr_SPI0
	b isr_SPI1
	b isr_SPI2
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Timer0
	b isr_Timer1
//	b isr_Timer2
	ldr pc, =isr_Timer2
	b isr_Timer3
	b isr_Invalid
	b isr_DMA
	b isr_PIO
	b isr_TouchPanel
	b isr_AudioCodec
	b isr_LRADC
	b isr_SD_MMC_0
	b isr_SD_MMC_1
	b isr_SD_MMC_2
	b isr_Invalid
	b isr_Invalid
	b isr_NAND
	b isr_USB_OTG
	b isr_USB_EHCI
	b isr_USB_OHCI
	b isr_Invalid
	b isr_CSI
	b isr_Invalid
	b isr_LCD_Controller
	b isr_Invalid
	b isr_Invalid
	b isr_DE_FE_DE_BE
	b isr_Invalid
	b isr_PMU
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_VE
	b isr_CE
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_Invalid
	b isr_PLE_PERFMU
	b isr_Timer4
	b isr_Timer5
	b isr_GPU_GP
	b isr_GPU_GPMMU
	b isr_GPU_PP0
	b isr_GPU_PPMMU0
	b isr_GPU_PMU
	b isr_GPU_RSV0
	b isr_GPU_RSV1
	b isr_GPU_RSV2
	b isr_GPU_RSV3
	b isr_GPU_RSV4
	b isr_GPU_RSV5
	b isr_GPU_RSV6
	b isr_Invalid
	b isr_SyncTimer0
	b isr_SyncTimer1











