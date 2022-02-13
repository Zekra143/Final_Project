/*
 * LCD_LayeredArch_E25.c
 *
 * Created: 11/5/2021 2:09:59 PM
 * Author : user
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "DIO.h"
#include "LCD.h"

int main() {
	// Timer 2 config
	/*set fast PWM mode with non-inverted output*/
	TCCR2 = (1 << WGM20) | (1 << WGM21) | (1 << COM21) | (1 << CS20);// no prescaling 

	OCR2 = 20;//???? ???? ??? ??? ??? 255 ????? ??? ?? ?????? ??DUTY CY ?????? ??? %
	unsigned int a, b, c, high, period;
	char frequency[14], duty_cy[7];

	DIO_Init();
	LCD_Init();
	PORTD = 1 << 6; /* Turn ON pull-up resistor */

	while (1) 
	{
		TCCR1A = 0;
		TCNT1 = 0;
		TIFR = (1 << ICF1); /* Clear ICF (Input Capture flag) flag */

		TCCR1B = 0x41; /* Rising edge, no prescaler */
		while ((TIFR & (1 << ICF1)) == 0)// set all bits to 0  except bit number IFC
			;
		a = ICR1; /* Take value of capture register */
		TIFR = (1 << ICF1); /* Clear ICF flag */

		TCCR1B = 0x01; /* Falling edge, no prescaler */
		while ((TIFR & (1 << ICF1)) == 0)
			;
		b = ICR1; /* Take value of capture register */
		TIFR = (1 << ICF1); /* Clear ICF flag */

		TCCR1B = 0x41; /* Rising edge, no prescaler */
		while ((TIFR & (1 << ICF1)) == 0)
			;
		c = ICR1; /* Take value of capture register */
		TIFR = (1 << ICF1); /* Clear ICF flag */

		TCCR1B = 0; /* Stop the timer */

		if (a < b && b < c) /* Check for valid condition,
		 to avoid timer overflow reading */
		{
			high = b - a;
			period = c - a;

			long freq = F_CPU / period;/* Calculate frequency */

			/* Calculate duty cycle */
			float duty_cycle = ((float) high / (float) period) * 100;
			ltoa(freq, frequency, 10);

			itoa((int) duty_cycle, duty_cy, 10);

			LCD_Cmd(0x80);
			LCD_String("Freq: ");
			LCD_String(frequency);
			LCD_String(" Hz ");

			LCD_Cmd(0xC0);
			LCD_String("Duty: ");
			LCD_String(duty_cy);
			LCD_String(" % ");

		}

		else {
			LCD_Cmd(0x01);
			LCD_String("OUT OF RANGE!!");
		}
		_delay_ms(50);
	}

}
