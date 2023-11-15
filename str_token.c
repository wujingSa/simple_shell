#include "shell.h"

/**
 * _strtok - Custom strtok function.
 * @str: The string to tokenize.
 * @delim: The delimiter character.
 * Return: A pointer to the next token, or NULL if no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *nextToken;
	char *result;

	if (str != NULL)
		nextToken = str;

	if (nextToken == NULL || *nextToken == '\0')
		return (NULL);

	result = nextToken;

	while (*nextToken != '\0' && !_strchr(delim, *nextToken))
		nextToken++;

	while (*nextToken != '\0' && _strchr(delim, *nextToken))
	{
		*nextToken = '\0';
		nextToken++;
	}

	return (result);
}

/**
 * _strchr - Custom strchr function.
 * @str: The string to search.
 * @c: The character to find.
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}

	return (NULL);
}

