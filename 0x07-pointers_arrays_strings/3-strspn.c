#include "main.h"

/**
 * _strspn - entry point
 * @s: dting
 * @accept: string
 * Return: number of bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	int b = 0;
	int a;
	int c;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a] != 32)
		{
			for (c = 0; accept[c] != '\0'; c++)
			{
				if (s[a] == accept[c])
					b++;
			}
		}
		else
			return (b);
	}
		return (b);

}

