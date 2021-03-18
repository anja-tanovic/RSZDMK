#include <avr/io.h>
#include <avr/interrupt.h>


ISR (TIMER0_COMPA_vect) {

}

int main(void) {

	//inicijalizacija portova
	DDRB |= 1<<5; //PB5 izlaz (dioda)

	//inicijalizacija tajmera 0
	TCCR0A = 0x02; //tajmer 0: CTC mod
	TCCR0B = 0x01; //tajmer 0: No prescaling
	//gornja linija ni ne mora ako nema skaliranja
	OCR0A = 159; //perioda tajmera 0: 160 Tclk (OCR0A + 1 = 160)
	TIMSK0 = 0x02;

	sei();
	//prekidi se desavaju svakih 10us, i tada se pojacava faktor ispune


	while(1);
	return 0;
}
