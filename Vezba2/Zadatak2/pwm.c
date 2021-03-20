#include <avr/io.h>
#include <avr/interrupt.h>

unsigned long us = 0; //vreme
unsigned char jacina=150; //UNETI JACINU 0-255


ISR (TIMER0_COMPA_vect) {
	us ++; //svakih 10us se uveca za 1
		   //nakon cele periode imace vrednost 256
	if (us == 255)
		us = 0; //prosla je cela perioda, ispocetka broji

	if (us <jacina) //sto je ovde broj manji, to je osvetljenost manja
		PORTB |= 1<<5; //led on
	else
		PORTB &= ~(1<<5); //led off
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
	//prekidi se desavaju svakih 10us, i tada je mogucnost da se promeni signal (u tim trenucima
	//uticemo na faktor ispune
	//posto se desavaju prekidi svakih 10us, a perioda je zadata da je 2,56ms
	//to znaci da imamo 256 mogucih faktora ispune


	while(1);

	return 0;
}
