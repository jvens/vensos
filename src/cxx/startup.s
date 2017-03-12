.extern __stack
.extern __bss_start__
.extern __bss_end__
.extern __init_array_start
.extern __init_array_end
.extern __main

.section .init
.globl _entry

_entry:
	b _reset

_reset:
	ldr sp, =__stack
	
	;@ enable fpu
	mrc p15, 0, r0, c1, c0, 2
	orr r0,r0,#0x300000 ;@ single precision
	orr r0,r0,#0xc00000 ;@ double precision
	mcr p15, 0, r0, c1, c0, 2
	mov r0,#0x40000000
	fmxr fpexc,r0

	;@ Zero bss section
	ldr r0, =__bss_start__
	ldr r1, =__bss_end__
	mov r2, #0
	
	bss_zero_loop:
		cmp		r0,r1
		it 		lt
		strlt 	r2,[r0], #4
		blt 	bss_zero_loop
		
	;@ call constructors of all global objects
	ldr r0, =__init_array_start
	ldr r1, =__init_array_end
	
	globals_init_loop:
		cmp 	r0,r1
		it 		lt
		ldrlt	r2, [r0], #4
		blxlt	r2
		blt		globals_init_loop
		
	;@ Main function
	bl	main
	
hang:
	b hang
	
.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr

.globl ASMDELAY
ASMDELAY:
    subs r0,r0,#1
    bne ASMDELAY
    bx lr

.globl MIDR
MIDR:
    mrc p15, 0, r0, c0, c0, 0
    bx lr

.globl ID_PFR0
ID_PFR0:
    mrc p15, 0, r0, c0, c1, 0
    bx lr

.globl ID_PFR1
ID_PFR1:
    mrc p15, 0, r0, c0, c1, 1
    bx lr

.globl ID_DFR0
ID_DFR0:
    mrc p15, 0, r0, c0, c1, 2
    bx lr

.globl ID_AFR0
ID_AFR0:
    mrc p15, 0, r0, c0, c1, 3
    bx lr

.globl CPACR
CPACR:
    mrc p15, 0, r0, c1, c0, 2
    bx lr

.globl ID_ISAR0
ID_ISAR0:
    mrc p15, 0, r0, c0, c2, 0
    bx lr


.globl FPSID
FPSID:
    VMRS r0, FPSID
    bx lr

	
