section .data
	msg db "Hello, World", 10	; the string followed by a new line
	len equ $ - msg			; length of the string

section .text
	global main

main:
	mov rax, 1		; syscall number for write
	mov rdi, 1		; file descriptor 1 = stdout
	mov rsi, msg		; address of the string
	mov rdx, len		; number of bytes to write
	syscall			; call the kernel

	mov rax, 0		; return value 0
	ret			; return from main
