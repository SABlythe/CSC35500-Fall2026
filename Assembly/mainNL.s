	section	.text		;comment
	global	_start
	extern	printNL

_start:
	mov	rax, 0x123
	mov	rbx, 0xff5
	add	rax, rbx
	mov	rcx , 0x74
	div	rcx
	call	printNL
	
	mov	rax, 1
	mov	rbx, 0
	int	0x80
