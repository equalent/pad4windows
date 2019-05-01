@echo off
echo Creating .lib for libpad.def...
cd lib
lib /def:libpad.def /out:libpad.lib /machine:x64
cd ..
echo DONE