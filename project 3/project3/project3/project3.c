/******************************************************************************
 *
 * Module: main
 *
 * File Name: project3.c
 *
 * Description: Fan Controller Project
 *
 * Author: Aya Ashraf
 *
 *******************************************************************************/


#include "adc.h"
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"


int main(void)
{
	uint8 temp;

	/*
	 * creating a structure of ADC_ConfigType
	 * using the external reference voltage by internal reference voltage 2.56 voltage
	 * ADC_Clock = F_CPU/8
	 */
	ADC_ConfigType config;
	config.ref_volt = ADC_internalVoltage;
	config.prescaler = ADC_freq8;

	/* initialize LCD driver */
	LCD_init();
	/* initialize DC Motor driver */
	DcMotor_Init();
	/* initialize ADC driver */
	ADC_init(&config);
	/* calling the clear the LCD function */
	LCD_clearScreen();
	/* Display this string on LCD at the first row , column 4 */
	LCD_displayStringRowColumn(0,4,"FAN is OFF");
	/* Display this string on LCD at the second row , column 4 */
	LCD_displayStringRowColumn(1,4,"Temp =    c");


	while(1)
	{
		/**/
		temp = LM35_GetTemp();
		/* Display the temperature value every time at same position */
		LCD_moveCursor(1,10);

		if(temp<10)
		{
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayString("  ");
            LCD_moveCursor(1,10);
		}


		if(temp < 30)
		{
			LCD_intgerToString(temp);
			LCD_displayStringRowColumn(0,4,"FAN is OFF");
			DcMotor_Rotate(DcMotor_stop,0);
		}
		else if(temp < 60)
		{
			LCD_displayStringRowColumn(0,4,"FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(DcMotor_CW,25);
		}
		else if(temp < 90)
		{
			LCD_displayStringRowColumn(0,4,"FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(DcMotor_CW,50);
		}
		else if(temp < 120)
		{
			LCD_displayStringRowColumn(0,4,"FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(DcMotor_CW,75);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_displayStringRowColumn(0,4,"FAN is ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(DcMotor_CW,100);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}





	}


}
