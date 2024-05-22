/*
 * File:   lcd.c
 * Author: Administrator
 *
 * Created on May 16, 2024, 4:04 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
void command(char a){
    PORTD=a;
    PORTC=0X02;      //pc1=1   enable
    _delay_ms(500);
    PORTC=0X00;      //pc=0
}
void data(char a)
{
 PORTD=a;
 PORTC=0X03;      //pc1=1   enable
 _delay_ms(500);
 PORTC=0X01;      //pc=0
    
}
void display(const char *a)
{
    while(*a!='\0'){
        data(*a);
        a++;
    }
}
int main(void) {
     DDRC=0XFF;
     DDRD=0XFF;
        while (1)
        {
        
    
        
        command(0X01);
        command(0X38);
        command(0X06);
        command(0X0E);
        command(0X80);
        display("hello");
        }
        return ;
}
