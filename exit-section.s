/* syscall exit(int status) */
mov r0, #0
mov r7, #1
swi #0
