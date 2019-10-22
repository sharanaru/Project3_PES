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

int main(void) {
	LED_Initialise();
  	/* Init board hardware. */
#ifdef KL25Z
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
    int b;printf("hey\n");
scanf(" %d",&b);size_t a=16;
//if(a<0)
//   scanf("",&a);
    uint32_t *memoryblock=NULL;
   memoryblock=allocate_words(a);

    //mem_status writing[5];
write_pattern(memoryblock,a,'a');
    //printf("pattern at address is:");
		if(memoryblock!=NULL)
		{
    uint8_t *verify=NULL;verify=display_memory(memoryblock,a);
    //verify=display_memory(memoryblock,16);

    printf("address  = %p\n\r",verify);
    for(int i=0;i<16;i++)
    {
    	printf("Address is:%p  %d \r\n",(verify+i),*(verify+i));
    	printf("%d \r\n",i);

    }
    uint32_t *errors=NULL;
    errors=verify_pattern(memoryblock,a,'a');
    for(int i=0;i<16;i++)
            {
            	if(*(errors+i)!=0)
            		printf("Wrong-%p\n\r",*(errors+i));
            	else
            		printf("correct\n\r");
            }
    printf("\n");
   write_memory(memoryblock,0xFFEE);
    uint32_t *error=NULL;
        error=verify_pattern(memoryblock,a,'a');
        for(int i=0;i<16;i++)
        {
        	if(*(error+i)!=0)
        		printf("Wrong-%p\n\r",*(error+i));
        }
       write_pattern(memoryblock,16,'a');verify=NULL;
        verify=display_memory(memoryblock,16);
            //verify=display_memory(memoryblock,16);

            printf("address  = %p\n\r",verify);
            for(int i=0;i<16;i++)
            {
            	printf("Address is:%p  %d \r\n",(verify+i),*(verify+i));
            	printf("%d \r\n",i);

            }
            errors=verify_pattern(memoryblock,a,'a');
                for(int i=0;i<16;i++)
                        {
                        	if(*(errors+i)!=0)
                        		printf("Wrong-%p\n\r",*(errors+i));
                        	else
                        		printf("correct\n\r");
                        }
                printf("\n");
                uint32_t *offsetaddress=NULL; printf("malloc at %p\n\r",memoryblock);
                offsetaddress=get_address(memoryblock,4); printf("%p\n\r",offsetaddress);

               invert_block(offsetaddress, 4);uint8_t *hell=NULL;
                		hell=(uint8_t *)offsetaddress;
                printf("first invert\n\r");printf("%d\n\r", *hell);
                uint32_t *err=NULL;;
                err=verify_pattern(memoryblock,a,'a');
                for(int i=0;i<16;i++)
                                        {
                                        	if(*(err+i)!=0)
                                        		printf("Wrong-%p\n\r",*(err+i));

                                        }
                                printf("\n");
                                invert_block(offsetaddress, 4);

                                printf("2nd invert\n\r");
                                uint32_t *er=NULL;
                                er=verify_pattern(memoryblock,16,'a');
for(int i=0;i<16;i++)
              {
                           if(*(errors+i)!=0)
                                    printf("Wrong-%p \n\r",*(errors+i));
                                                                        	else
                                                                        		printf("correct\n\r");
                                                                        }
                                                                printf("\n");
    free_words(memoryblock);
		}
    	return 0 ;
}
