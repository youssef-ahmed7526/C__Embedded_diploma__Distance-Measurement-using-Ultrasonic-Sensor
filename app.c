/*
 ================================================================================================
 Name        : app.c
 Author      : Youssef Ahmed
 Description : mini-project4
 Date        : 12/10/2021
 ================================================================================================
 */

#define F_CPU 8000000UL
#include "lcd.h"
#include "icu.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	uint16 distance=0;
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	/* Initialize the LCD driver */
	LCD_init();
	/* Display the string ("Distance=    cm") only once on LCD at the first row */
	LCD_displayString("Distance=    cm");
	while(1)
	{
		/* get the distance value from the ULTRASONIC */
		distance=Ultrasonic_readDistance();
		/* Display the distance value every time at same position*/
		LCD_moveCursor(0,10);
		if(distance >= 100)
				{
					LCD_intgerToString(distance);
				}
				else
				{
					LCD_intgerToString(distance);
					/* In case the digital value is two or one digits print space in the next digit place */
					LCD_displayCharacter(' ');
				}
		/* over 60ms measurement cycle, in order to prevent trigger signal to the echo signal */
		_delay_ms(70);
	}
}
