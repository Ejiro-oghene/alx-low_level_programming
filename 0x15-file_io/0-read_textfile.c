#include "main.h"
#include <stdlib.h>



/**
 * read_textfile - reads a text file & prints to the POSIX standard output
 * @filename: the file to read
 * @letters: numb of letters to read and print.
 *
 * Return: w- the actual numb of letters read and printed,
 * 0 on failure or filename is NULl
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
