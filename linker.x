MEMORY
{
	DRAM (rwx) : ORIGIN = 0x40000000, LENGTH = 0x80000000
}

ENTRY(_entry)

SECTIONS {
	.start : {
		KEEP(*(.init))
		KEEP(*(.fini))
	} > DRAM = 0
	
	.text : {
		*(.text)
	} > DRAM
	
	.data : {
		*(.data)
	} > DRAM
	
	.bss : {
		__bss_start__ = .;
		*(.bss)
		*(.bss.*)
		__bss_end__ = .;
	} > DRAM
	
	.init.array : {
		__init_array_start = .;
		*(.init_array)
		*(.init_array.*)
		__init_array_end = .;
	} > DRAM
	
	/* .ARM.exidx is required for exception handling */
	.ARM.exidx : {
		__exidx_start = .;
		*(.ARM.exidx* .gnu.linkonce.armexidx.*)
		__exidx_end = .;
	} > DRAM
	
	/* todo heap */
	__stack = ORIGIN(DRAM) + LENGTH(DRAM);
}
	
	
	
