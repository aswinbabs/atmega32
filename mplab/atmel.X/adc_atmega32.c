/*
 * File:   adc_atmega32.c
 * Author: Administrator
 *
 * Created on May 21, 2024, 3:37 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>    // for sprintf
void delay(){
    _delay_ms(10);
}
void command(char cmd){
    PORTD=cmd;
    PORTC&=~(1<<PC0);     //RS=0
    PORTC|=(1<<PC1);     //E=1
    delay();
    PORTC&=~(1<<PC1);     //E=0     
}
void data(char a)
{
 PORTD=a;
 PORTC |= (1 << PC0) | (1 << PC1);

 _delay_ms(500);
 PORTC&=~(1<<PC1);     
    
}
void display(const char *str)
{
    while(*str!='\0'){
        data(*str);
        str++;
    }
}

void init_ports(){
    
    DDRA=0X00;
    DDRC=0XFF;
    DDRD=0XFF;
    ADMUX=0X50;
    ADCSRA=0XC0;
    
     
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
    
    while(1){
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
     
    return 0;
}