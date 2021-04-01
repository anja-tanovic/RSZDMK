/**
 * @file main.c
 * @brief AD konvertor
 * @author Anja Tanovic
 * @version 1.0
 */

#include "rand_mto.h"
#include "adc_utils.h"
#include "../pin_driver/pin.h"
#include "../timer_0/timer0.h"

///Makro za selektovanje kanala
#define CHANNEL 0x03

//Makroi kojim se odredjuje opseg pseudoslucajnih brojeva
#define MIN 2
#define MAX 8

//Makro za selektovanje pina za diodu
#define DIODE_PIN 5

//Makro za pauzu izmedju 2 treptaja
#define PAUZA1 300
//Makro za pauzu izmedju grupa treptaja
#define PAUZA2 2000

int main()
{

	unsigned int seed;
	unsigned int broj_treptaja = 0;
	unsigned char i;

	pinInit(PORT_B, DIODE_PIN, OUTPUT);
	timer0InteruptInit();
	//inicijalizacija reference (AVCC - 01) i preskalera (128)
	InitADC(ShiftLeft(0x01, 6), 0x07);

	seed = ReadADC(CHANNEL);
	InitRand(seed);

	while(1)
	{
		broj_treptaja = RandRange(MIN, MAX);
		//broj_treptaja = ReadADC(CHANNEL) % (MAX - MIN + 1) + MIN;

		for (i = 0; i < broj_treptaja; i++)
		{
			pinSetValue(PORT_B, DIODE_PIN, HIGH);
			timer0DelayMs(PAUZA1);
			pinSetValue(PORT_B, DIODE_PIN, LOW);
			timer0DelayMs(PAUZA1);
		}
		timer0DelayMs(PAUZA2);
	}

	return 0;
}
