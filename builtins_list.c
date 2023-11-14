#include "shell.h"

/**
 * builtins_list - Search for a matching cmd & execute the associated builtin.
 * @data: Struct holding the program's data.
 *
 * Return: Returns the return value of the executed function if match,
 * otherwise returns -1.
 **/
int builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", builtin_exit},
		{"help", builtin_help},
		{"cd", builtin_cd},
		{"alias", builtin_alias},
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};

	/* Iterate through the list of builtins */
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		/* Check if there is a match between the given command and a builtin */
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
			/* Execute the associated function and return its return value */
			return (options[iterator].function(data));
		}
		/* If no match is found, return -1 */
	}

	return (-1);
}
