	section	.data
__minus:	db	'-'

	
	section	.text
	global	printRAX
	extern	printDigit

printRAX:
	push	rax
	push	rbx
	push	rcx
	push	rdx

	;;  check if number is negative
	cmp	rax, 0
	jge	printPos
	
	;;  if it is negative, print a '-' sign
	push	rax
	mov	rax, 4
	mov	rbx, 1
	mov	rcx, __minus
	mov	rdx, 1
	int	0x80
	pop	rax
	
	;;  and negate the number.
	neg	rax

printPos:	
	mov	rcx, 0		; count of number of digits
doDigit:
	mov	rbx, 0xa
	mov	rdx,0		; div does rdx:rax/rbx
	div	rbx

	;; push	rax		
	;; mov	al, dl
	;; call	printDigit
	;; pop	rax

	push	rdx		; push next digit onto stack
	inc	rcx
	
	cmp	rax, 0
	jne	doDigit

dumpDigits:
	pop	rax		;get next digit off of stack
	dec	rcx
	
	call	printDigit

	cmp	rcx, 0
	jne	dumpDigits

	
	pop 	rdx
	pop	rcx
	pop 	rbx
	pop 	rax

	ret
