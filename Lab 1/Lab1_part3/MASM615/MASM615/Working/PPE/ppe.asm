Page	58,132
Title	PPE


;*
;* Test program for PPE card
;*


   cseg	segment 'code'
	assume	cs:cseg, ds:cseg, ss:cseg, es:cseg

	ORG 0100h
START:	MOV DX,0378h	;setup output port
	MOV AL,01h	;looking for 1,2,3
	OUT DX,AL	;enable the 1,2,3 row
	MOV DX,0379h	;setup input port
	IN  AL,DX	;get input data
	MOV AH,AL	;save the key data
	CMP AL,3Fh	;Nothing Pressed
	JZ  START
	AND AL,08h	;looking for #1 pressed in bit D3
	JZ  ONE
	MOV AL,AH	;get saved input key data
	AND AL,10h	;looking for #2 pressed in bit D3
	JZ  TWO
	MOV AL,AH	;get saved input key data
	AND AL,20h	;looking for #3 pressed in bit D3
	JZ  THREE
	JMP START

ONE:	MOV BL,01h
	JMP BYE

TWO:	MOV BL,02h
	JMP BYE

THREE:	MOV BL,03h
	JMP BYE

BYE:	mov ah, 4ch
	INT 21

cseg	ends
	end start
