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

start: 	
				mov ah,9			;We want to write a string
 				mov dx, offset Title_msg	;Containing the title
				int 21h				;Display the title with new line
 				mov dx, offset Instruct_msg	;We want to write another string with the input instructions
				int 21h				;Display input instructions with new line
				MOV DX, offset input_txt 	;We want to input the count from the user
				MOV AH, 0Ah 			;Using a two byte input string buffer
				INT 21h 			;So we ask the user for the count they want to see
				MOV BX, word ptr [Input_txt+2]	;This count comes in as two ascii characters so we copy these
				SUB BH, 30h			;Then convert both the ones place...
				SUB BL, 30h			;...and the tens place into decimal values
				MOV CL, 8			;Tens place and ones place are currently reversed
				ROR BX, CL			;So rotating them by a byte fixes their order
				MOV CX, 0			;We are now ready to begin counting up to the desired value
				mov ah,9			;Ready INT 21 to write strings for the rest of the program

process_count:			CMP BH, 0			;Find out if the tens place is greater than 0
				JLE have_target			;If its not, we have the count value in BL
				ADD BL, 10			;If it is, BL needs to be increased by 10...
				DEC BH				;And a single value of the tens place removed
				JMP process_count		;Lets now check and see if the tens place is still greater then 0

								;BH is now zero, BL contains our count target so were 
have_target: 			mov dx, offset Count_msg	;ready to display our count as we step through
				int 21h				;Display the count message with space to show the count values
				mov [tens_place], 30h		;Our tens place in memory may have been incremented before, we'll make it ASCII 0
				mov dl, cl			;And copy our count to another location so it isn't tampered with

t_place:			cmp dl, 10			;If our count is less than 10
				JL o_place			;then we have what we need for the ones place
				sub dl, 10			;But if its greater then we need to account for this
				add [tens_place], 1		;By bringing up our ASCII tens place character
				JMP t_place			;Until there is only a single decimal digit left
				
o_place:			mov [ones_place], dl		;What remains in dl is a single decimal digit, lets copy this
				add [ones_place], 30h		;And convert it to ASCII for display to the user
 				mov dx, offset Tens_place	;We can now ready ourselves to display the tens place
				int 21h				;which is followed by no space or newline
 				mov dx, offset Ones_place	;Followed by the ones place
				int 21h				;which will contain a newline
				INC CX				;This completes the process for displaying our current count value, increment this count. 
				CMP CX, BX			;And make sure it's less than our target
				JL have_target			;So we can diaply the next count message and value

done: 				mov ah, 4ch			;But if the count is larger, then we are done
				int 21h				;then we are done

				org 200h

Count_msg 	db "Count",20h,20h,"$"
Input_txt	db 3
Title_msg	db "Andrew Robertson",13,10,36
Instruct_msg	db "Please enter a decimal number in XX format",13,10,36
Tens_place	db 30h,36
Ones_place	db 30h,13,10,36

cseg ends
end start
