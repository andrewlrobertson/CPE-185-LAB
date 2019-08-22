Page 58,132
Title MASMLab
;************************
;* *
;* MASM Hello *
;* *
;************************

cseg segment 'code'
assume cs:cseg, ds:cseg, ss:cseg, es:cseg

		org 100h

start:		mov [Num_msg],30h		;Ready byte pointer at ASCII '0'
		mov cx,10			;Only wish to display 10 characters
		mov ah,9			;Ready INT 21 to write string
 		mov dx, offset Title_msg	;Ready title adress for INT 21
		int 21h				;Display "Andrew Robertson" with new line

again: 		mov dx, offset Hello		;Ready string adress for INT 21
		int 21h				;Display "Hello World" with space and no new line
		mov dx, offset Num_msg		;Ready new string adress
		int 21h				;Display again, this time with ASCII character and new line
		inc byte ptr Num_msg		;Set the ASCII designation to the next chaacter
		loopne again			;Continue to display characters until counter is zero

done: 		mov ah, 4ch			;Ready to end program
		int 21h				;End program

		org 200h

Hello 		db "Hello World", 20h, 20h, "$"
Num_msg 	db 30h,13,10, 36
Title_msg	db "Andrew Robertson", 13, 10, 36 

cseg ends
end start