/**
 * @file rand_mto.c
 * @brief biblioteka koja definise funkcije generisanja pseudoslucajnih
 * brojeva
 * @author Anja Tanovic
 * @version 1.0
 */

#include "rand_mto.h"

//promenljiva koja oznacava trenutno stanje registra
unsigned int current_state;

void InitRand(unsigned int seed)
{
	unsigned char bit15 = CheckBit(seed,15);
	current_state = UpdateState(seed, bit15);
	//current_state = seed;  moze sam ovo umesto gornja dva reda
}

/*****************************************************************************/

unsigned int Rand()
{
	unsigned int new_state;
	unsigned char bit;

	bit = GenerateNextBit(current_state);

	new_state = UpdateState(current_state, bit);

	return new_state;
}

/*****************************************************************************/

unsigned int RandRange(unsigned int min, unsigned int max)
{
	unsigned int new_state;

	/* Rand daje neki broj iz veceg opsega i onda se deli sa
	 * razlikom (tj kolicinom mogucih brojeva)
	 * rezultat toga je uvek 0, 1, 2 itd (u zavisnosti od opsega)
	 * na to se dodaje min da bi odatle krenulo
	 */
	new_state = Rand() % (max - min + 1) + min;

	return new_state;

}

/*****************************************************************************/

unsigned char GenerateNextBit(unsigned int current_state)
{
	unsigned char new_bit;

	unsigned char bit0=CheckBit(current_state,0);
	unsigned char bit2=CheckBit(current_state,2);
	unsigned char bit3=CheckBit(current_state,3);
	unsigned char bit5=CheckBit(current_state,5);

	new_bit = Xor(bit5,Xor(bit3,Xor(bit2,bit0)));
	new_bit = And(new_bit, 0x01); // da se izoluje sam bit na lsb poziciji
							      //  kasnije ga treba staviti na MSB poziciju

	return new_bit;
}

/*****************************************************************************/

unsigned int UpdateState(unsigned int state, unsigned char bit)
{
	// novo stanje se dobija tako sto se prvo pomeri sadrzaj udesno za jedno mesto
	unsigned int new_state = ShiftRight(state, 1);

	//zatim se na MSB mesto postavlja novi bit (iz XOR kola dobijen)
	if (bit == 0)
		new_state = ClearBit(new_state,15);
	else
		new_state = SetBit(new_state,15);

	// novo stanje treba sacuvati kao sadasnje, sledeci put se ono menja
	current_state = new_state;
	return new_state;
}
