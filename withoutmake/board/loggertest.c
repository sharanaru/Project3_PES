#include"loggertest.h"

uint8_t Log_enable()
{
 return 1;
}

uint8_t Log_disable()
{
return 0;
}



void Log_data(uint32_t* pointer,uint8_t length)
{

	uint8_t* tempp = NULL;
	tempp=(uint8_t*)pointer;//to print out characters byte by byte
	for(uint8_t i = 0;i<length;i++)
	{
		printf("address = %p ",(tempp+i));
		printf("data= %d \n",*(tempp+i));

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
printf("%x\n",integer);
}




