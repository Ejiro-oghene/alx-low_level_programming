#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: 0 (success)
 */

int main(void)
{
	int lowerCase = 'a';

	while (lowerCase <= 'z')
	{
	if (lowerCase == 'e' || lowerCase == 'q')
	{
	lowercase += 1;
	}
	else
	{
	putchar(lowerCase);
	lowerCase += 1;
	}
	}
	putchar('\n')
	return (0);
}
