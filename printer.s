	.section	__TEXT,__text,regular,pure_instructions
	.ios_version_min 9, 3
	.syntax unified
	.globl	_main
	.align	1
	.code	16                      @ @main
	.thumb_func	_main
_main:
@ BB#0:
	push	{r7, lr}
	mov	r7, sp
	sub	sp, #16
	movw	r2, :lower16:(L_.str-(LPC0_0+4))
	movt	r2, :upper16:(L_.str-(LPC0_0+4))
LPC0_0:
	add	r2, pc
	movs	r3, #0
	str	r3, [sp, #12]
	str	r0, [sp, #8]
	str	r1, [sp, #4]
	mov	r0, r2
	bl	_printf
	movs	r1, #0
	str	r0, [sp]                @ 4-byte Spill
	mov	r0, r1
	add	sp, #16
	pop	{r7, pc}

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 @ @.str
	.asciz	"Executing Shellcode!"


.subsections_via_symbols
