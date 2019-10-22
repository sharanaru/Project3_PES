#include "led_board.h"
#ifdef KL25Z
#include "board.h"
#endif
void delay()
{
volatile uint64_t i=0;
while(i!=390000) //holds execution till delay is achieved
{ __asm("NOP");
i++;
  }
}
//only for kl25z
#ifdef KL25Z
void LED_Initialise()
{
	LED_BLUE_INIT(1);
	LED_RED_INIT(1);
	LED_GREEN_INIT(1);
}
void ALLLED_OFF()
{
	LED_BLUE_OFF();
	LED_RED_OFF();
	LED_GREEN_OFF();
}
void LED_PASS()
{
ALLLED_OFF();
LED_GREEN_ON();
delay();
}
void LED_PROCESS()
{
ALLLED_OFF();
LED_BLUE_ON();
delay();
}
void LED_FAIL()
{
	ALLLED_OFF();
	LED_RED_ON();
	delay();
}
#endif
//when platform is pc
#ifdef PC
void LED_Initialise()//does nothing
{
	;
}
void ALLLED_OFF()//does nothing
{
	;
}
void LED_PASS()//prints green led is on
{
printf("green led on\n");
delay();
}
void LED_PROCESS()//prints blue led on //delay too less as clock on pc is much faster
{
printf("blue led on\n");
delay();
}
void LED_FAIL()
{
	printf("red led on\n");
	delay();
}
#endif
