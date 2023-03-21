#include "main.h"
#include <stdio.h>

/**
 * _abs - rntry point
 *
 * @i: integer
 *
 * Return: absolute value
 */

int _abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (i * -1);
	_putchar('\n');
}
