#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - entry point
 * @filename: string
 * @letters: int
 * Return: a number
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

	FILE *file;
	size_t read_size;
	char *buffer;
	ssize_t write_size;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	read_size = fread(buffer, sizeof(char), letters, file);
	write_size = fwrite(buffer, sizeof(char), read_size, stdout);

	fclose(file);
	free(buffer);

	return (write_size);
}
