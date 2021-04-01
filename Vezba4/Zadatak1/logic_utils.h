/**
 * @file logic_utils.h
 * @brief biblioteka koja deklarise pomocne funkcije (cesto koriscene
 * logicke operacije)
 * @author Anja Tanovic
 * @version 1.0
 */

#ifndef LOGIC_UTILS_H_
#define LOGIC_UTILS_H_

/**
 * SetBit - Funkcija koja postavlja vrednost bita na 1 na poziciji bit_num u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned int, ona kojoj setujemo bit
 * @param bit_num - ulazna promenljiva tipa unsigned char, broj bita
 * @return - Vraca modifikovanu vrednost promenlive reg
 */
unsigned int SetBit(unsigned int reg, unsigned char bit_num);

/**
 * ClearBit - Funkcija koja postavlja vrednost bita na 0 na poziciji bit_num u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned int, ona kojoj resetujemo bit
 * @param bit_num - ulazna promenljiva tipa unsigned char, broj bita
 * @return - Vraca modifikovanu vrednost promenlive reg
 */
unsigned int ClearBit(unsigned int reg, unsigned char bit_num);

/**
 * ToggleBit - Funkcija koja postavlja vrednost bita na suprotnu od postojece na poziciji bit_num
 * u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned int, ona kojoj toglujemo bit
 * @param bit_num - ulazna promenljiva tipa unsigned char, broj bita
 * @return - Vraca modifikovanu vrednost promenlive reg
 */
unsigned int ToggleBit(unsigned int reg, unsigned char bit_num);

/**
 * CheckBit - Funkcija koja proverava vrednost bita na poziciji bit_num u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned int, ona kojoj proveravamo bit
 * @param bit_num - ulazna promenljiva tipa unsigned char, broj bita
 * @return - Vraca vrednost bita sa pozicije bit_num
 */
unsigned int CheckBit(unsigned int reg, unsigned char bit_num);

/**
 * BitMaskSet - Funkcija koja postavlja vrednost grupe bita na 1 na pozicijama maske u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned char, ona kojoj setujemo bite
 * @param mask - ulazna promenljiva tipa unsigned char, maska za bite
 * @return - Vraca modifikovanu vrednost promenljive reg
 */
unsigned char BitmaskSet(unsigned char reg, unsigned char mask);

/**
 * BitMaskClear - Funkcija koja postavlja vrednost grupe bita na 0 na pozicijama maske u promenljivoj reg
 * @param reg - ulazna promenljiva tipa unsigned char, ona kojoj resetujemo bite
 * @param mask - ulazna promenljiva tipa unsigned char, maska za bite
 * @return - Vraca modifikovanu vrednost promenljive reg
 */
unsigned char BitmaskClear(unsigned char reg, unsigned char mask);

/**
 * Not - Funkcija koja vrsi bitsku negaciju promenljive input
 * @param input - ulazna promenljiva tipa unsigned int na kojoj vrsimo negaciju bita
 * @return - Vraca rezultat operacije
 */
unsigned int Not(unsigned int input);

/**
 * And - Funkcija koja vrsi bitsko I nad promenljivama input1 i input 2
 * @param input1 - ulazna promenljiva tipa unsigned int, prvi ulaz u I kolo
 * @param input2 - ulazna promenljiva tipa unsigned int, drugi ulaz u I kolo
 * @return - Vraca rezultat operacije
 */
unsigned int And(unsigned int input1, unsigned int input2);

/**
 * Or - Funkcija koja vrsi bitsko ILI nad promenljivama input1 i input 2
 * @param input1 - ulazna promenljiva tipa unsigned int, prvi ulaz u ILI kolo
 * @param input2 - ulazna promenljiva tipa unsigned int, drugi ulaz u ILI kolo
 * @return - Vraca rezultat operacije
 */
unsigned int Or(unsigned int input1, unsigned int input2);

/**
 * Xor - Funkcija koja vrsi bitsko EKS-ILI nad promenljivama input1 i input 2
 * @param input1 - ulazna promenljiva tipa unsigned int, prvi ulaz u EKS-ILI kolo
 * @param input2 - ulazna promenljiva tipa unsigned int, drugi ulaz u EKS-ILI kolo
 * @return - Vraca rezultat operacije
 */
unsigned int Xor(unsigned int input1, unsigned int input2);

/**
 * ShiftLeft - Funkcija koja vrsi pomeranje u levo nad promenljivom input za num_of_shifts mesta
 * @param input - ulazna promenljiva tipa unsigned int, promenljiva koja se shiftuje
 * @param num_of_shifts - ulazna promenljiva tipa unsigned int, broj pomeranja u levo
 * @return - Vraca rezultat operacije
 */
unsigned int ShiftLeft(unsigned int input, unsigned int num_of_shifts);

/**
 * ShiftRight - Funkcija koja vrsi pomeranje u desno nad promenljivom input za num_of_shifts mesta
 * @param input - ulazna promenljiva tipa unsigned int, promenljiva koja se shiftuje
 * @param num_of_shifts - ulazna promenljiva tipa unsigned int, broj pomeranja u desno
 * @return - Vraca rezultat operacije
 */
unsigned int ShiftRight(unsigned int input, unsigned int num_of_shifts);

#endif /* LOGIC_UTILS_H_ */
