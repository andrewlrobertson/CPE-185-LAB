	Page	43,132
	Title	Menu


	.286

;******************************************************
;*		 Menu Program			      *
;*						      *
;* This is an example of a menu program		      *
;*						      *
;*						      *
;******************************************************



;The following equate statements assign constants to the labels shown.
;This makes the program more readable and will allow global changes to
;the program to be mde more easily.

display_message		equ	09h	;DOS INT 21h function 9 (string output)
video_mode		equ	0002h	;BIOS INT 10h service 0, video mode 2 (80x25)
cr			equ	0dh	;carriage return
lf			equ	0ah	;line feed
get_key 		equ	0	;BIOS INT 16h service 0 (read next keyboard character)
quit			equ	'q'	;Exit by typing q
terminate		equ	4ch	;DOS INT 21h function 4ch (terminate with error code)
write_character 	equ	0eh	;Bios INT 10h service 0eh (write character in TTY mode)


;************************
;*     Stack Segment    *
;************************
sseg	segment  stack
	db	100 dup	(?)		;100 bytes for stack
sseg	ends


;************************
;*   Data Segment	*
;************************
dseg	segment

welcome	db	'This is an example Menu Program '
	db	cr,lf,lf,'$'

instruc db	'Please choose one of the following selections: '
	db	cr,lf
	db	' 1:  Run Program 1'
	db	cr,lf
	db	' 2:  Run Program 2'
	db	cr,lf
	db	' q:  Quit program'
	db	cr,lf
	db	cr,lf,lf,'$'

uchce	db	'Your choice: $'

choice  db 	?	;This location stores the number selected

one_mes	db	'You have gotten to selection one Program '
	db	cr,lf,lf,'$'

two_mes	db	'You have gotten to selection two Program '
	db	cr,lf,lf,'$'



dseg	ends





;************************
;      Code Segment     *
;************************
cseg	segment 'code'
assume	cs:cseg, ss:sseg

start:	mov	ax,dseg 		;Load DS
	mov	ds,ax

;Clear the screen
	call clear_screen

;Display Menu sign-on message
	lea	dx,welcome		;Point DX at sign-on message
	call	show			;Show the message

;Display the program instructions
	lea	dx,instruc		;Point DX at instructions
	call	show			;Show the message

;Get the user's choice
	call get_choice

;Determine what to do based on user's selection
	mov al, ds:[choice]
	cmp al, 31h			;test for choice 1
	jz one
	cmp al, 32h			;test for choice 2
	jz two
	cmp	al,quit 		;Quit?
	jz	dos			;Return to DOS
	jmp start			;Display menu options again

;Execute choice one
one:	call select_one
	jmp start

;Execute choice two
two:	call select_two
	jmp start

;Come here to return to DOS
dos:	mov	ah,terminate		;DOS function: terminate
	int	21h






;************************************
;*     Procedure Clear Screen	    *
;*				    *
;* Function: Clears screen by 	    *
;*	     setting video mode	    *
;* Inputs:   none		    *
;* Calls:    DOS INT 10 service 0,  *
;	     video mode 2 (80x25)   *
;* Modifys:  nothing		    *
;				    *
;************************************

clear_screen	proc

	pusha				;Save all registers
					;Clear the screen by setting the video mode
	mov	ax,video_mode		;BIOS service: set video mode
	int	10h
	popa				;Restore registers
	ret

clear_screen	endp



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
	mov	ah,display_message	;DOS function: string output
	int	21h
	popa				;Restore registers
	ret

show	endp


;************************************
;*     Procedure get_choice	    *
;*				    *
;* Function: Gets Users choice	    *
;*	     terminated with $	    *
;* Inputs:   none		    *
;* Calls:    DOS INT 16 	    *
;* Modifys:  nothing		    *
;				    *
;************************************

get_choice	proc

	pusha				;Save all registers
	lea	dx,uchce		;Point to message to show users selection
	call	show			;Show the message
	mov ah, 0eh			;Display number user selected
	int 10h
	mov ax, 0e0dh			;Send a CR to the screen 
	int 10h
	mov ax, 0e0ah			;Send a LF to the screen 
	int 10h
	mov	ah,get_key		;DOS function: wait for next keypress
	int	16h			;Character to AL
	mov ds:[choice], al			;store number selected
	popa				;Restore registers
	ret

get_choice	endp




;************************************
;*     Procedure select_one	    *
;*				    *
;* Function: excutes selection one  *
;*	        		    *
;* Inputs:   none		    *
;* Calls:    			    *
;	     			    *
;* Modifys:  nothing		    *
;				    *
;************************************

select_one	proc

	pusha				;Save all registers
					;Display slect_one message
	lea	dx,one_mes		;Point DX at sign-on message
	call	show			;Show the message
	popa				;Restore registers
	ret

select_one	endp



;************************************
;*     Procedure select_two	    *
;*				    *
;* Function: excutes selection one  *
;*	        		    *
;* Inputs:   none		    *
;* Calls:    			    *
;	     			    *
;* Modifys:  nothing		    *
;				    *
;************************************

select_two	proc

	pusha				;Save all registers
					;Display slect_two message
	lea	dx,two_mes		;Point DX at sign-on message
	call	show			;Show the message
	popa				;Restore registers
	ret

select_two	endp



cseg	ends
	end	start


