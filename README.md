# Fan-Speed-Controller-with-Temperature
This project is designed to create a temperature-controlled fan using the ATmega32 microcontroller, with a focus on efficiency, precision, and real-time temperature management.
# Introduction
In this project, we've developed a sophisticated temperature-controlled fan system that offers precise control and automation. By utilizing an ATmega32 microcontroller, an LM35 temperature sensor, and other components, we've created a system that automatically adjusts the fan's speed based on the surrounding temperature.

Specifications
Here are the key specifications and features of the Fan Controller System:

Objective: Design a temperature-controlled fan using the ATmega32 microcontroller with a 1MHz clock frequency.

Temperature Sensing: The LM35 temperature sensor provides continuous analog output, which is then converted to digital values using the ADC.

Display: The system displays the temperature on an LCD screen for real-time monitoring.

Temperature-Dependent Fan Control:

Below 30°C: Fan is turned off.
30°C - 60°C: Fan operates at 25% of its maximum speed.
60°C - 90°C: Fan operates at 50% of its maximum speed.
90°C - 120°C: Fan operates at 75% of its maximum speed.
Above 120°C: Fan operates at 100% of its maximum speed.

PWM Control: The fan speed is precisely controlled using PWM signals generated from Timer0.

Layered Architecture: The project is designed with a layered architecture model, comprising:

HAL Layer: LCD, LM35, and DC motor drivers.
MCAL Layer: GPIO, ADC, and Timer0 PWM drivers.
