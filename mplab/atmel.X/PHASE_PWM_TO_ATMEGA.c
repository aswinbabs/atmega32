/*
 * File:   PHASE_PWM_TO_ATMEGA.c
 * Author: Administrator
 *
 * Created on May 27, 2024, 3:08 PM
 */


#include <avr/io.h>

int main(void) {
    DDRB=0X0F;
    TCCR0=0X65;
    OCR0=64;         //25% OF FULL PERIOD  (25% OF 256)
    while (1);
}
