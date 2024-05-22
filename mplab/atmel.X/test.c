/*
 * File:   test.c
 * Author: Administrator
 *
 * Created on May 15, 2024, 4:08 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void) {
    DDRD=0XFF;
    DDRC=0X00;/* Replace with your application code */
    while (1) {
        if((PINC&0X01)==0){
            PORTD=0XFF;
            _delay_ms(1000);
            PORTD=0X00;
            _delay_ms(1000);
        }
        if((PINC&0X20)==0X20){
            PORTD=0XFF;
            _delay_ms(1000);
            PORTD=0X00;
            _delay_ms(1000);
        }
    }
}
