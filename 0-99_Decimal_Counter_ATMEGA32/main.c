/*
 * Home111.c
 *
 * Created: 4/12/2021 11:13:12 PM
 * Author : zeinab walid
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{ unsigned int arr[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x010,0x011};
	unsigned int i = 0;
	unsigned int j = 0;
	DDRA = 0XFF;
	DDRB = 0XFF;
    /* Replace with your application code */
    while (1) 
    {   PORTA = 0x04;
		PORTB=arr[i];
		_delay_ms(30);
		PORTA=0x08;
		PORTB=arr[j];
		_delay_ms(30);
		if (PINC == 0x01)
		{  _delay_ms(300);
			i++;
			if(i==10){
				i=0;
				j++;
			}
			if(j==10){
				j=0;
			}
		}
    }
}

