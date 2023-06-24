#include "main.h"
/**
 * *_strcpy - fentry point
 * @dest: destination
 * @src: source
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int len;
	int i;

	for (len = 0; src[len] != '\0'; len++)
	{
	}

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
