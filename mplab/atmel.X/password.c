/*
 * File:   password.c
 * Author: Administrator
 *
 * Created on May 20, 2024, 12:50 PM
 */




#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
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
void data(char data)
{
 PORTD=data;
 PORTC|=(1<<PC0);    //RS=1
 PORTC|=(1<<PC1);   //E=1
 delay;
 PORTC&=~(1<<PC1);   //E=0      
    
}
void display(const char *str)
{
    while(*str!='\0'){
        data(*str);
        str++;
    }
}
char read_key(){
    char key='\0';
    const char key_map[4][4]={
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
    };
    
    for(uint8_t col=0;col<4;col++){
        PORTB=~(1<<col);                 //set 1 coloumn low
        for(uint8_t row=0;row<4;row++){
            if(!(PINB&(1<<(row+4)))){
                key=key_map[row][col];
                while(!(PINB&(1<<(row+4))));  //wait until key is released
            }
        }
        
    }
    return key;
    
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
    
      
    char password[] = "1234"; // Set your password here
    char enteredPassword[5];  // Array to store the entered password
    uint8_t passwordIndex = 0; // Index to keep track of which character of the password is being entered
    
    while(1){
        char key=read_key();
        
        if(key!='\0'){
            
            data('*'); // Display '*' on LCD for each key press
            
            // Store the entered character in the enteredPassword array
            enteredPassword[passwordIndex++] = key;
            
            // Check if the entered password matches the expected password
            if(passwordIndex == 4){ // Check when the password length reaches 4
                enteredPassword[4] = '\0'; // Null terminate the entered password string
                
                if(strcmp(enteredPassword, password) == 0){
                    display("Access granted"); // Display "Access granted" if the passwords match
                } else {
                    display("Access denied");  // Display "Access denied" if the passwords do not match
                }
                
                // Reset variables for the next attempt
                _delay_ms(2000); // Delay to show the result for 2 seconds
                command(0x01);   // Clear the LCD
                passwordIndex = 0; // Reset password index
            }
        }
        
    } 
    return 0;
}