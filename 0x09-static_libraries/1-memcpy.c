#include "main.h"

/**
 * _memcpy - entry point
 * @n: to copy
 * @src: byte
 * @dest: byte
 * Return: pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

