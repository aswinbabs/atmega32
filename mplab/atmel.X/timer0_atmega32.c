/*
 * File:   timer.c
 * Author: Administrator
 *
 * Created on May 22, 2024, 3:54 PM
 */


#include <avr/io.h>
timer(){
    while((TIFR&0x01)==0);
        TCNT0=178;
        TIFR=0X01;
    
}
int main(void) {
    DDRD=0XFF;
    TCCR0=0X05;
    while (1) {
        int i;
        PORTD=0XFF;
      
        timer();
        PORTD=0X00;
       
        timer();
    }
}
