	Page 58, 80
	Title strings_attached

cseg	segment 'code'
	assume cs:cseg, ds:cseg, es:cseg, ss:cseg


	org 100h

start:	mov ah,0
	int 16h
	mov cx,ax
	and cx, 000fh
	mov ah, 0eh
	int 10h
	cld
	mov ax, 0e0dh
	int 10h
	mov ax, 0e0ah
	int 10h
	mov si, offset shopa
	mov di, offset shopb
	repz cmpsb
	jz good
	mov dx, offset notso
	jmp putout

good:	mov dx, offset fine
putout: mov ah,09
	int 21h
	mov ah, 4ch
	int 21h

	org 200h

shopa	db "SHOPPER", 20h, 0dh

shopb	db "SHOPPING",0dh

fine	db "EQUAL",0dh, 0ah, "$"

notso	db "NOT EQUAL", 0dh, 0ah, "$"

cseg	ends
	end start

