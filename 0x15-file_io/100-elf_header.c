#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


/**
 * display_error - display error message and exit with status code 98.
 * @message: error message to be displayed.
 */
void display_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * display_elf_header - display information
 *                      contained in the ELF header.
 * @header: pointer to the ELF header structure.
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\nClass:         %s\n", (header->e_ident[EI_CLASS]
				== ELFCLASS64) ? "ELF64" : "ELF32");
	printf("Data:          %s\n", (header->e_ident[EI_DATA]
				== ELFDATA2MSB) ? "2's complement, big endian"
			: "2's complement, little endian");
	printf("Version:       %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("OS/ABI:        %s\n", (header->e_ident[EI_OSABI]
				== ELFOSABI_SYSV) ? "UNIX System V ABI" : "Others");
	printf("ABI Version:   %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:          %d\n", header->e_type);
	printf("Entry point address:   0x%lx\n", header->e_entry);
}


/**
 * main - entry point of the program
 * @argc: number of command-line argument.
 *
 * @argv: array of command-line argument strings
 * Return: On success 0, on error 98.
 */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		display_error("Usage: elf_header elf_filename");

	filename = argv[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		display_error("Failed to open file");
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		display_error("Failed to read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
		display_error("Not an ELF file");

	display_elf_header(&header);

	close(fd);
	return (0);
}
