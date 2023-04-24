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

	for(int i = 0; i < 5; ++i){
		DDRA |= (1<<i);
	}

	while(1){

		for(int i = 0; i < 5; ++i){
			PORTA |= (1<<i);
			_delay_ms(300);
		}

		for(int i = 0; i < 5; ++i){
			PORTA &= ~(1<<i);
			_delay_ms(300);
		}

	}

	return 0;
}
