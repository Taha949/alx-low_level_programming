#include "main.h"
#include <stdlib.h>

/**
 * _strdup - entry point
 * @str: pointer to char
 * Return: copy
 */
char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *prime;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	prime = (char *)malloc((sizeof(char) * len) + 1);
	if (prime == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		prime[i] = str[i];
	prime[len] = '\0';

	return (prime);
}
