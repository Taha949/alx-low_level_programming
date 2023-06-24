#include "main.h"
/**
 * _strlen - entry point
 * @s: string
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;
	int len = 0;

	for (; s[i] != '\0'; i++)
	{
		len += 1;
	}

	return (len);
}
