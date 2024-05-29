/*
 * File:   timer1_atmega32.c
 * Author: Administrator
 *
 * Created on May 23, 2024, 2:13 PM
 */


#include <avr/io.h>
timer1(){
    while((TIFR&0x04)==0);
    TCNT1L=0XB2;
    TCNT1H=0XFF;
    TIFR=0X04;
}
int main(void) {
    DDRD=0XFF;
    TCCR1A=0X00;
    TCCR1B=0X05;
    
    
    while (1) {
        PORTD=0XFF;
        timer1();
        PORTD=0X00;
        timer1();
    }
}
