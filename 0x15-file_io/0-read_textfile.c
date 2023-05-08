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
	FILE *fp;
	char *buf;
	ssize_t nread;
	ssize_t nprinted;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
	{
		fclose(fp);
		return (0);
	}

	nread = fread(buf, sizeof(char), letters, fp);
	buf[nread] = '\0';

	nprinted = fwrite(buf, sizeof(char), nread, stdout);

	free(buf);
	fclose(fp);

	return (nprinted);
}

