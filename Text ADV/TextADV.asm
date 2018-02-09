	include \masm32\include\masm32rt.inc

	include     \masm32\include\winmm.inc
	includelib  \masm32\lib\winmm.lib

	includelib  \masm32\lib\advapi32.lib

	include     \masm32\include\d3d8.inc
	includelib  \masm32\lib\d3d8.lib

	include     \masm32\include\winextra.def
		
		

.data
	   num1 db 0
       msg1 db "What is your name? ",0
       msg2 db "Hello ",0
	   backquote db "'",0
	   frontquote db "'",0
	   space db "   ",0
	   welcome db " Welcome!",0ah,0
	   bye db "Goodbye!",0ah,0
		
	   continue db "Do you want to continue?",0ah,0
	   yes db "Yes",0
	   no db "No",0
	   WinTitleString db 'Text Adventure',0    ; Window title
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
	   

	   
CMPchar proc
		push 1000 
		mov ecx,3 ;the length of the abc and def strings	
		
		cld                                  ;set the direction flag so that EDI and ESI will increase using repe
		mov esi, edx               ;moves address of edx string into esi
		mov edi, offset [yes]
		
		repe cmpsb     						;#repeat compare [esi] with [edi] until ecx!=0 and current chars in strings match	
		
		cmp ecx,0                         ;#test if the above command passed until the end of strings
		
		je strings_are_equal  							;#if yes then strings are equal
		jmp strings_not_equal
		
		
		ret
	CMPchar endp

INPUT proc
		push 10
		push offset choice
		call StdIn 
		mov edx, offset choice
		ret
		INPUT endp
	
strings_are_equal:		
		push offset welcome 
		call StdOut
		jmp exit0
		
strings_not_equal:
		push offset bye
		call StdOut
		jmp exit0
			
			
			
			
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
		 
		 call INPUT
		 call CMPchar
		

	   
exit0:
       inkey
       push 0
       call ExitProcess

end start
