#include "main.h"
#include <unistd.h>


/**
 * _putchar - writes the char C to stdout.
 * @c: char to print
 *
 * Return: 1 on success.
 * On error, -1 is returned and error is set correctly
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
