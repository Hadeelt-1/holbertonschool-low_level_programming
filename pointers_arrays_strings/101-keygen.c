#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a valid password for the 101-crackme program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	int n = 0;
	int target_sum = 2772;

	srand(time(NULL));

	while (sum < target_sum - 126)
	{
		n = rand() % 94 + 33;
		sum += n;
		putchar(n);
	}

	if (sum < target_sum)
	{
		n = target_sum - sum;
		putchar(n);
	}

	return (0);
}
