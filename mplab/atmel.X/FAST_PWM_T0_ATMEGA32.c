/*
 * File:   FAST_PWM_T0_ATMEGA32.c
 * Author: Administrator
 *
 * Created on May 23, 2024, 2:41 PM
 */


#include <avr/io.h>

int main(void) {
    DDRB=0X0F;
    TCCR0=0X6D;
    OCR0=64;
    while (1);
}
