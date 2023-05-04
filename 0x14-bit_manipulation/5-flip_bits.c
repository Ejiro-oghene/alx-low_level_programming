#include "main.h"


/**
 * flip_bits - returns the number of bits needed to be
 *             flipped to get from one num. to another
 * @n: the 1st numb.
 * @m: the second num.
 *
 * Return: number of bits that needs to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int number = n ^ m;
	unsigned int count = 0;

	while (number)
	{
		count += number & 1;
		number >>= 1;
	}

	return (count);
}
