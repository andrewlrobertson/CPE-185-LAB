.286
cseg	segment 'code'
assume	cs:cseg,  ds:cseg,  ss:cseg, es:cseg
	org 100h

start:	push sp
	call subr1
        mov ah, 4ch
        int 21h

subr1:	push sp
	call subr2
	ret

subr2:	push sp
	pusha
	pop dx
	popa
	ret






cseg	ends
	end start
