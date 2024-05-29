/*
 * File:   atmega_hw_lcd.c
 * Author: Administrator
 *
 * Created on May 28, 2024, 3:53 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
delay(){
    _delay_ms(10);
}
void command(char a){
    PORTB=a;
    PORTD=0X40;      //  enable on
    delay();
    PORTD=0X00;      //off
}
void data(char a)
{
 PORTB=a;
 PORTD=0X60;      //pc1=1   enable
 delay();
 PORTD=0X20;      //pc=0
    
}
void display(const char *a)
{
    while(*a!='\0'){
        data(*a);
        a++;
    }
}
lcd_init(){
    command(0x01);
    command(0x38);
    command(0x06);
    command(0x0E);
    command(0x80);
}
int main(void) {
    DDRD=0xFF;
    DDRB=0xFF;
    lcd_init();
    display("Hello love!");
    while (1) {
        
    }
}
