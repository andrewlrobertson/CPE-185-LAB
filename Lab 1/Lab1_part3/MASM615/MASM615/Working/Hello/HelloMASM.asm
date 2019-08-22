	Page 58,132
	Title Lab1ex4
;************************
;*			*
;* MASM Hello		*
;*			*
;************************

cseg segment 'code'
assume cs:cseg, ds:cseg, ss:cseg, es:cseg

	org 100h
start: 	mov ah,9
	mov cx,10
again: 	mov dx, offset Hello
	int 21h
	mov dx, offset msg
	int 21h
	inc byte ptr msg
	loopne again
done: 	mov ah, 4ch
	int 21h

	org 200h
Hello 	db "hello world", 20h, 20h, "$"

msg 	db 30h,13,10, "$"

cseg ends
end start