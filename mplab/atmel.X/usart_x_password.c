/*
 * File:   usart x password.c
 * Author: Administrator
 *
 * Created on May 21, 2024, 1:55 PM
 */

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>

char password[4]="0000";                   //declaring password

 
 void transmitter(char c){               //TX
	 UDR=c;
	   while((UCSRA&0x40)==0);
	   
	   UCSRA=0x40;
		   
	 }
char reciever(){                         //RX
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
		char c,enteredpassword[4];
        int i;
        for(i=0;i<4;i++){
            c=reciever();
		    transmitter(c);
            enteredpassword[i]=c;
        }
        
            if(i == 4){ 
                enteredpassword[5] = '\0'; 
//                display(enteredpassword);
                if(strcmp(enteredpassword, password) == 0){
                    display("Access granted"); 
                   
                    
                } else {
                    display("Access denied");  
                }
            
        }
        
        
			
    }
    return 0;
	
}
