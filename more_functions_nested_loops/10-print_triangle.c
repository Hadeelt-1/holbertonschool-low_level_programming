#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int row, space, hash;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	row = 1;
	while (row <= size)
	{
		space = 0;
		while (space < size - row)
		{
			_putchar(' ');
			space++;
		}
		hash = 0;
		while (hash < row)
		{
			_putchar('#');
			hash++;
		}
		_putchar('\n');
		row++;
	}
}
