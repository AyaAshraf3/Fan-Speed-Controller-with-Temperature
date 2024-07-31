/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Aya Ashraf
 *
 *******************************************************************************/


#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the ADC Registers */

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult=0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
		 * REFS1:0 = ref_volt set in the structure to choose to connect external reference voltage by internal reference voltage 2.56 voltage
		 * ADLAR   = 0 right adjusted
		 * MUX4:0  = 00000 to choose channel 0 as initialization
		 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt << 6) & 0xC0);
	ADMUX = (ADMUX & 0xE0)| (ADC_CHANNEL0 & 0x1F );

	/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 0 Disable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = prescaler set in the structure to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
		 */
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr-> prescaler & 0x07);
}

void ADC_read(uint8 channel)
{
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX |= (ADMUX & 0xE0)| (channel & 0x1F );
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){}
	/* Clear ADIF by write '1' to it */
	SET_BIT(ADCSRA,ADIF);
	/* Read the digital value from the data register and save it in the global variable */
	g_adcResult= ADC;


}
