/*
 * File:   usart_hw_atmega32.c
 * Author: Administrator
 *
 * Created on May 30, 2024, 2:38 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
Transmitter(char c){
    UDR = c ;
    while((UCSRA&0x40)==0);
    UCSRA=0x40;
}
Reciever(){
    while((UCSRA&0x80)==0);
    return(UDR);
}
display(const char *str){
    while(*str!='\0'){
        Transmitter(*str);
        str++;
    }
}
init_ports(){
    DDRA=0x00;
    DDRD=0x02;
    UCSRB=0x18;
    UCSRC=0x86;
    UBRRL=51;
}
int main(void) {
    
    while (1) {
        init_ports();
	
	
    while (1) 
    {
		char c;
		c=Reciever();
		Transmitter(c);	
    }
    }
}
