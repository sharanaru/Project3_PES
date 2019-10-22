#PES Project 3
#Team: Abhijeet Srivastava and Sharan Arumugam
#Makefile
#makefile has 2 different targets based on requirement
#FB_Debug
#PC_Debug
# https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/
# We would like to thank Rakesh, Gitanjali and Sorabh Gandhi for helping out with the project

# Command for removing files
RM := rm -rf

ifeq ($(MODE), FB_Debug)
# Include files
INCLUDES := \
	-I"CMSIS" \
	-I"source" \
	-I"board" \
	-I"drivers" \
	-I"utilities" \
	-I"startup"	

# Compiler

CC := arm-none-eabi-gcc

# Linker
LL := arm-none-eabi-gcc

# Binary/exectable to build
EXE := \
  ./Debug/Project3.axf

# List of object files
OBJS := ./Debug/Project3.o \
	./Debug/startup_MKL25Z4.o \
	./Debug/system_MKL25Z4.o \
	./Debug/board.o \
	./Debug/clock_config.o \
	./Debug/peripherals.o \
	./Debug/pin_mux.o \
	./Debug/fsl_clock.o \
	./Debug/fsl_common.o \
	./Debug/fsl_flash.o \
	./Debug/fsl_gpio.o \
	./Debug/fsl_lpsci.o \
	./Debug/fsl_smc.o \
	./Debug/fsl_uart.o \
	./Debug/led_board.o \
	./Debug/pattern_gen.o \
	./Debug/memory.o \
	./Debug/loggertest.o \
	./Debug/fsl_debug_console.o
	
# List of dependency files
C_DEPS = \
	./Project3.d \
	./Debug/startup_MKL25Z4.d \
	./Debug/system_MKL25Z4.d \
	./Debug/board.d \
	./Debug/clock_config.d \
	./Debug/peripherals.d \
	./Debug/pin_mux.d \
	./Debug/fsl_clock.d \
	./Debug/fsl_common.d \
	./Debug/fsl_flash.d \
	./Debug/fsl_gpio.d \
	./Debug/fsl_lpsci.d \
	./Debug/fsl_smc.d \
	./Debug/fsl_uart.d \
	./Debug/led_board.d \
	./Debug/pattern_gen.d \
	./Debug/memory.d \
	./Debug/loggertest.d \
	./Debug/fsl_debug_console.d
 
# Compiler options
CC_OPTIONS := \
	-c \
	-std=gnu99 \
	-O0 \
	-g3 \
	-ffunction-sections \
	-fmessage-length=0\
	-fno-common \
	-fdata-sections \
	-fno-builtin \
	-mcpu=cortex-m0plus \
	-mthumb


# Build Options
B_OPTIONS := \
	-D__REDLIB__ \
	-DCPU_MKL25Z128VLK4 \
	-DCPU_MKL25Z128VLK4_cm0plus \
	-DSDK_OS_BAREMETAL \
	-DFSL_RTOS_BM \
	-DSDK_DebugCONSOLE=0 \
	-DCR_INTEGER_PRINTF \
	-DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 \
	-DPRINTF_ADVANCED_ENABLE=0 \
	-DSCANF_ADVANCED_ENABLE=0 \
	-D__MCUXPRESSO \
	-D__USE_CMSIS \
	-DKL25Z \
	-DDISABLE \
	-DFREEDOM \
	-specs=redlib.specs \
	

# Linker Options
LL_OPTIONS := -nostdlib -Xlinker -Map="Debug/Project3.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE) 
LINKER := ./linkerfile.ld
# linker file
#FLAG:= -DFBD
# Macro passed to main C program
endif

#################################################################
ifeq ($(MODE),FB_Log)
# Include files
INCLUDES := \
	-I"CMSIS" \
	-I"source" \
	-I"board" \
	-I"drivers" \
	-I"utilities" \
	-I"startup"	

# Compiler

CC := arm-none-eabi-gcc

# Linker
LL := arm-none-eabi-gcc

# Binary/exectable to build
EXE := \
  ./Debug/Project3.axf

# List of object files
OBJS := ./Debug/Project3.o \
	./Debug/startup_MKL25Z4.o \
	./Debug/system_MKL25Z4.o \
	./Debug/board.o \
	./Debug/clock_config.o \
	./Debug/peripherals.o \
	./Debug/pin_mux.o \
	./Debug/fsl_clock.o \
	./Debug/fsl_common.o \
	./Debug/fsl_flash.o \
	./Debug/fsl_gpio.o \
	./Debug/fsl_lpsci.o \
	./Debug/fsl_smc.o \
	./Debug/fsl_uart.o \
	./Debug/led_board.o \
	./Debug/pattern_gen.o \
	./Debug/memory.o \
	./Debug/loggertest.o \
	./Debug/fsl_debug_console.o
	
# List of dependency files
C_DEPS = \
	./Project3.d \
	./Debug/startup_MKL25Z4.d \
	./Debug/system_MKL25Z4.d \
	./Debug/board.d \
	./Debug/clock_config.d \
	./Debug/peripherals.d \
	./Debug/pin_mux.d \
	./Debug/fsl_clock.d \
	./Debug/fsl_common.d \
	./Debug/fsl_flash.d \
	./Debug/fsl_gpio.d \
	./Debug/fsl_lpsci.d \
	./Debug/fsl_smc.d \
	./Debug/fsl_uart.d \
	./Debug/led_board.d \
	./Debug/pattern_gen.d \
	./Debug/memory.d \
	./Debug/loggertest.d \
	./Debug/fsl_debug_console.d
 
