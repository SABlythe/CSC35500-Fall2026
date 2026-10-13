	section	.text
	global	_start
	extern	printRAX, printNL

_start:

	mov	rax, -850

printNext:	
	call	printRAX
	call	printNL

	add	rax, 17
	
	cmp	rax, 4028
	jle	printNext
	
	mov	rax, 1
	mov	rbx, 0
	int	0x80
	
