
COINVOKE MACRO pInterface:REQ, Interface:REQ, Function:REQ, args:VARARG
    LOCAL istatement, arg
    ;; invokes an arbitrary COM interface 
    ;; pInterface    pointer to a specific interface instance
    ;; Interface     the Interface's struct typedef
    ;; Function      which function or method of the interface to perform
    ;; args          all required arguments 
    ;;                   (type, kind and count determined by the function)
    istatement TEXTEQU <invoke (Interface PTR[eax]).&Function, pInterface>
    FOR arg, <args>
        ; build the list of parameter arguments
        istatement CATSTR istatement, <, >, <&arg>
    ENDM
    mov eax, pInterface
    mov eax, [eax]
    istatement
ENDM



return MACRO arg
	mov eax,arg
	ret
ENDM


ZeroMemory MACRO dest,bytes
	push edi
	push eax
	push ecx
	mov edi,dest
	xor eax,eax
	mov ecx,bytes
	rep stosb
	pop ecx
	pop eax
	pop edi
ENDM


MOVF32 MACRO dest,val
	LOCAL lbl,fimmed
	jmp lbl
fimmed: REAL4 val
lbl:
	push dword ptr fimmed
	pop dword ptr dest
ENDM


LINKFUNC MACRO library,szfuncname,funcptr
	invoke GetProcAddress,library,ADDR szfuncname
	.if eax == NULL
		invoke MessageBox,NULL,ADDR szfuncname,ADDR szDirectE,MB_OK
		popa
		return FALSE
	.endif
	mov funcptr,eax
ENDM


MSGBOX MACRO Text:REQ
    LOCAL lbl
    LOCAL sztext,szCaption
    jmp lbl
sztext:  
    db Text,0
szCaption:
    db 'Error',0
lbl:
    invoke MessageBox,NULL,sztext,szCaption,MB_OK
ENDM

