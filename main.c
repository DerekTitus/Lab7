#include <msp430.h> 
#include "RobotSensors.h"
/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    P1DIR |= BIT0|BIT6;
    P1OUT &= ~(BIT0|BIT6);

    initSensors();

    while(1)
    {
    	initLeftSensor();
    	if (initLeftSensor() >= 0x220){
    		P1OUT |= 0x01;}
    	else{
    		P1OUT &= ~0x01;}

    }
}
