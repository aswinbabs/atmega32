/*
 * File:   ATMEGA_HWTEST.c
 * Author: Administrator
 *
 * Created on May 27, 2024, 4:45 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

delay(){
    _delay_ms(500);
}
int main(void) {
    DDRC=0XFF;
    DDRD=0X00;
    int i;
    while (1) {
        if(  ((PIND& 0x10  ) ==0)|| ((PIND& 0x08  ) ==0)|| ((PIND& 0x04  ) ==0) ){
            
            for(i=0x01;i<=0x04;i<<=1){
                PORTC=i;
                delay();
            }
        }
        else{
            PORTC=0x00;
        }
    }   
}
