//
/**
 * @file    PROJECT3.c PES project 3 Main routine - SHaran Arumugam and Abhijeet 
 * @brief   Application entry point.
 */
#ifdef KL25Z
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#include <stdio.h>
#include "memory.h"
#include "loggertest.h"
#include "led_board.h"
#include<stdint.h>

char pass[] = "CORRECT\n\r";//sets message for valid entry in memory
char fail[] = "WRONG\n\r";//sets message for invalid entry in memory
char invert[] = "First Invert\n\r";//sets message after first toggle entry in memory
char sinvert[] = "Second Invert\n\r";//sets message after second toggle in memory
int main(void) {
	uint8_t flag=0;//flag for logger enable or disable
LED_Initialise();//initialises led pins
  	/* Init board hardware. */
#ifdef KL25Z //board iniitlsiation routine only for KL25Z
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
#ifdef ENABLE
flag = Log_enable(); // enables logger
#endif

# ifdef DISABLE
flag=Log_disable(); //disables logger
#endif
  
  int a=16;
  
  uint32_t * memoryblock = NULL;
  memoryblock = allocate_words(a); //creates memory block of size 16 (a) bytes
  write_pattern(memoryblock, a, 'a'); //writes random pattern using seed of 'a'

  uint8_t * verify = NULL;
  verify = display_memory(memoryblock, a);//getting values stored at malloc

  if (1 == flag) {


    Log_data((uint32_t *)verify, a); //logger to print pattern and array containig pattern from memoryblock 

  }
  uint32_t *errors = NULL;
  errors = verify_pattern(memoryblock, a, 'a'); //checking for errors

  if (1 == flag) {

    for (int i = 0; i < a; i++) {
      if (*(errors + i) != 0) {

        log_string(fail); //prints fail msg when pattern and value at memory dont match
        log_integer(*(errors+i));//[rints address where it failed
      } else {
        
        log_string(pass);//prints pass message
        log_integer(*(errors+i));//returns o as address is not stored when value at memory is  same as expected pattern
      }
    }
    printf("\n");
  }

  write_memory(memoryblock, 0xFFEE);//writes value to memory block as FFEE is 2 bytes writes FF,EE at 2 succesive locations 
  verify = NULL;
  verify = display_memory(memoryblock, a);//returns array containing values stored at memoryblock 
  uint32_t * error = NULL;
  error = verify_pattern(memoryblock, a, 'a');//returns array containing addresses where error is present
  for (int i = 0; i < a; i++) {  //to print and set led for pass and fail conditions
    if ( * (error + i) != 0)
    {
      if (1 == flag) {

        log_string(fail);
        log_integer(*(error+i));
      }
	  LED_FAIL();
    }
	  else {
		LED_PASS();
      if (1 == flag) {

        log_string(pass);log_integer(*(error+i));
      }
    }

  }
   write_pattern(memoryblock, a, 'a'); //writing random pattern to memoryblock using same seed as before
  verify = NULL;
  verify = display_memory(memoryblock, a);//returns array containing addresses where error is present

  if (1 == flag) { //prints data and address at verify


    Log_data((uint32_t *)verify, a);
  }
  errors = verify_pattern(memoryblock, a, 'a');
  for (int i = 0; i < a; i++) {
    if ( *(errors + i) != 0) {
      if (1 == flag) {

        //printf("Wrong-%p\n\r",*(errors+i));
        log_string(fail);log_integer(*(errors+i));
      }
	  LED_FAIL();
    }
	else {
		LED_PASS();
      if (1 == flag) {

        log_string(pass);log_integer(*(errors+i));
      }
    }
  }
  if (1 == flag) {

    printf("\n");

  }
  uint32_t * offsetaddress = NULL;

  offsetaddress = get_address(memoryblock, 4);//calculates address +offset and sets a pointer to it

   invert_block(offsetaddress, 4);
  uint8_t * invertwrite = NULL;
  invertwrite = (uint8_t * ) offsetaddress;
  if (1 == flag)
  {
    log_string(invert);
    log_integer( *invertwrite);
  }
  uint32_t * err = NULL;;
  err = verify_pattern(memoryblock, a, 'a'); // returns at address where error is found 
  for (int i = 0; i < a; i++) { //printing out error check results
    if ( * (err + i) != 0)
    {
      if (1 == flag)
      {

        log_string(fail);log_integer(*(err+i));
      }
	  LED_FAIL();
    }
  else
  {
  log_string(pass);log_integer(*(err+i));
  LED_PASS();
  }
  }

   invert_block(offsetaddress, 4); //inverting at same address again
  if (1 == flag) {

    log_string(sinvert);
  }

  uint32_t *er=NULL;
  er=verify_pattern(memoryblock, a, 'a'); //checking for errors
  for (int i = 0; i < a; i++) {
    if ( * (er + i) != 0) {
      if (1 == flag) {

        log_string(fail);log_integer(*(er+i));
      }
	  LED_FAIL();
    }
	else
	{
		LED_PASS();
    if (1 == flag) {


      log_string(pass);
      log_integer(*(er+i));

    }
	}

  }
  free_words(memoryblock); //freeing memoryblock 

  return 0;
}

