/**
 * @file adc_utils.c
 * @brief biblioteka koja definise osnovne funkcije za rad sa AD konvertorom
 * @author Anja Tanovic
 * @version 1.0
 */

#include "adc_utils.h"

void InitADC(unsigned char reference, unsigned char division_factor)
{
	SetVref(reference);
	SetPrescaler(division_factor);
	SetEnable(1);
}

/*****************************************************************************/

unsigned int ReadADC(unsigned char channel)
{
	//postavljanje kanala za citanje
	SetChannel(channel);
	//Pokretanje konverzije  i cekanje dok se ona ne izvrsi
	RunConversion();

	unsigned int procitano = 0; //treba inicijalizovati
	//procita ADCH i pomeri levo (da to budu gornji biti) i na donja mesta doda ADCL
	procitano = ShiftLeft(ADCH, 8) + ADCL;

	/*
	unsigned int cuvanje;
	unsigned char i;

	unsigned char pomocna = 7; //pocinje se citanje od MSB
	for (i = 0; i < 8; i++)
	{
		//cita bit iz registra i sacuva u pomocnoj promenljivoj cuvanje
		cuvanje = CheckBit(ADCH,pomocna);
		//rezultat je na lsb mestu, treba ga pomeriti na njegovo pravo mesto
		ShiftLeft(cuvanje,pomocna);
		//dodaje se taj bit na glavnu promenljivu
		procitano+=cuvanje;
		//smanjuje se pomocna, cita se nizi bit svaki put
		pomocna--;
	}
	pomocna = 7; //pocinje se citanje od MSB ponovo
	for (i = 0; i < 8; i++)
	{
		//cita bit iz registra i sacuva u pomocnoj promenljivoj cuvanje
		cuvanje = CheckBit(ADCL,pomocna);
		//rezultat je na lsb mestu, treba ga pomeriti na njegovo pravo mesto
		ShiftLeft(cuvanje,pomocna);
		//dodaje se taj bit na glavnu promenljivu
		procitano+=cuvanje;
		//smanjuje se pomocna, cita se nizi bit svaki put
		pomocna--;
	}
	*/

	return procitano;
}

/*****************************************************************************/

void SetVref(unsigned char reference)
{
	/*
	 * reference ovde predstavlja bite koji trebaju da se
	 * postave u ADMUX registar
	 * oni se postavljaju pomocu pomocnih promenljivih da bi
	 * se izmenila samo 2 MSB bita unutar tog registra
	 */
	unsigned char bit_num7 = CheckBit(reference, 7);
	unsigned char bit_num6 = CheckBit(reference, 6);

	if (bit_num7)
		ADMUX = SetBit(ADMUX,7);
	else
		ADMUX = ClearBit(ADMUX,7);

	if (bit_num6)
		ADMUX = SetBit(ADMUX, 6);
	else
		ADMUX = ClearBit(ADMUX,6);
}

/*****************************************************************************/

void SetPrescaler(unsigned char division_factor)
{
	/*
	 * preskaler se podesava u ADCSR registru, na prva 3 LSB bita
	 * potrebno je setovati ili resetovati potrebne bite
	 */

	//division_factor je ustvari maska za setovanje
	ADCSRA = BitmaskSet(ADCSRA,division_factor);

	//masku za resetovanje je potrebno napraviti (invertovana maska za setovanje i uklonjeno prvih 5 bita)
	unsigned char mask_r = And(Not(division_factor), 0x07);
	ADCSRA = BitmaskClear(ADCSRA,mask_r);

	/*  drugi nacin:
	prvo obrise poslednja 3 bita
	 ADCSRA = BitmaskClear(ADCSRA, 0x07);
	onda samo setuje na jedinicu one bite koji pisu u division faktoru
	 ADCSRA = BitmaskSet(ADCSRA, division_factor);
	*/

}

/*****************************************************************************/

void SetEnable(unsigned char enable)
{
	/*
	 * enable treba postaviti na 1 u ADCSR registru
	 */
	if (enable == 1)
		ADCSRA = SetBit(ADCSRA,7);
	else
		ADCSRA = ClearBit(ADCSRA,7);
}

/*****************************************************************************/

void SetChannel(unsigned char channel)
{
	/*
	 * kanal se bira u ADMUX registru pomocu 3 LSB bita
	 */

	//channel je ustvari maska za setovanje
	ADMUX = BitmaskSet(ADMUX,channel);

	//masku za resetovanje je potrebno napraviti (invertovana maska za setovanje i uklonjeno prvih 3 bita)
	unsigned char mask_r = And(Not(channel), 0x1f);
	ADMUX = BitmaskClear(ADMUX,mask_r);

	/* drugi nacin
	prvo se obrise poslednjih 5 bita (za kanal)
	 ADMUX = BitmaskClear(ADMUX, 0x1f);
	onda se setuju oni biti koji trebaju
	ADMUX = BitmaskSet(ADMUX, And(channel, 0x1f));
	*/
}

/*****************************************************************************/

void RunConversion()
{
	//Start conversion
	ADCSRA = SetBit(ADCSRA, 6);

	//Proverava da li se konverzija zavrsila
	while(CheckBit(ADCSRA, 4) == 0)
	;
}
