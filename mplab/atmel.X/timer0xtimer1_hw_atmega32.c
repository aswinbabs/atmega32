/*
 * File:   timer0xtimer1_hw_atmega32.c
 * Author: Administrator
 *
 * Created on May 30, 2024, 3:54 PM
 */


#include <avr/io.h>
timer0(){
     TCCR0=0x05;
    while((TIFR&0x01)==0);
    TCNT0=178;
    TIFR=0x01;
}
timer1(){
      TCCR1A=0x00;
    TCCR1B=0x05;
    while((TIFR&0x04)==0);
    TCNT1L=0x64;
    TCNT1H=0xFF;
    TIFR=0x04;
}
init_port(){
   
  
    DDRD=0x00;
    DDRC=0xFF;
}
int main(void) {
    init_port();
    
    while (1) {
        
        if((PIND&0x04)==0){
            PORTC=0xFF;
            timer0();
            PORTC=0x00;
            timer0();
        }
        else if((PIND&0x08)==0){
            PORTC=0xFF;
            timer1();
            PORTC=0x00;
            timer1();
        }
        else{
            PORTC=0x00;
        }
    }
}
