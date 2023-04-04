#include "main.h"

/**
 * _strpbrk - entry point
 * @s:first a char
 * @accept: char
 * Return:  pointer
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
		while (*s)
		{
			for (i = 0; accept[i]; i++)
			{
				if (*s == accept[i])
					return (s);
			}
			s++;
		}
	return (NULL);
}

