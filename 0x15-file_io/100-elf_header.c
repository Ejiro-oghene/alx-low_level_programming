#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


/**
 * print_error - prints error message and exits with status code 98
 * @message: error message to print
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}


/**
 * print_elf_header - prints the information contained in ELF header
 * @header: Pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	const char *class_str = (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" :
		(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "Invalid class";
	printf("Class: %s\n", class_str);

	const char *data_str = (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
		"2's complement, little endian" :
		(header->e_ident[EI_DATA] == ELFDATA2MSB) ?
		"2's complement, big endian" : "Invalid data encoding";
	printf("Data: %s\n", data_str);

	printf("Version: %d\n", header->e_ident[EI_VERSION]);

	const char *osabi_str;

	switch (header->e_ident[EI_OSABI])
	case ELFOSABI_SYSV: osabi_str = "UNIX - System V";
			    break;
	case ELFOSABI_HPUX: osabi_str = "HP-UX";
			    break;
	case ELFOSABI_NETBSD: osabi_str = "NetBSD";
			      break;
	case ELFOSABI_LINUX: osabi_str = "Linux";
			     break;
	case ELFOSABI_SOLARIS: osabi_str = "Solaris";
			       break;
	case ELFOSABI_FREEBSD: osabi_str = "FreeBSD";
			       break;
	default: osabi_str = "Unknown";
		 break;

		 printf("OS/ABI: %s\n", osabi_str);

		 printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

		 printf("Type: %d\n", header->e_type);
		 printf("Entry point address: %lx\n", header->e_entry);
}


/**
 * main - entry point of the program
 * @argc: numb of command-line argument
 * @argv: array of command-line argument strings
 *
 * Return: On success 0, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	const char *filename = argv[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open the file");
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Failed to read ELF header");

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3) {
		print_error("Not an ELF file");
	}

	print_elf_header(&header);

	close(fd);

	return (0);
}
