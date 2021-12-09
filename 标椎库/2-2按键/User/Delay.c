#include "stm32f10x.h"                  // Device header

void Delay(unsigned int x)
{
	while(x--)
	{
		unsigned char i, j;
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}


void Delay_ms(uint16_t u16_Time_ms)
{
	uint16_t i,j;
	for(i=0;i<u16_Time_ms;i++)
	{
		for (j=0;j<9192;j++);
	}
}
