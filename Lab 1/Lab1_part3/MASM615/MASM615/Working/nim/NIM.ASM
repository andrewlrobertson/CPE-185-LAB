	Page	43,132
	Title	NIM


	.286

;******************************************************
;*		  The Game of NIM		      *
;*						      *
;* The game of NIM is played with 15 "sticks."  When  *
;* it is your turn, you may pick 1, 2, or 3 sticks.   *
;* The player to pick up the last stick wins.	      *
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
delay			equ	50	;50 x 65,536 = 3.3s
BIOS_Wait		equ	86h	;Bios INT 15h service 86h (wait for time delay)
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

sticks	db	?	;This location stores the number of sticks in the pile


nim	db	'NIM - A Game of Skill'
	db	cr,lf,lf,'$'

instruc db	'I have 15 sticks.  You may pick'
	db	' 1, 2, or 3 sticks.  Then I will'
	db	' pick.'
	db	cr,lf
	db	'You win if you pick up the last'
	db	' 1, 2 or 3 sticks.  Type q to quit at any time.'
	db	cr,lf,lf,'$'

uchce	db	'Your choice: $'

lost	db	cr,lf
	db	'YOU WIN!$'

won	db	cr,lf
	db	'I WIN!$'

update	db	cr,lf,lf
	db	'There are now $'

up_end	db	' sticks remaining.'
	db	cr,lf,'$'

mychce	db	'My choice is: $'

;This is the table of choices for the computer
choices db	0,1,2,3,1
	db	1,2,3,1,1
	db	1,1,1,1,2

dseg	ends





;************************
;      Code Segment     *
;************************
cseg	segment 'code'
assume	cs:cseg, ss:sseg

start:	mov	ax,dseg 		;Load DS
	mov	ds,ax

;Clear the screen by setting the video mode
	mov	ax,video_mode		;BIOS service: set video mode
	int	10h

;Show NIM sign-on message
	lea	dx,nim			;Point DX at sign-on message
	call	show			;Show the message

;Set number of sticks to 15
	mov	ds:[sticks],15

;Display the program instructions
	lea	dx,instruc		;Point DX at instructions
	call	show			;Show the message

;Display the number of sticks remaining in the pile
Turn:	call	process

;Get the user's choice
	lea	dx,uchce		;Point to message
	call	show			;Show the message

	mov	ah,get_key		;DOS function: wait for next keypress
	int	16h			;Character to AL

	cmp	al,quit 		;Quit?
	jz	dos			;Return to DOS

	call	cout			;Else display character

;Update the stick counter
	sub	al,30h			;Remove ASCII bias
	sub	ds:[sticks],al		;Adjust counter
	jz	uwin			;If 0, user wins
	call	process 		;Show the new count

;Look up the computer's choice
	lea	dx,mychce		;Point to message
	call	show			;Show the message
	call	think_time		;Time to "think"
	lea	bx,choices		;Point to base of choice table
	mov	al,ds:[sticks]		;Get current number of sticks
	xlat				;Use this as index into table
	mov	bl,al			;Save in BL
	add	al,30h			;Add ASCII bias
	call	cout			;Display choice

;Update the stick counter and check to see if computer wins
	call	think_time		;More think time
	sub	ds:[sticks],bl		;Adjust counter
	jz	iwin			;If 0, computer wins
	jmp	turn			;Else next turn

;Come here to process the winner and start over
uwin:	lea	dx,lost 		;Point to message
	call	show			;Show the message
	jmp	skip

iwin:	lea	dx,won
	call	show

skip:	mov	ah,get_key		;Any key restarts game
	int	16h
	jmp	start

;Come here to return to DOS
dos:	mov	ah,terminate		;DOS function: terminate
	int	21h



;***************************************
;*	Procedure Think_Time	       *
;*				       *
;* Function: Create time delay	       *
;* Inputs:   nothing		       *
;* Calls:    BIOS INT 15H service 86H  *
;* Modifys:  flags		       *
;***************************************

think_time	proc

;Adjust delay equate for desired time interval
	pusha				;Save all registers
	mov	dx,0			;Time delay in CX:DX (microseconds)
	mov	cx,delay
	mov	ah,bios_wait
	int	15h			;Do time delay
	popa				;Restore registers
	ret

think_time	endp


;**************************************
;*	 Procedure Process	      *
;*				      *
;* Function: Display number of sticks *
;*	     remaining in the pile.   *
;* Inputs:   Counter in [sticks]      *
;* Calls:    SHOW and COUT	      *
;* Modifys:  flags		      *
;**************************************

process proc

	pusha				;Save all registers

;Print the update message
	lea	dx,update		;Point DX at message
	call	show			;Show message

;Display the number of sticks remaining
	mov	bl,ds:[sticks]		;Copy stick counter to BL
	cmp	bl,0ah			;Fewer than 10 sticks?
	jb	units			;Yes:
	mov	al,31h			;No: So first digit is ASCII '1'
	call	cout			;Display 1
	sub	bl,10			;Get units digit
units:	add	bl,30h			;Add ASCII bias
	mov	al,bl			;COUT wants character in AL
	call	cout			;Display units

	lea	dx,up_end		;Point DX to end of update message
	call	show			;Show message

	popa				;Restore registers
	ret

process endp



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



;**************************************
;*    Procedure COUT		      *
;*				      *
;* Function: Write one character at   *
;*	     current cursor position. *
;* Inputs: character in AL	      *
;* Calls: BIOS INT 10H service 0EH    *
;* Modifys: flags		      *
;**************************************

cout	proc

	pusha				;Save all registers
	mov	ah,write_character	;BIOS service: write character in TTY mode
	int	10h
	popa				;Restore registers
	ret

cout	endp


cseg	ends
	end	start
