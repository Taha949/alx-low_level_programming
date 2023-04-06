#include "main.h"
/**
 * _strlen_recursion - entry point
 * @s: string (the parametre)
 * Return: int i
 */
int _strlen_recursion(char *s)
{
	int i = 0;

	if (*s)
	{
		i += _strlen_recursion(s + 1);
		i++;

	}
	return (i);
}

