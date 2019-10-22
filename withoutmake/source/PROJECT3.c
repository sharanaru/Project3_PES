//
/**
 * @file    PROJECT3.c
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

char pass[] = "CORRECT\n\r";
char fail[] = "WRONG\n\r";
char invert[] = "First Invert\n\r";
char sinvert[] = "Second Invert\n\r";
int main(void) {
	uint8_t flag=0;
LED_Initialise();
  	/* Init board hardware. */
#ifdef KL25Z
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
#ifdef ENABLE
flag = Log_enable();
#endif

# ifdef DISABLE
flag=Log_disable();
#endif
  //printf("Enter Bytes to be allocated\n");
  int a=16;
  //scanf("%d\n", &a);
  uint32_t * memoryblock = NULL;
  memoryblock = allocate_words(a);
  write_pattern(memoryblock, a, 'a');

  uint8_t * verify = NULL;
  verify = display_memory(memoryblock, a);

  if (1 == flag) {


    Log_data((uint32_t *)verify, a);

  }
  uint32_t *errors = NULL;
  errors = verify_pattern(memoryblock, a, 'a');

  if (1 == flag) {

    for (int i = 0; i < a; i++) {
      if (*(errors + i) != 0) {

        log_string(fail);
        log_integer(*(errors+i));
      } else {
        //printf("correct\n\r");
        log_string(pass);
        log_integer(*(errors+i));
      }
    }
    printf("\n");
  }

  write_memory(memoryblock, 0xFFEE);
  verify = NULL;
  verify = display_memory(memoryblock, a);
  uint32_t * error = NULL;
  error = verify_pattern(memoryblock, a, 'a');
  for (int i = 0; i < a; i++) {
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
   write_pattern(memoryblock, a, 'a');
  verify = NULL;
  verify = display_memory(memoryblock, a);

  if (1 == flag) {


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

  offsetaddress = get_address(memoryblock, 4);

   invert_block(offsetaddress, 4);
  uint8_t * invertwrite = NULL;
  invertwrite = (uint8_t * ) offsetaddress;
  if (1 == flag)
  {
    log_string(invert);
    log_integer( *invertwrite);
  }
  uint32_t * err = NULL;;
  err = verify_pattern(memoryblock, a, 'a');
  for (int i = 0; i < a; i++) {
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

   invert_block(offsetaddress, 4);
  if (1 == flag) {

    log_string(sinvert);
  }

  uint32_t *er=NULL;
  er=verify_pattern(memoryblock, a, 'a');
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
  free_words(memoryblock);

  return 0;
}

