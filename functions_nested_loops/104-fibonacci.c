#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers, starting with 1 and 2,
 *        followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long f1_hi = 0, f1_lo = 1;
	unsigned long f2_hi = 0, f2_lo = 2;
	unsigned long next_hi, next_lo;

	printf("1, 2");

	for (i = 3; i <= 98; i++)
	{
		next_lo = f1_lo + f2_lo;
		next_hi = f1_hi + f2_hi;

		if (next_lo >= 1000000000)
		{
			next_hi += next_lo / 1000000000;
			next_lo %= 1000000000;
		}

		printf(", ");
		if (next_hi != 0)
			printf("%lu%09lu", next_hi, next_lo);
		else
			printf("%lu", next_lo);

		f1_hi = f2_hi;
		f1_lo = f2_lo;
		f2_hi = next_hi;
		f2_lo = next_lo;
	}
	printf("\n");

	return (0);
}
