#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the words in a string
 * @str: the string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * word_len - gets the length of the first word in a string
 * @str: the string
 *
 * Return: length of the word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] != '\0' && str[len] != ' ')
		len++;

	return (len);
}

/**
 * free_words - frees an array of strings
 * @words: the array
 * @n: number of strings to free
 *
 * Return: Nothing.
 */
void free_words(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(words[i]);

	free(words);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to the array of words, or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int count, i, j, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	for (j = 0; j < count; j++)
	{
		while (*str == ' ')
			str++;
		len = word_len(str);
		words[j] = malloc(sizeof(char) * (len + 1));
		if (words[j] == NULL)
		{
			free_words(words, j);
			return (NULL);
		}
		for (i = 0; i < len; i++)
			words[j][i] = str[i];
		words[j][len] = '\0';
		str += len;
	}
	words[count] = NULL;

	return (words);
}
