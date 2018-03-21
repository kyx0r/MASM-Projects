@echo off

pushd c:\ASM\SectorEX

\masm32\bin\ml /c /Zd /coff Inject.asm 
rem \masm32\bin\ml /c /Zd /coff usedll.asm 
if errorlevel 1 goto errasm

\masm32\bin\Link /DLL /SUBSYSTEM:WINDOWS /DEF:DLLSkeleton.def /LIBPATH:c:\masm32\lib Inject.obj
 rem \masm32\bin\Link /SUBSYSTEM:CONSOLE usedll.obj 
rem \masm32\bin\Link /SUBSYSTEM:CONSOLE Inject.obj 
if errorlevel 1 goto errlink
rem usedll.bat

goto TheEnd


:errlink
echo _
echo Link error
goto TheEnd

:errasm
echo _
echo Assembly Error
goto TheEnd

:TheEnd
  usedll.bat
pause