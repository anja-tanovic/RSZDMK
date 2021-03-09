#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//treptanje f=2Hz
	DDRB |= 1 << 5; //PB5 je izlaz za diodu
	while(1) {
		PORTB |= 1<<5; //setovanje diode na 1 (led on)
		_delay_ms(500);
		PORTB &= ~(1<<5); //resetovanje diode na 0 (led off)
		_delay_ms(500);
	}
	return 0;
}


