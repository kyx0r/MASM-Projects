jumpIfEqual PROC var1:DWORD, var2:DWORD, jmpAddress:DWORD
    mov eax,var1
    cmp eax,var2
    jne skip
    pop eax
    push jmpAddress
    skip:
    ret
jumpIfEqual ENDP

....

push OFFSET jumpToHere
mov eax, 5
push eax
push eax
call jumpIfEqual





abc db "abc",0
def db "def",0
...
mov ecx,3                          #the length of the abc and def strings
cld                                  #set the direction flag so that EDI and ESI will increase using repe
mov esi, offset [abc]               #moves address of abc string into esi
mov edi, offset [def]                  #exact syntax may differ depending on assembler you use
                                       #I am not exactly sure what MASM accepts but certainly something similar to this
repe cmpsb     							 #repeat compare [esi] with [edi] until ecx!=0 and current chars in strings match
											#edi and esi increase for each repetition, so pointing to the next char
cmp ecx,0     								 #test if the above command passed until the end of strings
je strings_are_equal  								#if yes then strings are equal
														# here print the message that strings are not equal (i.e. invoke MessageBox)
jmp end
strings_not_equal:
													# here print the message that strings are equal (i.e. invoke MessageBox)
end:





.data
	sz1 db "hello",0
	sz2 db "hello",0
.code

cld
lea edi,sz1
mov ecx,-1
xor eax,eax
mov edx,edi
repnz scasb
sub edi,edx
mov ecx,edi
mov edi,edx

lea esi,sz2
repz cmpsb
.if ZERO?
	; equal
.else
	; not equal	
.endif






