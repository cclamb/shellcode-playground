  .section __TEXT,__text,regular,pure_instructions
  .ios_version_min  5, 0
  .syntax unified
  .globl  _main
  .align  1
  .code   16  @ @main
  .thumb_func _main

_main:
@ BB#0:
  /* syscall exit(int status) */
  mov r0, #0
  mov r7, #1
  swi #0

.subsections_via_symbols
