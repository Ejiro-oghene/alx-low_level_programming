#include "main.h"



/**
 * clear_bit - sets the value of a bit to zero at a given index
 * @n: pointer to the num.
 * @index: index of bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(unsigned long int) * 8 - 1)
		return (-1);

	*n &= ~(1ul << index);

	return (1);
}
