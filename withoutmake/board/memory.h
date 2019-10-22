#include<stdio.h>
#ifdef KL25Z
#include<board.h>
#endif
#include<stdlib.h>
#include "pattern_gen.h"
#include "led_board.h"
/* PES PROJECT 3- SHARAN ARUMUGAM AND ABIJEET 
Memory Test Suite*
*/
typedef enum mem_status
{
SUCCESS = 0, // no error
FAILED // failure case
} mem_status;
 
uint32_t * allocate_words(size_t length);//tries to malloc a memory block of required length if not possible returns null pointer
void free_words(uint32_t* src); //fress allocation pointed to by pointer 
uint8_t * display_memory(uint32_t * loc,size_t length); //returns another pointer containing the contents at loc and of size length 
mem_status write_memory(uint32_t * loc, uint16_t value);//writes  value at memory address pointed by loc  
mem_status invert_block(uint32_t*loc,size_t length);// toggles all the bits at memory address - loc. length gives number of bytes to toggle 
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed); //writes random pattern at memory address  
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);// verifies whether pattern at address matches random pattern and returns list of addresses where pattern didnt match
uint32_t *get_address (uint32_t *base_addr, uint32_t offset); //retunrs a pointer which points to memory location at base_addr+offset
