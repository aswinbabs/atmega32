/*
 * File:   4sw.c
 * Author: Administrator
 *
 * Created on May 16, 2024, 2:25 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void) {
    DDRD=0XFF;   //LEDS
    DDRC=0X00;  //SWITCHES
    int i;
    while (1) {
        
        if((PINC&0X01)==0){
            
            PORTD=0XFF;
            
            
        }
        else if((PINC&0X02)==0){
            
            PORTD=0XFF;
            _delay_ms(500);
            PORTD=0X00;
            _delay_ms(500);
        }
        else if((PINC&0X04)==0){
            
            for(i=0;i<8;i++){
                
                PORTD=0X80>>i;
                _delay_ms(500);
            }
            
        }
        else if((PINC&0X08)==0){
            
            for(i=0;i<8;i++){
                
                PORTD=0X01<<i;
                _delay_ms(500);
            }
        }
        else{
            PORTD=0X00;
        }
        
    }
    return 0;
}
