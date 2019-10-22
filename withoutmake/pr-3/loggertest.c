#include"loggertest.h"

void Log_enable()
{
#define Logger
}

void Log_disable()
{


}



void Log_data(uint32_t* pointer,uint8_t length)
{
	printf("address = %p \n",pointer);
	uint8_t* tempp = NULL;
	tempp=(uint8_t*)pointer;
	for(uint8_t i = 0;i<length;i++)
	{
		printf("%x",*(tempp+i));

	}
	printf("\n");
}


int Log_status(uint8_t x)
{
if(x)
return 1;
else
return 0;
}


void log_string(char *letter)
{
printf("%s",letter);
printf("\n");
}

void log_integer(uint32_t integer)
{
printf("%d\n",integer);
}




