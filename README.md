# Pad4Windows
Sony DUALSHOCK® 3 library for Windows (libPad for PC Games) allows you to implement DUALSHOCK® 3 in your Windows game.

# Disclaimer
This library was created by examining SIE's `libpad.dll` to produce `libpad.lib` and modifying [PSL1GHT](https://github.com/HACKERCHANNEL/PSL1GHT) `pad.h` to create a valid header file.
You are free to use it under WTFPL 2.0:
```
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                   Version 2, December 2004
 
Copyright (C) 2019 Andrey Tsurkan <andrey.turcan@hotmail.com>

Everyone is permitted to copy and distribute verbatim or modified
copies of this license document, and changing it is allowed as long
as the name is changed.
 
           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

 0. You just DO WHAT THE FUCK YOU WANT TO.
```
However, Sony Interactive Entertainment (SIE) may prohibit the use of this library in a commercial game if you are not a current member of the PlayStation Partners program. You can always use DirectInput as an alternative but some DS3 features are not supported by DirectInput.

# Requirements
MSVC Toolchain is required to create the `libpad.lib` file. 

# Tutorial
## 0. Getting Started
1. Clone the repository to any directory; download `libpad.dll` from latest release and move it to your output directory
2. Add the `include` folder to "Additional Include Directories" in Visual Studio project properties (in "C++ - General").
3. Add the `lib` folder to "Library Directories" in "Linker - Input"
4. Run the Native Tools command line that is installed with Visual Studion in the Start menu
5. Use `cd` command to open the directory with `create_lib.bat` file
6. Type `create_lib.bat` in the Native Tools window
7. Add `libpad.lib` to Additional Dependencies in "Linker - Input"
## 1. Initializing the library
```cpp
#define MAX_CONNECT 1
...
int result = cellPadInit(MAX_CONNECT);
if(result < 0){
        /* ERROR HANDLING */
}
```
## WIP
