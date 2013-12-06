/*
 * RobotSensors.c
 *
 *  Created on: Dec 4, 2013
 *      Author: C15Derek.Titus
 */


void initSensors()
{
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;			// SMCLK selected
}

void initLeftSensor()
{
	ADC10CTL0 &= ~ENC; //clear the ENC bit
	ADC10CTL1 = INCH_4;  //input A4
	ADC10AE0 |= BIT4;
	ADC10CTL0 |= ENC + ADC10SC; //sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);	//LPM0, ADC10_ISR will force exit
}

void initRightSensor()
{
	ADC10CTL0 &= ~ENC; //clear the ENC bit
	ADC10CTL1 = INCH_5; //input A5
	ADC10AE0 |= BIT5;
	ADC10CTL0 |= ENC + ADC10SC; //sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);
}

void initCenterSensor()
{
	ADC10CTL0 &= ~ENC; //clear ENC bit
	ADC10CTL1 = INCH_3; //input A3
	ADC10AE0 |= BIT3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);
}

void RightWall()
{

}



ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
  ADC10CTL1 = INCH_4;                       // input A4
  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
  P1DIR |= 0x01;                            // Set P1.0 to output direction

  for (;;)
  {
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
    if (ADC10MEM < 0x1FF)
      P1OUT &= ~0x01;                       // Clear P1.0 LED off
    else
      P1OUT |= 0x01;                        // Set P1.0 LED on
  }


