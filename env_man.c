#include "shell.h"

/**
 * get_env_key - Fetches the value of an environment variable.
 * @key: The environment variable to retrieve.
 * @data: Structure containing the program's data.
 *
 * Return: A pointer to the value of the variable or NULL if it doesn't exist.
 */
char *get_env_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	/* Validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);

	/* Obtain the length of the requested variable */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		/* Iterates through the env & checks for a match of the variable name */
		if (str_compare(key, data->env[i], key_length) &&
			data->env[i][key_length] == '=')
		{
			/* Returns the value of the variable NAME= when found */
			return (data->env[i] + key_length + 1);
		}
	}
	/* Returns NULL if the variable is not found */
	return (NULL);
}

/**
 * set_env_key - Mod the value of the env var or creates it if non-existent.
 * @key: Name of the variable to set.
 * @value: New value.
 * @data: Structure containing the program's data.
 *
 * Return: 1 if the params are NULL, 2 if there is an error, or 0 if success.
 */
int set_env_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;

	/* Validate the arguments */
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	/* Obtain the length of the variable name */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		/* Iterates through the environ and checks for a match of the var name */
		if (str_compare(key, data->env[i], key_length) &&
			data->env[i][key_length] == '=')
		{
			/* If the variable already exists */
			is_new_key = 0;
			/* Free the entire variable, as it will be newly created below */
			free(data->env[i]);
			break;
		}
	}
	/* Create a string of the form key=value */
	data->env[i] = str_concat(str_duplicate(key), "=");
	data->env[i] = str_concat(data->env[i], value);

	if (is_new_key)
	{ /* If the variable is new, it is created at the end of the current list */
		/* to put the NULL value in the next position */
		data->env[i + 1] = NULL;
	}
	return (0);
}

/**
 * remove_env_key - Deletes a key from the environment.
 * @key: The key to remove.
 * @data: Structure containing the program's data.
 *
 * Return: 1 if the key was removed, 0 if the key does not exist;
 */
int remove_env_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	/* Validate the arguments */
	if (key == NULL || data->env == NULL)
		return (0);

	/* Obtain the length of the variable name */
	key_length = str_length(key);

	for (i = 0; data->env[i]; i++)
	{
		/* Iterates through the environ and checks for matches */
		if (str_compare(key, data->env[i], key_length) &&
			data->env[i][key_length] == '=')
		{
			/* If the key already exists, remove it */
			free(data->env[i]);

			/* Move the other keys one position down */
			i++;
			while (data->env[i])
			{
				data->env[i - 1] = data->env[i];
				i++;
			}
			/* Put the NULL value at the new end of the list */
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}

/**
 * print_environment - Prints the current environment.
 * @data: Structure for the program's data.
 *
 * Return: Nothing.
 */
void print_environment(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
}
