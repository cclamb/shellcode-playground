	.section	__TEXT,__text,regular,pure_instructions
	.ios_version_min 9, 3
	.syntax unified
	.globl	_main
	.align	1
	.code	16                      @ @main
	.thumb_func	_main
_main:
@ BB#0:
	sub	sp, #8
	movs	r0, #0
	movs	r1, #5
	str	r0, [sp, #4]
	str	r1, [sp]
	add	sp, #8
	bx	lr


.subsections_via_symbols
