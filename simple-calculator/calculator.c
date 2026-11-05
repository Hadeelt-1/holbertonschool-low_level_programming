#include <stdio.h>

/**
 * print_menu - Prints the calculator menu
 */
void print_menu(void)
{
	printf("1) Addition\n");
	printf("2) Subtraction\n");
	printf("3) Multiplication\n");
	printf("4) Division\n");
	printf("5) Quit\n");
	printf("Choice: ");
}

/**
 * calculate - Performs the arithmetic operations
 * @choice: The user's operation choice
 * @first: First number
 * @second: Second number
 */
void calculate(int choice, double first, double second)
{
	if (choice == 1)
		printf("Result: %f\n", first + second);
	else if (choice == 2)
		printf("Result: %f\n", first - second);
	else if (choice == 3)
		printf("Result: %f\n", first * second);
	else if (choice == 4)
	{
		if (second == 0)
			printf("Error: Division by zero\n");
		else
			printf("Result: %f\n", first / second);
	}
}

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
		print_menu();
		if (scanf("%d", &choice) != 1)
			break;
		if (choice == 5)
			break;
		else if (choice >= 1 && choice <= 4)
		{
			printf("Enter first number: ");
			scanf("%lf", &first);
			printf("Enter second number: ");
			scanf("%lf", &second);
			calculate(choice, first, second);
		}
	}
	return (0);
}
