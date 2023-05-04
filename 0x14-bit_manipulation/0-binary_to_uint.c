#include "main.h"
#include <stddef.h>


/**
 * binary_to_uint - change a binary number to an unsigned integer.
 *
 * @b: pointer to string containing 0 and 1 chars
 *
 * Return: converted number, or 0 if there is one or more chars in
 *         string b that is not 0 or 1, or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);
		n = (n << 1) + (*b++ - '0');
	}

	return (n);
}
