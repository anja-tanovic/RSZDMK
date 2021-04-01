/**
 * @file adc_utils.h
 * @brief biblioteka koja deklarise osnovne funkcije za rad sa AD konvertorom
 * @author Anja Tanovic
 * @version 1.0
 */

#ifndef ADC_UTILS_H_
#define ADC_UTILS_H_

#include <avr/io.h>
#include "logic_utils.h"

/**
 * InitADC - Funkcija koja vrsi inicijalizaciju ADC na osnovu prosledjenih parametara
 * @param reference - ulaz tipa unsigned char, referentni napon
 * @param division_factor - ulaz tipa unsigned char, faktor skaliranja
 * @return - Nema povratnu vrednost
 */
void InitADC(unsigned char reference, unsigned char division_factor);

/**
 * ReadADC - Funkcija koja cita vrednost sa kanala channel na ADC
 * @param channel - ulaz tipa unsigned char, kanal sa kojeg se cita
 * @return - Ocitana vrednost za izlaza ADC
 */
unsigned int ReadADC(unsigned char channel);

/**
 * SetVref - Funkcija koja postavlja vrednost referentnog napona u ADMUX
 * @param reference - ulaz tipa unsigned char, referentni napon
 * @return - Nema povratnu vrednost
 */
void SetVref(unsigned char reference);

/**
 * SetPrescaler - Funkcija koja postavlja vrednost preskalera u ADCSRA
 * @param division_factor - ulaz tipa unsigned char, faktor skaliranja
 * @return - Nema povratnu vrednost
 */
void SetPrescaler(unsigned char division_factor);

/**
 * SetEnable - Funkcija koja postavlja dozvolu rada ADC u ADCSRA
 * @param enable - ulaz tipa unsigned char, 1 dozvola, 0 zabrana
 * @return - Nema povratnu vrednost
 */
void SetEnable(unsigned char enable);

/**
 * SetChannel - Funkcija koja vrsi izbor ulaznog kanala ADC u ADMUX
 * @param channel - ulaz tipa unsigned char, ulazni kanal
 * @return - Nema povratnu vrednost
 */
void SetChannel(unsigned char channel);

/**
 * RunConversion - Funkcija koja izvrsava AD konverziju, pokrece je
 * i ceka na njen zavrsetak
 * @return - Nema povratnu vrednost
 */
void RunConversion();

#endif /* ADC_UTILS_H_ */
