/*
 * File:   atmega32_hw_adc.c
 * Author: Administrator
 *
 * Created on May 28, 2024, 4:30 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
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
void init_ports(){
    
    DDRA=0X00;
    DDRD=0XFF;
    DDRB=0XFF;
    ADMUX=0X50;
    ADCSRA=0XC0;
    
     
}
init_lcd(){
    command(0x01);
    command(0x38);
    command(0x06);
    command(0x0E);
    command(0x80);
}
int main(void) {
    init_ports();
    init_lcd();
    while (1) {
        
        ADCSRA=0XC0;    
        while((ADCSRA&0X40));     //while ADSC=1
        int a=ADCL;
        a+=(ADCH<<8);
        command(0x80);
        char c[10];
        float voltage;
        voltage=(a*5)/1023.0;
        sprintf(c,"%0.2f",voltage);
        
        display(c);
    }
}
