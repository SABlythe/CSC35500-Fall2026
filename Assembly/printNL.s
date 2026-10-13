	section	.data
_newline:	db	0x0a


	section	.text		;comment
	global	printNL
	
printNL:

;backup my registers	
	push 	rax
	push	rbx
	push	rcx
	push	rdx
	
;go ahead ant print the newline
	mov	rax, 0x4
	mov	rbx, 0x1
	mov	rcx, _newline
	mov	rdx, 0x1
	int 	0x80

; restore my registers
	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
