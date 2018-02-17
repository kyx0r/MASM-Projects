@echo off
color a
pushd c:\ASM\TextADV\res

if not exist rsrc.rc goto over1
\MASM32\BIN\Rc.exe /v rsrc.rc
\MASM32\BIN\Cvtres.exe /machine:ix86 rsrc.res
copy "c:\ASM\TextADV\res\rsrc.obj" "c:\ASM\TextADV"
pushd c:\ASM\TextADV

:over1

\masm32\bin\ml /c /Zd /coff TextADV.asm 
pushd c:\ASM\TextADV\include
\masm32\bin\ml /c /Zd /coff vector.asm
\masm32\bin\ml /c /Zd /coff matrix.asm
\masm32\bin\ml /c /Zd /coff d3dsetup.asm
copy "c:\ASM\TextADV\include\d3dsetup.obj" "c:\ASM\TextADV"
copy "c:\ASM\TextADV\include\matrix.obj" "c:\ASM\TextADV"
copy "c:\ASM\TextADV\include\vector.obj" "c:\ASM\TextADV"
pushd c:\ASM\TextADV\

if errorlevel 1 goto errasm
\masm32\bin\Link /SUBSYSTEM:CONSOLE TextADV.obj rsrc.obj d3dsetup.obj matrix.obj vector.obj 
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
del "c:\ASM\TextADV\rsrc.obj"
del "c:\ASM\TextADV\d3dsetup.obj" 
del "c:\ASM\TextADV\matrix.obj" 
del "c:\ASM\TextADV\vector.obj"
del "c:\ASM\TextADV\TextADV.obj"
pause


