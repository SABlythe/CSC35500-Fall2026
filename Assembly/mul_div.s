	section	.text		;comment
	global	_start


_start:
	mov	rdx, 0x01
	mov	rax, 0x1122334455667788
	mov	rcx, 0x1000
	mul	rcx

	mov	rdx, 0		; div uses rdx:rax
	mov	rax, 0x12345
	mov	rcx, 0x10000
	div	rcx

	mov	eax, 1
	mov	ebx, 0
	int 	0x80
