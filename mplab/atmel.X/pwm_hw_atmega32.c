/*
 * File:   pwm_hw_atmega32.c
 * Author: Administrator
 *
 * Created on May 31, 2024, 2:30 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
delay(){
    _delay_ms(100);
}
command(char a){
    PORTB=a;
    PORTD=0x40;
    delay();
    PORTD=0x00;
}
data(char a){
    PORTB=a;
    PORTD=0x60;
    delay();
    PORTD=0x20;
}
display(const char *str){
    while(*str!='\0'){
        data(*str);
        str++;
    }
}
init_lcd(){
    command(0x01);
    command(0x06);
    command(0x38);
    command(0x0E);
    command(0x80);
    
}
init_ports(){
    DDRB=0xFF;
    DDRC=0xFF;
    DDRD=0xE0;
}
int main(void) {
    init_ports();
    init_lcd();
    TCCR2=0x6F;      //for fast pwm
    int count=0;
    
    while (1) {
        while(1){
            command(0x80);
            display("Press Button\n\r");
            if((PIND&0x10)==0){
            count++;
            if(count>3){
                count=0;
            }
            while((PIND&0x10)==0);
            break;
            }
        
        }

        
          
          switch(count){
              
              case 1:
                  command(0x01);
                  command(0xC0);
                  PORTC=0XFF;
                  OCR2=64;
                  display("25%");
                  command(0X80);
                  
                  break;
              case 2:
                  command(0x01);
                  command(0xC0);
                  PORTC=0XFF;
                  OCR2=128;
                  display("50%");
                  command(0X80);
                  break;
                  
              case 3:
                  command(0x01);
                  command(0xC0);
                  PORTC=0XFF;
                  OCR2=192;
                  display("75%");
                  command(0X80);
                  break;
              default:
                  PORTC=0x00;
          }
    }
    
}
