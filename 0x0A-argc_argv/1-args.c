#include <stdio.h>

/**
 * main - entry point
 * @argc: an int
 * @argv: pointer to pointer to char
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}

