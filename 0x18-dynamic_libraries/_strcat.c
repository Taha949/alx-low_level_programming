#include "main.h"
/**
 * *_strcat - entry point
 * @dest: destination
 * @src: source
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (; dest[i] != '\0'; i++)
	{
	} /* get the length of the destination */

	for (; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
