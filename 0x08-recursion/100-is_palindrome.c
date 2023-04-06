#include "main.h"
/**
 * _strlen_recursion - entry point
 * @s: char
 * Return: int
 */

int _strlen_recursion(char *s)
{
	if (s[0] != '\0')
		return (1 + _strlen_recursion(s + 1));

	return (0);
}

/**
 * pal_checker - entry point
 * @s: char
 * @i: int
 * @j: int
 * Return: 1 or 0
 */

int pal_checker(char *s, int i, int j)
{
	if (s[i] == s[j])
		if (i > j / 2)
			return (1);

		else
			return (pal_checker(s, i + 1, j - 1));

	else
		return (0);
}

/**
 * is_palindrome - entry point
 * @s: char
 * Return: 1 or 0
 */

int is_palindrome(char *s)
{
	return (pal_checker(s, 0, _strlen_recursion(s) - 1));
}

