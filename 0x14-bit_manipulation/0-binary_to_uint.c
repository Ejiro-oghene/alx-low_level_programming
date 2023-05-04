#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


/**
 * binary_to_uint - change a binary number to an unsigned integer.
 *
 * @b: pointer to string containing the binary num.
 *
 * Return: converted number, or 0 if there is one or more chars in
 *         string b that is not 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		exit(EXIT_FAILURE);

	for (; *b; b++)
	{
		if (*b == '0')
			result <<= 1; /* Shift left by 1 bit */
		else if (*b == '1')
			result = (result << 1) | 1; /* Shift left by 1 bit and OR with 1 */
		else
			return (0 /* Invalid character, return 0 */);
	}

	return (result);
}
