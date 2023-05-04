#include "main.h"


/**
 * get_bit - Returns the value of bit at a given index
 * @n: num. to retrieve the bit from.
 * @index: index of bit to retrieve, starting from 0
 *
 * Return: the value of bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	return ((n >> index) & 1);
}
