#include "shell.h"

/**
 * str_length - Computes the length of a string.
 * @string: The input string.
 * Return: The length of the string.
 */
int str_length(char *string)
{
	int length = 0;

	while (string[length] != '\0')
		length++;

	return (length);
}

/**
 * str_duplicate - Duplicates a string.
 * @string: The input string to duplicate.
 * Return: The duplicated string.
 */
char *str_duplicate(char *string)
{
	int length, i;
	char *duplicate;

	length = str_length(string);

	duplicate = malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		duplicate[i] = string[i];

	duplicate[length] = '\0';

	return (duplicate);
}

/**
 * str_compare - Compares two strings.
 * @string1: The first string to compare.
 * @string2: The second string to compare.
 * @number: The number of characters to compare.
 * Return: 0 if the strings are equal, a negative value if the first string
 * is less than the second, and a positive value otherwise.
 */
int str_compare(char *string1, char *string2, int number)
{
	int i;

	for (i = 0; i < number; i++)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
	}

	return (0);
}

/**
 * str_concat - Concatenates two strings.
 * @string1: The first string.
 * @string2: The second string.
 * Return: A new string containing the concatenated input strings.
 */
char *str_concat(char *string1, char *string2)
{
	int length1, length2, i, j;
	char *result;

	length1 = str_length(string1);
	length2 = str_length(string2);

	result = malloc((length1 + length2 + 1) * sizeof(char));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < length1; i++)
		result[i] = string1[i];

	for (j = 0; j < length2; j++)
		result[i + j] = string2[j];

	result[i + j] = '\0';

	return (result);
}

/**
 * str_reverse - Reverses a string.
 * @string: The input string to reverse.
 */
void str_reverse(char *string)
{
	int start = 0;
	int end = str_length(string) - 1;
	char temp;

	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;

		start++;
		end--;
	}
}

