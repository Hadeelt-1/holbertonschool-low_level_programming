#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * error_exit - prints an error message to stderr and exits with 98
 * @msg: the error message
 * @file: the file name
 */
void error_exit(char *msg, char *file)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", msg, file);
	exit(98);
}

/**
 * print_magic - prints the magic numbers of the ELF header
 * @buf: the ELF header
 */
void print_magic(unsigned char *buf)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", buf[i]);
		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class_data_version - prints the class, data and version
 * @buf: the ELF header
 */
void print_class_data_version(unsigned char *buf)
{
	printf("  %-35s", "Class:");
	if (buf[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (buf[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (buf[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else
		printf("<unknown: %x>\n", buf[EI_CLASS]);

	printf("  %-35s", "Data:");
	if (buf[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (buf[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else if (buf[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else
		printf("<unknown: %x>\n", buf[EI_DATA]);

	printf("  %-35s", "Version:");
	if (buf[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", buf[EI_VERSION]);
	else
		printf("%d\n", buf[EI_VERSION]);
}

/**
 * print_osabi - prints the OS/ABI and the ABI version
 * @buf: the ELF header
 */
void print_osabi(unsigned char *buf)
{
	printf("  %-35s", "OS/ABI:");
	switch (buf[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", buf[EI_OSABI]);
	}
	printf("  %-35s%d\n", "ABI Version:", buf[EI_ABIVERSION]);
}

/**
 * print_type - prints the type of the ELF file
 * @buf: the ELF header
 */
void print_type(unsigned char *buf)
{
	unsigned int type;

	if (buf[EI_DATA] == ELFDATA2MSB)
		type = (buf[16] << 8) | buf[17];
	else
		type = (buf[17] << 8) | buf[16];

	printf("  %-35s", "Type:");
	if (type == ET_NONE)
		printf("NONE (None)\n");
	else if (type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown>: %x\n", type);
}

/**
 * print_entry - prints the entry point address
 * @buf: the ELF header
 */
void print_entry(unsigned char *buf)
{
	unsigned long entry = 0;
	int i, size;

	size = (buf[EI_CLASS] == ELFCLASS64) ? 8 : 4;
	for (i = 0; i < size; i++)
	{
		if (buf[EI_DATA] == ELFDATA2MSB)
			entry = (entry << 8) | buf[24 + i];
		else
			entry |= (unsigned long)buf[24 + i] << (8 * i);
	}
	printf("  %-35s0x%lx\n", "Entry point address:", entry);
}

/**
 * main - displays the information in the ELF header of a file
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success, exits with 98 on error
 */
int main(int ac, char **av)
{
	int fd;
	ssize_t r;
	unsigned char buf[64];

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_exit("Can't open file", av[1]);
	r = read(fd, buf, 64);
	if (r < 32)
		error_exit("Can't read file", av[1]);
	if (buf[0] != 0x7f || buf[1] != 'E' || buf[2] != 'L' || buf[3] != 'F')
		error_exit("Not an ELF file:", av[1]);

	printf("ELF Header:\n");
	print_magic(buf);
	print_class_data_version(buf);
	print_osabi(buf);
	print_type(buf);
	print_entry(buf);

	if (close(fd) == -1)
		error_exit("Can't close fd for", av[1]);
	return (0);
}
