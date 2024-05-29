/*
 * File:   INTERRUPT_ATMEGA32.c
 * Author: Administrator
 *
 * Created on May 27, 2024, 3:48 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
delay(){
    _delay_ms(500);
}
int main(void) {
    DDRB=0X0F;
    DDRC=0XFF;
    DDRD=0X0B;
    
    MCUCR=0X02;
    GICR=0X40;
    
    sei();
    int i;
    while (1) {
        
        for(i=0x01;i<=0x80;i<<=1){
            PORTC=i;
            delay();
        }
    }
}
ISR(INT0_vect){
    int i=0;
    while(i<5){
        PORTB=0xFF;
        delay();
        PORTB=0x00;
        delay();
        i++; 
    }
    
    GIFR=0x40;
}