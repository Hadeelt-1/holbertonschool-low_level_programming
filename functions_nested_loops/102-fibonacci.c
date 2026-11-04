#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers, starting with 1 and 2,
 *        followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long t1 = 1, t2 = 2, next;

	for (i = 1; i <= 50; i++)
	{
		if (i == 1)
		{
			printf("%lu", t1);
		}
		else if (i == 2)
		{
			printf(", %lu", t2);
		}
		else
		{
			next = t1 + t2;
			t1 = t2;
			t2 = next;
			printf(", %lu", next);
		}
	}
	printf("\n");

	return (0);
}
