/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: aya ashraf
 *
 *******************************************************************************/


#include "lm35_sensor.h"
#include "adc.h"
#include <util/delay.h>

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemp(void)
{
	uint8 temp_value=0;

	/* Read ADC channel where the temperature sensor is connected */
	ADC_read(LM_SENSOR_CHANNEL);
	_delay_ms(5);

	/* Calculate the temperature from the ADC value*/
	temp_value=(uint8)(((uint32)(g_adcResult * ADC_REF_VOLT_VALUE * LM_SENSOR_MAX_TEMP)) / (LM_SENSOR_MAX_VOLTAGE * ADC_MAXIMUM_VALUE));

	return temp_value;
}
