#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * main - entry point
 * @argc: an int
 * @argv: An array
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		return (97);
	}

	FILE *from_file = fopen(argv[1], "rb");
	if (!from_file)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	FILE *to_file = fopen(argv[2], "wb");
	if (!to_file)
	{
		fclose(from_file);
		fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}

	char buffer[BUFFER_SIZE];
	size_t num_read = 0;

	while ((num_read = fread(buffer, 1, BUFFER_SIZE, from_file)) > 0)
	{
		if (fwrite(buffer, 1, num_read, to_file) != num_read)
		{
			fclose(from_file);
			fclose(to_file);
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			return (99);
		}
	}

	if (ferror(from_file))
	{
		fclose(from_file);
		fclose(to_file);
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fclose(from_file);
	fclose(to_file);

	return (0);
}

