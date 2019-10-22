//PES Project 3- for printing out log data and address while execution By- Sharan and Abhijeet
#ifdef KL25Z
#include "fsl_debug_console.h" 
#endif
#include <stdio.h>
#include<stdint.h>
uint8_t Log_enable();//enables logger
uint8_t Log_disable();//disables logger
void Log_data(uint32_t* pointer,uint8_t length);//prints data and address of memory block
int Log_status(uint8_t x);//checks if logger is enabled
void log_string(char *letter);//prints string
void log_integer(uint32_t integer);//prints integer 



