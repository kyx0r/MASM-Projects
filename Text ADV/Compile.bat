@echo off
color a
pushd c:\ASM\Text ADV\res

if not exist rsrc.rc goto over1
\MASM32\BIN\Rc.exe /v rsrc.rc
\MASM32\BIN\Cvtres.exe /machine:ix86 rsrc.res
copy "c:\ASM\Text ADV\res\rsrc.obj" "c:\ASM\Text ADV"
pushd c:\ASM\Text ADV

:over1

\masm32\bin\ml /c /Zd /coff TextADV.asm 
if errorlevel 1 goto errasm
\masm32\bin\Link /SUBSYSTEM:CONSOLE TextADV.obj rsrc.obj
if errorlevel 1 goto errlink

TextADV.exe
del "c:\ASM\Text ADV\rsrc.obj"

:errasm
: -----------------------------------------------------
: display message if there is an error during assembly
: -----------------------------------------------------
echo.
echo There has been an error while assembling this project.
echo.
goto TheEnd

:errlink
: ----------------------------------------------------
: display message if there is an error during linking
: ----------------------------------------------------
echo.
echo There has been an error while linking this project.
echo.
goto TheEnd

:TheEnd
del "c:\ASM\Text ADV\rsrc.obj"
pause