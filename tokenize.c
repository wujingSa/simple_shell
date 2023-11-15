#include "shell.h"

/**
 * tokenize - Tokenizes a string into an array of strings.
 * @str: The string to tokenize.
 * @delim: The delimiter character.
 * Return: An array of tokens.
 */
char **tokenize(char *str, const char *delim)
{
	char **tokens = NULL;
	char *token;
	int count = 0;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * (countTokens(str, delim) + 1));
	if (tokens == NULL)
		return (NULL);

	token = _strtok(str, delim);
	while (token != NULL)
	{
		tokens[count] = token;
		count++;
		token = _strtok(NULL, delim);
	}

	tokens[count] = NULL;
	return (tokens);
}

/**
 * countTokens - Counts the number of tokens in a string.
 * @str: The string to count tokens in.
 * @delim: The delimiter character.
 * Return: The number of tokens.
 */
int countTokens(char *str, const char *delim)
{
	int count = 0;
	char *token = _strtok(str, delim);

	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, delim);
	}

	return (count);
}

