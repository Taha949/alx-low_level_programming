#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 * Description: last digit
 * Return: always 0
*/

int main(void)
{
	int n;
	double a;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	a = n % 10;
	if (n > 5)
		printf("Last digit of %d is %a and is greater than 5", n, a);
	if (n == 0)
		printf("Last digit of %d is %a and is 0", n, a);
	if (n < 6 && n != 0)
		printf("Last digit of %d is %a and is less than 6 and not 0", n, a);
	return (0);
}
