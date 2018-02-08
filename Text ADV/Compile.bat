pushd c:\ASM\Text ADV
\masm32\bin\ml /c /Zd /coff TextADV.asm
\masm32\bin\Link /SUBSYSTEM:CONSOLE TextADV.obj
TextADV.exe
pause