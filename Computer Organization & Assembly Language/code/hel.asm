section .text
	global _start
_start :
	mov edx, len
	mov ecx, msg
	mov ebx, 1
	mov eax, 4
	int 0x80	;to call kernal
	mov eax, 1	; system call (sys_exit)
	int 0x080
section  .data
	msg db  "hello, world!", 10
	len equ $ -msg
