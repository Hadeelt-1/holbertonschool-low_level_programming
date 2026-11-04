#include <stdio.h>
#include <math.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long int n, f, largest;

	n = 612852475143;
	largest = 0;
	f = 2;
	while (f <= n / f)
	{
		if (n % f == 0)
		{
			largest = f;
			n = n / f;
		}
		else
			f++;
	}
	if (n > largest)
		largest = n;
	printf("%ld\n", largest);
	return (0);
}
