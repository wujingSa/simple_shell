#include "shell.h"

/**
 * builtin_env - Display the current environment where the shell is operating.
 *
 * @data: The program's data structure.
 * Return: 0 on success, or another number if specified in the arguments.
 */
int builtin_env(data_of_program *data)
{
	int i;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	/* Check for the absence of arguments */
	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
		for (i = 0; data->tokens[1][i]; i++)
		{
			/* Check for the existence of '=' character */
			if (data->tokens[1][i] == '=')
			{
				var_copy = str_duplicate(env_get_key(cpname, data));
				if (var_copy != NULL)
					env_set_key(cpname, data->tokens[1] + i + 1, data);

				/* Display the environment, including the modified variable */
				print_environ(data);
				if (env_get_key(cpname, data) == NULL)
				{
					/* Display the variable if it does not exist in the environment */
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					/* Restore the old value of the variable */
					env_set_key(cpname, var_copy, data);
					free(var_copy);
				}
				return (0);
			}
			cpname[i] = data->tokens[1][i];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * builtin_set_env - Set a new environment variable or update an existing one.
 *
 * @data: The program's data structure.
 * Return: 0 on success, or another number if specified in the arguments.
 */
int builtin_set_env(data_of_program *data)
{
	/* Validate the number of arguments */
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	/* Set the environment variable */
	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * builtin_unset_env - Unset (remove) an environment variable.
 *
 * @data: The program's data structure.
 * Return: 0 on success, or another number if specified in the arguments.
 */
int builtin_unset_env(data_of_program *data)
{
	/* Validate the number of arguments */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	/* Remove the environment variable */
	env_remove_key(data->tokens[1], data);

	return (0);
}
