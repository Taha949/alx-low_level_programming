#include "main.h"

/**
 * _isalpha - Entry point
 *
 * @c: the character
 * Return: 1 0
 */

int _isalpha(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else
		return (0);
	_putchar('\n');
}
