	Page 58,132
	Title Prog51
;************************
;* *
;* Program 5.1 *
;* *
;************************

cseg segment 'code'
assume cs:cseg, ds:cseg, ss:cseg, es:cseg

	org 100h
start:	mov     ax,0002h        ;BIOS service 0, video mode 2
	int     10h             ;Set video mode and clear screen
	mov     ah,2h           ;BIOS service 2
	mov     dx,0a00h        ;Row 10, column 0
	mov     bh,0h           ;Page 0
	int     10h             ;Position cursor
	mov     ax,0e00h        ;BIOS service 0E, first character 0
again:	int     10h             ;Print character
	inc     al              ;Next
	cmp     al,80h          ;Done?
	jnz     again           ;No: loop again
	mov	ah, 4CH         ;Yes: back to DOS
	int     21h             ;

cseg ends
end start
