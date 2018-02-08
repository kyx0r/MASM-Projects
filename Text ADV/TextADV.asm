		include \masm32\include\masm32rt.inc

.data
	   num1 db 0
       msg1 db "What is your name? ",0
       msg2 db "Hello ",0
	   backquote db "'",0
	   frontquote db "'",0
	   space db "   ",0
	   welcome db " Welcome!",0ah,0
		
	   continue db "Do you want to continue?",0ah,0
	   yes db "Yes",0
	   ;yes2 db "Yes",0
	   no db "No",0
.data?
       buffer db 100 dup(?)   ; reserve 100 bytes for input storage
	   choice db 20 dup(?)
.code

spacefunc proc
		push offset space
		call StdOut
		;jmp cont
		ret
		spacefunc endp
	   

	   
RDchar proc
		push 1000 
		;push esi
		;push edi
		mov ecx,6 ;the length of the abc and def strings	
		
		;mov edx, offset choice
		push offset choice
		call StdIn 
		
		cld                                  ;set the direction flag so that EDI and ESI will increase using repe
		mov esi, offset [choice]               ;moves address of abc string into esi
		mov edi, offset [yes]
		;lea esi, offset [choice]               ;moves address of abc string into esi
		;lea edi, offset [yes]
		repe cmpsb     						;#repeat compare [esi] with [edi] until ecx!=0 and current chars in strings match	
		;repz cmpsb
		cmp ecx,0                         ;#test if the above command passed until the end of strings
		
		je strings_are_equal  							;	#if yes then strings are equal
		push offset no 
		call StdOut									;	# here print the message that strings are not equal (i.e. invoke MessageBox)
		call spacefunc
		jmp exit0
		
		
		ret
	RDchar endp
	
strings_are_equal:		
		push offset welcome 
		call StdOut
		
;strings_not_equal:	
		;jmp exit0
			
			
			
			
start:
		 push offset msg1 ; put in to stack the effective add of msg1
		 call StdOut ; call console display API

		 push 1000 ; set the maximum input character
		 
		 push offset buffer ; put in to stack the effective add of input storage
		 call StdIn ; call console input API

		 push offset msg2 ; put in to stack the effective add of msg2
		 call StdOut ; call console display API
		 
		 push offset frontquote
		 call StdOut
		 
		 push offset buffer ; put in to stack the effective add of input storage
		 call StdOut ; call console display API
		 
		 push offset backquote
		 call StdOut
		 
		 call spacefunc
		 
		 push offset continue 
		 call StdOut
		 
		 call spacefunc
		 
		 push offset yes 
		 call StdOut
		 
		 call spacefunc
		 
		 push offset no 
		 call StdOut 
		 
		 call spacefunc
		 
		 call RDchar
		

	   
exit0:
       inkey
       push 0
       call ExitProcess

end start
