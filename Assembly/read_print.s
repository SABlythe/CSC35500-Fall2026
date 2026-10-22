	section	.data
printMe:	db	"Hello, World! How are you today, Stephen?", 0xA
cheeky:		db 	0
buffer:		resb 100


	section	.text		;comment
	global	_start


_start:
	mov	rax, 4
	mov 	rbx, 1
	mov	rcx, printMe
	mov	rdx, cheeky - printMe
	int	0x80

	mov	rax, 0x3
	mov	rbx, 0x0
	mov	rcx, buffer
	mov	rdx, 100
	int 	0x80

	mov	rdx, rax	; upon return from int, rax holds # chars
	mov	rax, 4		
	mov 	rbx, 1
	mov	rcx, buffer
	int	0x80

	
	mov	rax, 1
	mov 	rbx, 17
	int	0x80
