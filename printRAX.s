	section	.text
	global	printRAX
	extern	printDigit

printRAX:
	push	rax
	push	rbx
	push	rdx

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
	pop 	rbx
	pop 	rax

	ret
