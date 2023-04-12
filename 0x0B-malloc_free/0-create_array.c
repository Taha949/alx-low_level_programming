#include "main.h"
#include <stdlib.h>

/**
 * create_array - entry point
 * @size: unsigned int
 * @c: char
 * Return: Null or tab
 */
char *create_array(unsigned int size, char c)
{
	unsigned char i;
	char *tab;

	if (size == 0)
		return (NULL);

	tab = (char *)malloc(sizeof(char) * size);
	if (tab == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		tab[i] = c;

	return (tab);
}