# Compiler options
CC_OPTIONS := \
	-c \
	-std=gnu99 \
	-O0 \
	-g3 \
	-ffunction-sections \
	-fmessage-length=0\
	-fno-common \
	-fdata-sections \
	-fno-builtin \
	-mcpu=cortex-m0plus \
	-mthumb


# Build Options
B_OPTIONS := \
	-D__REDLIB__ \
	-DCPU_MKL25Z128VLK4 \
	-DCPU_MKL25Z128VLK4_cm0plus \
	-DSDK_OS_BAREMETAL \
	-DFSL_RTOS_BM \
	-DSDK_DebugCONSOLE=0 \
	-DCR_INTEGER_PRINTF \
	-DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 \
	-DPRINTF_ADVANCED_ENABLE=0 \
	-DSCANF_ADVANCED_ENABLE=0 \
	-D__MCUXPRESSO \
	-D__USE_CMSIS \
	-DKL25Z \
	-DENABLE \
	-DFREEDOM \
	-specs=redlib.specs 
	

# Linker Options
LL_OPTIONS := -nostdlib -Xlinker -Map="Debug/Project3.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE) 
LINKER := ./linkerfile.ld
# linker file
FLAG:= -DFBD
# Macro passed to main C program
endif

#################################################################

ifeq ($(MODE), PC_Debug)
CC:=gcc
LL:=gcc
EXE:= ./PROJECT3.exe
OBJS:=./Debug/Project3.o \
     ./Debug/led_board.o \
	 ./Debug/pattern_gen.o \
	 ./Debug/memory.o \
	 ./Debug/loggertest.o 

C_DEPS := ./Project3.d \
          ./Debug/led_board.d \
	      ./Debug/pattern_gen.d \
	      ./Debug/memory.d \
	      ./Debug/loggertest.d 
INCLUDES:= \
	-I"source" \
	-I"board" 
	  
	
CC_OPTIONS:= -c -std=gnu99 
B_OPTIONS:= -DPC \
            -DDISABLE
FLAG:=-DPCD
# Macro passed to main c program for running pc Debug version
endif

############################
#################################################################

ifeq ($(MODE), PC_Log)
CC:=gcc
LL:=gcc
EXE:= ./PROJECT3.exe
OBJS:=./Debug/Project3.o \
     ./Debug/led_board.o \
	 ./Debug/pattern_gen.o \
	 ./Debug/memory.o \
	 ./Debug/loggertest.o 

C_DEPS := ./Project3.d \
          ./Debug/led_board.d \
	      ./Debug/pattern_gen.d \
	      ./Debug/memory.d \
	      ./Debug/loggertest.d 
INCLUDES:= \
	-I"source" \
	-I"board" 
	  
	
CC_OPTIONS:= -c -std=gnu99 
B_OPTIONS:= -DPC \
            -DENABLE

# Macro passed to main c program for running pc Debug version
endif
####################################################
# Main (all) target
all: $(EXE)
#	@echo "*** finished building ***"

############################
# Clean target
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) $(EXE)
	-$(RM) ./Debug/*
	-$(RM) ./a.exe
	-@echo "*******Cleaned!*******"

#############################
# Rule to link the executable
$(EXE): $(OBJS) $(USER_OBJS) $(LINKER)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	$(LL) $(LL_OPTIONS) $(OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

############################
# Rule to build the executable

#./Debug/test.o: ./source/test.c
#	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
#	@echo 'Finished building: $<'
#	@echo ' '
./Debug/Project3.o: ./source/Project3.c
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) $(FLAG) -o ./Debug/Project3.o ./source/Project3.c -Wall -Werror  	
############################
# Rule to build the files in the CMSIS folder
./Debug/%.o: ./CMSIS/%.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' ' 

############################
# Rule to build the files in the board folder
./Debug/board.o: ./board/board.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

############################
# Rule to build the files in the board folder
./Debug/clock_config.o: ./board/clock_config.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
############################
./Debug/led_board.o: ./board/led_board.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

############################
./Debug/memory.o: ./board/memory.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
#################################################
./Debug/loggertest.o: ./board/loggertest.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

# Rule to build the files in the board folder
./Debug/pattern_gen.o: ./board/pattern_gen.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
#########################################################
./Debug/peripherals.o: ./board/peripherals.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
############################
# Rule to build the files in the board folder
./Debug/pin_mux.o: ./board/pin_mux.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_clock.o: ./drivers/fsl_clock.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

############################
# Rule to build the files in the drivers folder
./Debug/fsl_common.o: ./drivers/fsl_common.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '	
	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_flash.o: ./drivers/fsl_flash.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '	
	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_gpio.o: ./drivers/fsl_gpio.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_lpsci.o: ./drivers/fsl_lpsci.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_smc.o: ./drivers/fsl_smc.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '			
	
############################
# Rule to build the files in the drivers folder
./Debug/fsl_uart.o: ./drivers/fsl_uart.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '	
############################
# Rule to build the files in the startup folder
./Debug/startup_MKL25Z4.o: ./startup/startup_mkl25z4.c
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '			  
	
############################
# Rule to build the files in the utilities folder
./Debug/fsl_debug_console.o: ./utilities/fsl_debug_console.c 
	@echo 'Building file: $<'
#	$(CC) $(CC_OPTIONS) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '