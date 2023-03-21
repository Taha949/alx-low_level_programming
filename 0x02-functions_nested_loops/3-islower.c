#include "main.h"

/**
 * _islower - entry point
 * 
 * Return: 1  or 0
 */

int _islower(int c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else
		return (0);
	_putchar('\n');
}
