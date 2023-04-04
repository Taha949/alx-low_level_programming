#include "main.h"

/**
 * _memset - entry point
 * @n: byte
 * @s: byte
 * @b: pointer
 * Return: a pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
	s[i] = b;
	i++;
	}

	return (s);
}
