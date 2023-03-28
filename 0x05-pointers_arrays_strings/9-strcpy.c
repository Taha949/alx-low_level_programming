#include "main.h"
/**
 * _strcpy - entry point
 * @dest: char to check
 * @src: char to check
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

