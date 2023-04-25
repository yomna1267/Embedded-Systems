/*
 * main.c
 *
 *  Created on: Apr 25, 2023
 *      Author: mo
 */

typedef unsigned char u8;
#include <util/delay.h>
#define PINA *((volatile u8*)0x39)
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)

#define PINB *((volatile u8*)0x36)
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)

int main(void){
	char state[] = {
			0x3F, 0x06, 0x5B, 0x4F,0x66,
			0x6D, 0x7D, 0x07, 0x7F, 0x6F
	};

	// Set switches as an input
	DDRA &= ~(1<<0);
	DDRA &= ~(1<<1);

	// Switches are pulled up
	PORTA |= (1<<0);
	PORTA |= (1<<1);

	// 7-segment as an output
	DDRB = 0xff;

	// Display Zero
	PORTB = 0x3F;

	int counter = 0;
	while(1){
		if(((PINA>>0)&1) == 0){
			counter++;
			if(counter > 9){
				counter = 9;
			}
			PORTB = state[counter];
			while(((PINA>>0)&1) == 0);
		}
		else if(((PINA>>1)&1) == 0){
			counter--;
			if(counter < 0){
				counter = 0;
			}
			PORTB = state[counter];
			while(((PINA>>1)&1) == 0);
		}
	}
}

