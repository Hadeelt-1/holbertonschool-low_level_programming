#include <stdio.h>

/**
 * main - Entry point for the calculator program
 *
 * Return: Always 0
 */
int main(void)
{
	int choice = 0;
	double first, second;

	while (1)
	{
		printf("1) Addition\n");
		printf("2) Subtraction\n");
		printf("3) Multiplication\n");
		printf("4) Division\n");
		printf("5) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			break;
		}

		if (choice == 5)
		{
			break;
		}
		else if (choice >= 1 && choice <= 4)
		{
			printf("Enter first number: ");
			scanf("%lf", &first);
			printf("Enter second number: ");
			scanf("%lf", &second);

			if (choice == 1)
			{
				printf("Result: %f\n", first + second);
			}
			else if (choice == 2)
			{
				printf("Result: %f\n", first - second);
			}
			else if (choice == 3)
			{
				printf("Result: %f\n", first * second);
			}
			else if (choice == 4)
			{
				if (second == 0)
				{
					printf("Error: Division by zero\n");
				}
				else
				{
					printf("Result: %f\n", first / second);
				}
			}
		}
	}
	return (0);
}
