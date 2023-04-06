#include "main.h"

/**
 * check - entry point
 * @a: int
 * @b: int
 * Return: int
 */
int check(int a, int b)
{
	if (a * a == b)
		return (a);
	if (a * a > b)
		return (-1);
	return (check(a + 1, b));
}

/**
 * _sqrt_recursion - entry point
 * @n: int
 * Return: -1 or int
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}

