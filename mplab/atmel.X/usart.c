/*
 * File:   usart.c
 * Author: Administrator
 *
 * Created on May 20, 2024, 2:13 PM
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

 void transmitter(char c){
	 UDR=c;
	   while((UCSRA&0x40)==0);
	   
	   UCSRA=0x40;
		   
	 }
char reciever(){
	while((UCSRA&0x80)==0);
	return (UDR);
}
void display(const char *str)
{
	while(*str!='\0')
	{
		transmitter(*str);
		str++;
	}
}
void init(){
	DDRD = 0x02;
	UCSRB=0X18;
	UCSRC=0X86;
	UBRRL=51;
}


int main(void)
{
	init();
	
	
    while (1) 
    {
		char c;
		c=reciever();
		transmitter(c);	
    }
	
}

