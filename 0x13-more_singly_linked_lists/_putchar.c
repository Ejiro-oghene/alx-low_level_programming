#include "lists.h"
#include <unistd.h>

/**
 * _putchar - Writes the char. c to stdout.
 * @c: Char. to print.
 *
 * Return: Always 1 on success.
 * On error, -1 is returned, and errno is set correctly.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
