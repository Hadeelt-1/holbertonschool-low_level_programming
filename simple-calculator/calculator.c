#include <stdio.h>

/**
 * print_menu - Prints the calculator menu
 */
void print_menu(void)
{
	printf("0) Quit\n");
	printf("1) Addition\n");
	printf("2) Subtraction\n");
	printf("3) Multiplication\n");
	printf("4) Division\n");
	printf("Choice: ");
}

/**
 * perform_operation - Executes the chosen arithmetic operation
 * @choice: The operation choice
 */
void perform_operation(int choice)
{
	double a, b;

	printf("A: ");
	if (scanf("%lf", &a) != 1)
		return;
	printf("B: ");
	if (scanf("%lf", &b) != 1)
		return;

	if (choice == 1)
		printf("Result: %f\n", a + b);
	else if (choice == 2)
		printf("Result: %f\n", a - b);
	else if (choice == 3)
		printf("Result: %f\n", a * b);
	else if (choice == 4)
	{
		if (b == 0)
			printf("Error: Division by zero\n");
		else
			printf("Result: %f\n", a / b);
	}
}

/**
 * main - Entry point for the calculator program
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;

	while (1)
	{
		print_menu();
		if (scanf("%d", &choice) != 1)
			break;
		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		else if (choice >= 1 && choice <= 4)
		{
			perform_operation(choice);
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0);
}
