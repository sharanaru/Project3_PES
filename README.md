# Project 3 PES - Readme

Team Members: 
Sharan Arumugam
Abhijeet Srivastava

# Execution Instructions
Using custom make file with 4 build targets:
-FB_DEBUG : Memory test for the KL25z with logger disabled
-FB_LOG : Memory test for the KL25z with logger enabled
-PC_DEBUG : Memory test for the PC with logger disabled
-PC_LOG : Memory test for the KL25z with logger disabled
Using make file, run
+ make -r -j8 all MODE=FB_Debug  *for FB_DEBUG*
+ make -r -j8 all MODE=FB_Log       *for FB_LOG*
+ make -r -j8 all MODE=PC_Debug   *for PC_DEBUG*
+ make -r -j8 all MODE=PC_Log       *for PC_LOG*
Makefile runs ***arm-none-eabi-gcc*** as compiler for FB routines and ***gcc*** for PC


# Files in Repo
+ MCU XPRESSO Project Directory
	+  Board Folder- Written routines for memtest, led,logger and pattern generation in memory.h, led_board.h and loggertest.h and pattern_gen.h and contains other default folder
     + Source Folder - Contains main routine- Project3.c
     + Default folders with no change -CMSIS,startup,drivers,utilities
     + Debug - Contains .o files after compilation and also contains .axf binary and .exe files
+ Readme 
+ PDF contains make file and code and readme



## Issues faced

+ Had to find a random generator which could generate same pattern with seed. Linear congruential generator fit the bill.
+ Had issues on understanding what each described function had to do.  Got answers from slack for most problems. Example: offset function had its parameters changed to include both base address and offset value. 
+ Learned to declare array as static if returning it in a function. 
## References
+ Slack channel for clearing up questions on function definitions
+ [https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/](https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/)
+ Makefile from Project 2 [https://github.com/abhijeet-sharan/pes_fun/blob/master/Project2/makefile](https://github.com/abhijeet-sharan/pes_fun/blob/master/Project2/makefile)
+ [https://en.wikipedia.org/wiki/Linear_congruential_generator](https://en.wikipedia.org/wiki/Linear_congruential_generator)

```
