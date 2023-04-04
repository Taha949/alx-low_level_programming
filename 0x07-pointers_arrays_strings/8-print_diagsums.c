#include "main.h"
/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer
 * @size: int
 * Return: rien
 */
void print_diagsums(int *a, int size)
{
	int i, j, p;
	int l = 0, r = 0;

	for (i = 0; i < size; i++)
	{
		p = i + (i * size) ;
		l = l + *(a + p);
	}
	for (j = 0; j < size; j++)
	{
		p = (j * size) + (size - 1 - j);
		r = r + *(a + p);
	}
	printf("%i, %i\n", l, r);
}

