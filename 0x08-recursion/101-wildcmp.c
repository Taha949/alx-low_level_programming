#include "main.h"

/**
 * str_checker - entry point
 * @s1: char pointer
 * @s2: char pointer
 * @i: int
 * @j: int
 * Return: 1 or 0
 */

int str_checker(char *s1, char *s2, int i, int j)
{
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);

	if (s1[i] == s2[j])
		return (str_checker(s1, s2, i + 1, j + 1));

	if (s1[i] == '\0' && s2[j] == '*')
		return (str_checker(s1, s2, i, j + 1));

	if (s2[j] == '*')
		return (str_checker(s1, s2, i + 1, j) || str_checker(s1, s2, i, j + 1));

	return (0);
}

/**
 * wildcmp - entry point
 * @s1: pointer to char
 * @s2: pointer char
 * Return: 1
 */

int wildcmp(char *s1, char *s2)
{
	return (str_checker(s1, s2, 0, 0));
}

