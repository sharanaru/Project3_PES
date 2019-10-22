#include "pattern_gen.h"

void gen_pattern(uint8_t *pattern, size_t length, int8_t seed)// linear congruential generator
{
	    uint16_t a=34509;//random constant
	    uint32_t m=1653656;//modulus
	    uint16_t c=664;//constant
	    *pattern=seed;//first value is seed itself
for(int i=1;i<length;i++)
	    {
	      *(pattern+i)=(a*(*(pattern+(i-1)))+c)%m;//random value depends on previous value also
	    }

}
