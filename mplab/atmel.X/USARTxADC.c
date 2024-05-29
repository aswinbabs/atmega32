/*
 * File:   USARTxADC.c
 * Author: Administrator
 *
 * Created on May 22, 2024, 2:31 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include<stdio.h>
delay(){
    _delay_ms(100);
}
transmitter(char tra){
    UDR=tra;
    while((UCSRA&0x40)==0);
    UCSRA = 0x40;
}
reciever(){
   while((UCSRA&0x80)==0);
   return(UDR);
}

display(const char *str){
    
    while(*str!='\0'){
        transmitter(*str);
        str++;
    }
    
    
}
init_ports(){
    DDRA=0X00;
    DDRD=0XFF;
    
    ADMUX=0X50;
    ADCSRA=0XC0;
    UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=51;
}


void main(){
    
    init_ports();
    char c[10];
    float voltage;
    int flag=0;
    int a;
    while(1){
        flag=a;
        ADCSRA=0XC0;    
        while((ADCSRA&0X40));     //while ADSC=1
        
        a=ADCL;
        a+=(ADCH<<8);
        voltage=(a*5)/1023.0;
        sprintf(c,"%0.2f\r\n",voltage);
        if(flag!=a){
           display(c);  
        }
    }
       
    
}