#include "main.h"

/**
 * _islower - entry point
 * @c: character
 *
 * Return: 1 or 0
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z') /*if c is inclusively between a and z */
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
