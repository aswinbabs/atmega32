/*
 * File:   FAST_PWMxLCD_ATMEGA32.c
 * Author: Administrator
 *
 * Created on May 23, 2024, 3:16 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
delay(){
    _delay_ms(10);
}
void command(char a){
    PORTD=a;
    PORTC=0X02;      
    delay();
    PORTC=0X00;      
}
void data(char a)
{
 PORTD=a;
 PORTC=0X03;      
 delay();
 PORTC=0X01;      
    
}
void display(const char *a)
{
    while(*a!='\0'){
        data(*a);
        a++;
    }
}
void init_ports(){
    DDRC=0XFF;
    DDRD=0XFF;
    DDRB=0X0F;
     
}
void init_lcd(){
    command(0X01);
    command(0X38);
    command(0X06);
    command(0X0E);
    command(0X80);
}
int main(void) {
    init_ports();
    init_lcd();
    TCCR0=0X6D;
    int count=0;
    
    while (1) {
        while(1){
            command(0x80);
            display("Press Button\n\r");
        if((PINB&0x80)==0){
            count++;
            if(count>3){
                count=0;
            }
            while((PINB&0x80)==0);
            break;
        }
        
                    }

        
          
          switch(count){
              
              case 1:
                  command(0x01);
                  command(0xC0);
                  OCR0=64;
                  display("25%");
                  command(0X80);
                  
                  break;
              case 2:
                  command(0x01);
                  command(0xC0);
                  OCR0=128;
                  display("50%");
                  command(0X80);
                  break;
                  
              case 3:
                  command(0x01);
                  command(0xC0);
                  OCR0=192;
                  display("75%");
                  command(0X80);
                  break;
//              default:
//                  TCCR0=0X6D;
//                  OCR0=256;
//                  display("press button");
//                  command(0x80);
//                  break;
                  
          
      }  
        
    }
}
