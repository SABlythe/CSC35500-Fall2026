	section	.text		;comment
	global	_start
	extern	add2ToRAX

_start:
	mov	rax, 0x123
	call	add2ToRAX
	
	mov	rax, 1
	mov	rbx, 0
	int	0x80
