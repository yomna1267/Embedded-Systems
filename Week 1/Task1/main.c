/*
 * main.c
 *
 *  Created on: Apr 18, 2023
 *      Author: yomna
 */

typedef unsigned char u8;
#include <util/delay.h>
#define PINA *((volatile u8*)0x39)
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)

int main(void){

	DDRA |= (1<<0);

	while(1){
		PORTA |= (1<<0);
		_delay_ms(1000);
		PORTA &= ~(1<<0);
		_delay_ms(1000);
	}

	return 0;
}

