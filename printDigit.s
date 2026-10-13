	section	.data
_dig_buff:
	db	0

	section	.text
	global	printDigit

printDigit:

	; backup used registers
	push	rdx
	push	rax
	push	rcx
	push	rbx

	;;  convert al to its ascii code equivalent
	add	al, '0'

	;; put char in memory buffer
	mov	[_dig_buff], al

	;;  get linux to print buffer
	mov	rax, 4		; 4--> print
	mov	rbx, 1		; 1--> to standard output
	mov	rcx, _dig_buff	; mem location of chars
	mov	rdx, 1		; number of chars to print
	int	0x80

	;; restore the registers
	pop	rbx
	pop	rcx
	pop	rax
	pop	rdx

	
	ret	
