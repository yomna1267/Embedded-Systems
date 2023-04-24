/*
 * mainn.c
 *
 *  Created on: Apr 24, 2023
 *      Author: yomna
 */



typedef unsigned char u8;

#define PINA *((volatile u8*)0x39)
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)

#define PINB *((volatile u8*)0x36)
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)

int main(void){
	 // Set LEDs as an output
	DDRA |= (1<<0);
	DDRA |= (1<<1);
	// Turn LEDs off
	PORTA &= ~(1<<0);
	PORTA &= ~(1<<1);
	// Set switches as an input
	DDRB &= ~(1<<0);
	DDRB &= ~(1<<1);
	DDRB &= ~(1<<2);
	// Switches are pulled up
	PORTB |= (1<<0);
	PORTB |= (1<<1);
	PORTB |= (1<<2);


	while(1){
		if(((PINB>>0)&1) == 0){
			PORTA |= (1<<0);
		}
		else if(((PINB>>1)&1) == 0){
			PORTA |= (1<<1);
		}
		else if(((PINB>>2)&1) == 0){
			PORTA |= (1<<0);
			PORTA |= (1<<1);
		}
		else{
			PORTA &= ~(1<<0);
			PORTA &= ~(1<<1);
		}
	}
	return 0;
}
