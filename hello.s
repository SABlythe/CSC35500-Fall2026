	section	.data
printMe:	db	"Hello, World! How are you today, Stephen?", 0xA
cheeky:		db 	0


	section	.text		;comment
	global	_start


_start:
	mov	rax, 4
	mov 	rbx, 1
	mov	rcx, printMe
	mov	rdx, cheeky - printMe
	int	0x80
	
	mov	rax, 1
	mov 	rbx, 17
	int	0x80
