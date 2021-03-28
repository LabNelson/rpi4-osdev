Writing a "bare metal" operating system for Raspberry Pi 4 (Part 12)
====================================================================

Porting the WordUp Graphics Toolkit
-----------------------------------
Back in the mid-1990s (when I was young!), programmers who wanted to build their own games didn't have rich frameworks like Unity. Perhaps the closest we got was the WordUp Graphics Toolkit, which I came across on the Hot Sound & Vision CD-ROM - a BBS archive. If you have a moment, perhaps use Google to see what "bulletin board systems" were... nostaglia awaits!

Much like my very simple _fb.c_, the WGT provides a library of graphics routines which can be depended upon for reuse. This library, however, is much more fully-fledged than mine, and makes it easy to build sprite-based games (like Breakout, Space Invaders, Pacman etc.).

The directory structure
-----------------------
As I port the WGT to my OS (a.k.a. make it work on my OS), I am using the following directories:

 * _bin/_ : for WGT binary files (fonts, sprites, bitmaps etc.)
 * _controller/_ : a new Node.js BLE controller which is a little more advanced and fully emulates a 2-button mouse
 * _include/_ : now contains _wgt.h_ and _wgtspr.h_ too (header files necessary for WGT code)
 * _sample/_ : sample "kernels" for my OS which exercise certain WGT library functions. To build them, copy one of these (and only one at a time) to the same directory as the _Makefile_.
 * _wgt/_ : the library itself. Where possible, I have stayed true to the original code, but do bear in mind it was written for the x86 architecture and we're on AArch64!

Building
--------
So... to build the first sample simply type `cp samples/wgt01.c .` from the top-level directory, and then type `make`. When you boot with the generated _kernel8.img_ you will see the screen go into 320x200 (VGA!) mode and draw a white line from corner to corner.

boot/boot.S changes
-------------------
We're still booting into a multicore environment (just in case we need it). There are a few significant changes to _boot/boot.S_ though. I will write more on these later, but (for now) they are:

 * Enable FPU (floating-point unit) access... so we can do non-integer mathematics
 * Switch from EL3 (supervisor exception level) down to EL1 (kernel exception level), disabling the MMU all the same
 * Move the addresses for the `spin_cpu` variables to accommodate a larger _boot.S_
 * Implement a `get_el` function to check which exception level we're at (for debug mainly)

Work in progress!
-----------------
This part is still work in progress - and it's a *lot* of work - so keep watching this space!

_In the meantime, do have a go at building some of the samples..._