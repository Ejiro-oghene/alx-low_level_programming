#include "main.h"


/**
 * print_binary - prints the binary rep. of a number
 * @n: the number to be changed and printed
 *
 * Return: void.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << 63;
	int flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag)
		{
			_putchar('0');
		}
		mask >>= 1;
	}
}
