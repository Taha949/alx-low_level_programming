#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: pointer to pointer to char
 * @argv: an int
 * Return: 0
 */

int main(int argc, char **argv)
{
	int sum, compteur;
	unsigned int i;
	char *p;
	int cents[] = {25, 10, 5, 2};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	sum = strtol(argv[1], &p, 10);
	compteur = 0;

	if (!*p)
	{
		while (sum > 1)
		{
			for (i = 0; i < sizeof(cents[i]); i++)
			{
				if (sum >= cents[i])
				{
					compteur += sum / cents[i];
					sum = sum % cents[i];
				}
			}
		}
		if (sum == 1)
			compteur++;
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", compteur);
	return (0);
}

