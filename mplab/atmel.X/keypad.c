/*
 * File:   keypad.c
 * Author: Administrator
 *
 * Created on May 17, 2024, 2:43 PM
 */


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
void command(char a){                                      //EN   RS
    PORTD=a;                                            //   pc1 pc0
    PORTC=0X02;      //pc1=1   enable  pc0=0         0000 00  1    0
    _delay_ms(50);
    PORTC=0X00;      //pc1=0   enable_low   pco=0    0000 00  0    0
}                                                
                                                  // 7654 32  1    0  [ position ]
void data(char a)
{
 PORTD=a;
 PORTC=0X03;                                      // 0000 00  1    1
 _delay_ms(50);
 PORTC=0X01;                                      // 0000 00  0    1
    
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
     DDRB=0X0F;
     command(0X01);
        command(0X38);
        command(0X06);
        command(0X0E);
        command(0X80);
       
        while (1)
        {
        
            
            
            
            int i=0;
            
            PORTB=0x0E;                              //lane1
                
                if((PINB&(0x10))==0){
                       
                    display("0");
                    while((PINB&(0x10))==0);
                }
                
                else if((PINB&(0x20))==0){
                    display("1");
                    while((PINB&(0x20))==0);
                }
                else if((PINB&(0x40))==0){
                    display("2");
                    while((PINB&(0x40))==0);
                }
                else if((PINB&(0x80))==0){
                    display("3");
                    while((PINB&(0x80))==0);
                }
                
                
            
            
            
            
            
            
            PORTB=0X0D;                         //lane2
                
                if((PINB&(0x10))==0){
                        display("4");   
                     while((PINB&(0x10))==0);
               }
                
                else if((PINB&(0x20))==0){
                  display("5");
                    while((PINB&(0x20))==0);
                }
                else if((PINB&(0x40))==0){
                    display("6");
                    while((PINB&(0x40))==0);
                }
                else if((PINB&(0x80))==0){
                   display("7"); 
                   while((PINB&(0x80))==0);
                }
               
               
            
          
            PORTB=0X0B;                        //lane3
        
             if((PINB&(0x10))==0){
                    display("8"); 
                     while((PINB&(0x10))==0);
                }
                
                else if((PINB&(0x20))==0){
                    display("9");
                    while((PINB&(0x20))==0);
               }
                else if((PINB&(0x40))==0){
                    display("*");
                    while((PINB&(0x40))==0);
               }
                else if((PINB&(0x80))==0){
                    display("#");
                    while((PINB&(0x80))==0);
                }
                
            
            
            
            
            
            PORTB=0X07;                             //lane4
                
                 if((PINB&(0x10))==0){
                     display("a");   
                     while((PINB&(0x10))==0);
                }
                
                else if((PINB&(0x20))==0){
                    display("b");
                    while((PINB&(0x20))==0);
                }
               else if((PINB&(0x40))==0){
                    display("c");
                    while((PINB&(0x40))==0);
                }
                else if((PINB&(0x80))==0){
                    display("d");
                    while((PINB&(0x80))==0);
                }
       
        
        
       }
        return 0;
}
