#include <stdio.h>

/**
 * main - Finds and prints the sum of even-valued terms
 *        not exceeding 4,000,000, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long t1 = 1, t2 = 2, next = 0, sum = 2;

	while (next <= 4000000)
	{
		next = t1 + t2;
		if (next > 4000000)
		{
			break;
		}
		if (next % 2 == 0)
		{
			sum += next;
		}
		t1 = t2;
		t2 = next;
	}

	printf("%lu\n", sum);

	return (0);
}
