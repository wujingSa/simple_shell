#include "shell.h"

/**
 * _print - Prints a string to the standard output.
 * @string: The input string to print.
 * Return: The number of characters printed (excluding null byte).
 */
int _print(char *string)
{
	int length = 0;

	while (*string)
	{
		_putchar(*string);
		string++;
		length++;
	}

	return (length);
}

/**
 * _printe - Prints a string to the standard error output.
 * @string: The input string to print.
 * Return: The number of characters printed (excluding null byte).
 */
int _printe(char *string)
{
	int length = 0;

	while (*string)
	{
		_putchar_err(*string);
		string++;
		length++;
	}

	return (length);
}

/**
 * _print_error - Prints an error message to the standard error output.
 * @errorcode: The error code.
 * @data: Pointer to the program's data.
 * Return: The number of characters printed (excluding null byte).
 */
int _print_error(int errorcode, data_of_program *data)
{
	int length = 0;

	length += _printe(data->program_name);
	length += _printe(": ");
	length += _printe(longToString(data->counter, NULL, 10));
	length += _printe(": ");
	length += _printe("Error: ");
	length += _printe(get_error_message(errorcode));
	length += _printe("\n");

	return (length);
}

