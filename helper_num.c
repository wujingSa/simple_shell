#include "shell.h"

/**
 * longToString - Converts a long integer to a string.
 * @num: The long integer to convert.
 * Return: The converted string.
 */
char *longToString(long num)
{
	int length, i;
	char *str;

	length = countCharacters(num);

	str = malloc((length + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	for (i = length - 1; i >= 0; i--)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
	}

	str[length] = '\0';

	return (str);
}

/**
 * stringToInteger - Converts a string to an integer.
 * @str: The string to convert.
 * Return: The converted integer.
 */
int stringToInteger(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return sign * result;
}

/**
 * countCharacters - Counts the number of characters in an integer.
 * @num: The integer.
 * Return: The number of characters.
 */
int countCharacters(long num)
{
	int count = 0;

	while (num != 0)
	{
		num = num / 10;
		count++;
	}

	return count; ()
}

