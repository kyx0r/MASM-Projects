@echo off

pushd c:\ASM\SectorEX

del "usedll.exe"

\masm32\bin\ml /c /Zd /coff usedll.asm 
rem \masm32\bin\ml dllFile.asm /link /dll /noentry /out:dllFile.dll
if errorlevel 1 goto errasm

 rem \masm32\bin\Link /DLL /SUBSYSTEM:WINDOWS /DEF:DLLSkeleton.def /LIBPATH:c:\masm32\lib Inject.obj
\masm32\bin\Link /SUBSYSTEM:CONSOLE usedll.obj 
if errorlevel 1 goto errlink

usedll.exe

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
  del "Inject.exp"
  del "Inject.lib"
  del "Inject.obj"
  del "usedll.obj"
pause