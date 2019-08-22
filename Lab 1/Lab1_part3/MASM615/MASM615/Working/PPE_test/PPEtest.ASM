Page	68,132
Title   PPETEST.asm


.286

;******************************************************
;*						      *
;*						      *
;*	  Parallel Port Exerciser		      *
;*						      *
;* This is an example of using dummy subroutines      *
;* to mock test the pc keyboard.  Creates PPET.COM    *
;*						      *
;*						      *
;******************************************************



cseg	segment 'code'
assume	cs:cseg,  ds:cseg,  ss:cseg, es:cseg




        org      100h            ;Leave room for PSP


start:
        nop			 ;Main program
	call clsub   	         ;call clear subroutine
       	call Greet   	         ;call Greet subroutine
nextkey:
        call getkey		 ;call getkey subroutine
        lea dx, keymesg          ;display "You pressed "
	call show   	         ;call display subroutine
        call dispkey             ;call display subroutine to print key pressed
        mov al, [keynum]         ;get ascii key value of key pressed
       	cmp al, 71h              ;test to see if the key is "q"
	jz done                  ;if key is "q" jump to done
	jmp nextkey              ;if not "q" jump back to nextkey
done:
        lea dx, ending 		 ;load dx with the location of mesg2
	call show   	         ;call display subroutine
	mov ah, 4ch
        int 21h

clsub:
        nop			 ;Clear subroutine
	mov      ax,0002         ;BIOS service 0, video mode 2
	int      10h             ;Set video mode and clear screen
	mov      ah,2            ;BIOS service 2
	ret


Greet:
        lea dx, mtitle		 ;load dx with the location of mtitle
	call show   	         ;call display subroutine
	ret


getkey:
        pusha
        mov ah, 00h
        int 16h
        mov [keynum], al
        popa
        ret

dispkey:
        pusha
        mov al, [keynum]
        mov ah, 0eh
        int 10h
        popa
        ret



;************************************
;*     Procedure Show		    *
;*				    *
;* Function: Display ASCII message  *
;*	     terminated with $	    *
;* Inputs:   DX points to message   *
;* Calls:    DOS INT 21 service 09H *
;* Modifys:  flags		    *
;				    *
;************************************

show	proc

	pusha				;Save all registers
	mov	ah,09			;DOS function: string output
	int	21h
	popa				;Restore registers
	ret

show	endp








	org 200h
mtitle	db 13,10, "Parallel Port Exerciser Tester"
        db 13,10, "    [press 'q' to quit]",13,10,"$"

ending	db 13,10, "Ending PPE Tester Program",13,10, "$"
keymesg db 13,10, "You pressed ", "$"
keynum	db  ?
cseg	ends
	end start
