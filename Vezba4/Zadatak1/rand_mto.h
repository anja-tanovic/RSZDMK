/**
 * @file rand_mto.h
 * @brief biblioteka koja deklarise funkcije generisanja pseudoslucajnih
 * brojeva
 * @author Anja Tanovic
 * @version 1.0
 */


#ifndef RAND_MTO_H_
#define RAND_MTO_H_

#include "logic_utils.h"
#include <avr/io.h>

/**
 * InitRand - funkcija koja inicijalizuje pocetko stanje generatora
 * @param seed - ulazna promenljiva tipa unsigned int, pocetno stanje LFSR
 * @return - Nema povratnu vrednost
 */
void InitRand(unsigned int seed);

/**
 * Rand - funkcija koja generise pseudoslucajan broj (16-bitan)
 * @return - Vraca generisanu 16-bitnu vrednost
 */
unsigned int Rand();

/**
 * RandRange - funkcija koja generise pseudoslucajan broj iz intervala min-max
 * @param min - ulazna promenljiva tipa unsigned int, minimalna granica intervala
 * @param max - ulazna promenljiva tipa unsigned int, maksimalna granica intervala
 * @return - Vraca generisanu 16-bitnu vrednost
 */
unsigned int RandRange(unsigned int min, unsigned int max);

/**
 * GenerateNextBit - funkcija koja generise narednu vrednost MSB
 * @param current_state - ulazna promenljiva tipa unsigned int, trenutno stanje LFSR
 * @return - Vraca generisanu vrednost MSB
 */
unsigned char GenerateNextBit(unsigned int current_state);

/**
 * UpdateState - funkcija koja generise novo stanje na osnovu trenutnog stanja i nove MSB
 * @param state - ulazna promenljiva tipa unsigned int, trenutno stanje LFSR
 * @param bit - ulazna promenljiva tipa unsigned char, nova vrednost MSB
 * @return - Vraca generisanu vrednost novog stanja (16-bita)
 */
unsigned int UpdateState(unsigned int state, unsigned char bit);

#endif /* RAND_MTO_H_ */
