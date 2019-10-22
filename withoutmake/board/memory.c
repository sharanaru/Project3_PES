#include "memory.h"
#include "led_board.h"


uint32_t * allocate_words(size_t length)
{
LED_PROCESS();//switches blue led on
uint32_t *p = NULL;
 p=malloc(length * sizeof(uint8_t));//malloc a memeory block depending on input number of bytes
if(p==NULL)//checking if malloc was successfull
{
    printf("Memory not allocated\n\r");
    LED_FAIL();//switches red led on
}
else
{
    printf("Memory allocated = %p\n",p);
    LED_PASS();//switches green led on
    // for now let the memory be
}
return p;
}
void free_words(uint32_t* src)
{
	LED_PROCESS();
if(NULL==src)
    {
    printf("Error: Cannot free unallocated memory!\n");//if pointer is already at null doesnt free
    LED_FAIL();//switches on red led 
    }
else
    {
free(src);//freeing block of memory
src=NULL;
LED_PASS();
    }
}
uint8_t * display_memory(uint32_t *loc,size_t length)
{
	LED_PROCESS();
	volatile uint8_t *ptr=NULL;
    		ptr=(uint8_t *)loc;//casting loc to uint8_t type pointer
    static uint8_t *arr=NULL;//as returning arr defined as static
    arr=malloc(length*sizeof(uint8_t));//setting a block depending on size of bits
	for(int i=0;i<length;i++)
	{
		arr[i]=*ptr;//getting values at memory address loc and assigning to arr block
		ptr++;
	}
return arr;//returning pointer

}
mem_status write_memory(uint32_t *loc,uint16_t value)
{LED_PROCESS();
    uint16_t *ptr=NULL;
    ptr=(uint16_t *)loc;//casting to uint16 pointer and then writing value
    *ptr = value;
    return SUCCESS;
}

mem_status invert_block(uint32_t * loc, size_t length)
{LED_PROCESS();
	uint8_t *ptr=NULL;//casting to uint8_t pointer
	ptr=(uint8_t*)loc;
	for(int i=0;i<length;i++)
	{
		ptr[i]^=0xFF; //toggling all bits in that specific byte
	}
	return SUCCESS;
}

mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{ LED_PROCESS();
	uint8_t *patternwrite=NULL;//random patterns are of type int8_t
	patternwrite=(uint8_t *)loc;//casting to uint8 pointer 
	

	gen_pattern(patternwrite,length,seed);//calls pattern generating function

	return SUCCESS;
	}

 uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{LED_PROCESS();
	uint8_t storepattern[length]; 
	gen_pattern(storepattern,length,seed);//creates a array containg standard random pattern
	uint8_t *testptr=NULL;
	testptr=(uint8_t *)loc;
	  uint32_t *errorlist=NULL;
	  errorlist=malloc(length*sizeof(uint32_t));//list containg addresses where values dont match

	for(int i=0;i<length;i++) //goes through memory block and tests with pattern. if not matching stores address in memory block else sets as 0
	{
		if((*(testptr+i))!=storepattern[i])
            errorlist[i]=(uint32_t)(testptr+i); 
		else
			errorlist[i]=0;

	}
	return errorlist;
}
uint32_t *get_address (uint32_t *base_addr, uint32_t offset) //returns uint32_t* type pointer to base address +offset
{
LED_PROCESS();
uint8_t *offset_address=NULL;
offset_address=(uint8_t *)base_addr;//casts base adress to uint8 ptr
while(offset!=0)
{
	offset_address++;offset--;//uses poiner math to increment address by offset value
}
uint32_t * return_offset_address=NULL;
return_offset_address=(uint32_t *)offset_address;//casts pointer uint32 type to match return value.
return return_offset_address;
}


