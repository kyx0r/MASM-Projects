@echo off
pushd c:\ASM\Text ADV

if not exist rsrc.rc goto over1
\MASM32\BIN\Rc.exe /v rsrc.rc
\MASM32\BIN\Cvtres.exe /machine:ix86 rsrc.res

:over1

\masm32\bin\ml /c /Zd /coff TextADV.asm
if errorlevel 1 goto errasm
\masm32\bin\Link /SUBSYSTEM:CONSOLE TextADV.obj
if errorlevel 1 goto errlink

TextADV.exe

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
pause