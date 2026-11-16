#include "main.h"
#include <stdlib.h>

/**
 * error_exit - prints Error and exits with status 98
 */
void error_exit(void)
{
	char *msg = "Error\n";
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		_putchar(msg[i]);
	exit(98);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * is_number - checks that a string is only digits
 * @s: the string
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	if (s[0] == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * multiply - multiplies two number strings digit by digit
 * @s1: first number
 * @s2: second number
 * @len1: length of s1
 * @len2: length of s2
 * @res: array (len1 + len2 ints, filled with zeros) to hold the result
 */
void multiply(char *s1, char *s2, int len1, int len2, int *res)
{
	int i, j, mul;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (s1[i] - '0') * (s2[j] - '0') + res[i + j + 1];
			res[i + j + 1] = mul % 10;
			res[i + j] += mul / 10;
		}
	}
}

/**
 * print_result - prints the result array without leading zeros
 * @res: the result array
 * @size: size of the array
 */
void print_result(int *res, int size)
{
	int i = 0;

	while (i < size && res[i] == 0)
		i++;
	if (i == size)
		_putchar('0');
	for (; i < size; i++)
		_putchar(res[i] + '0');
	_putchar('\n');
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int len1, len2, i, *res;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
		error_exit();
	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);
	res = malloc(sizeof(int) * (len1 + len2));
	if (res == NULL)
		error_exit();
	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;
	multiply(argv[1], argv[2], len1, len2, res);
	print_result(res, len1 + len2);
	free(res);
	return (0);
}
