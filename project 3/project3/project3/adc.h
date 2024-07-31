/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Aya Ashraf
 *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.5
#define ADC_CHANNEL0 0b00000
#define ADC_CHANNEL1 0b00001
#define ADC_CHANNEL2 0b00010
#define ADC_CHANNEL3 0b00011
#define ADC_CHANNEL4 0b00100
#define ADC_CHANNEL5 0b00101
#define ADC_CHANNEL6 0b00110
#define ADC_CHANNEL7 0b00111

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern volatile uint16 g_adcResult;


/*******************************************************************************
 *                      Structures/Enums definition                                  *
 *******************************************************************************/

enum ADC_ReferenceVoltage{
	ADC_AREF, ADC_AVCC , ADC_internalVoltage =3
};

enum ADC_Prescaler{
	ADC_freq2 , ADC_freq2_2 , ADC_freq4,ADC_freq8 , ADC_freq16,ADC_freq32 ,ADC_freq64 ,ADC_freq128
};

typedef struct{
	enum ADC_ReferenceVoltage ref_volt ;
	enum ADC_Prescaler prescaler ;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_read(uint8 channel);


#endif /* ADC_H_ */
