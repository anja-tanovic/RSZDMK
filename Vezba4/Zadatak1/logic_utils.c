/**
 * @file logic_utils.c
 * @brief biblioteka koja definise pomocne funkcije (cesto koriscene
 * logicke operacije)
 * @author Anja Tanovic
 * @version 1.0
 */

#include "logic_utils.h"

unsigned int SetBit(unsigned int reg, unsigned char bit_num)
{
	reg |= 1 << bit_num; //setuje bit na bit_num poziciji
	return reg;
}

/*****************************************************************************/

unsigned int ClearBit(unsigned int reg, unsigned char bit_num)
{
	reg &= ~(1 << bit_num); //resetuje bit na bit_num poziciji
	return reg;
}

/*****************************************************************************/

unsigned int ToggleBit(unsigned int reg, unsigned char bit_num)
{
	reg ^=1 << bit_num; //invertuje bit na bit_num poziciji
	return reg;
}

/*****************************************************************************/

unsigned int CheckBit(unsigned int reg, unsigned char bit_num)
{
	// 1<<bit_num ce forsirati nule na svim ostalim mestima u AND operaciji
	unsigned int x;
	if ((reg & (1 << bit_num)) == 0)
		x = 0;
	else
		x = 1;
	return x;
}

/*****************************************************************************/

unsigned char BitmaskSet(unsigned char reg, unsigned char mask)
{
	reg |= mask;
	return reg;
}

/*****************************************************************************/

unsigned char BitmaskClear(unsigned char reg, unsigned char mask)
{
	reg &= ~mask;
	return reg;
}

/*****************************************************************************/

unsigned int Not(unsigned int input)
{
	return (~input);
}

/*****************************************************************************/

unsigned int And(unsigned int input1, unsigned int input2)
{
	return (input1 & input2);
}

/*****************************************************************************/

unsigned int Or(unsigned int input1, unsigned int input2)
{
	return (input1 | input2);
}

/*****************************************************************************/

unsigned int Xor(unsigned int input1, unsigned int input2)
{
	return (input1 ^ input2);
}

/*****************************************************************************/

unsigned int ShiftLeft(unsigned int input, unsigned int num_of_shifts)
{
	unsigned char i;
	for (i = 0; i < num_of_shifts; i++)
	{
		input <<= 1;
	}
	return input;
}

/*****************************************************************************/

unsigned int ShiftRight(unsigned int input, unsigned int num_of_shifts)
{
	input >>= num_of_shifts;
	return input;
}

