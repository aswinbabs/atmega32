/*
 * File:   motor.c
 * Author: Administrator
 *
 * Created on May 16, 2024, 3:14 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void) {
    DDRD=0XFF;   //motors
    DDRC=0X00;  //SWITCHES
    /* Replace with your application code */
    while (1) {
        if((PINC&0X01)==0){                     //pc0  or sw1
            
          PORTD=0X05;
          //_delay_ms(500);
            
            
        }
        else if((PINC&0X02)==0){                  //pc1 or sw2
          PORTD=0X06;
         // _delay_ms(500);
            
        }
        else{
            PORTD=0X00;
        }
    }
    return 0;
}
