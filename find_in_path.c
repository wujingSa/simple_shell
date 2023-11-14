#include "shell.h"

/**
 * check_file - Checks if a file exists, not a dir, and has execution perms.
 * @full_path: Pointer to the full file name.
 * Return: 0 on success, or an error code if the file do not meet the cri.
 */
int check_file(char *full_path);

/**
 * find_program - Finds a program in the system's PATH environment variable.
 * @data: Pointer to the program's data.
 * Return: 0 if success, error code otherwise.
 */
int find_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	/* If it is a full_path or an executable in the same path */
	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = tokenize_path(data); /* Search in the PATH */

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{
		/* Appends the function_name to path */
		directories[i] = str_concat(directories[i], data->tokens[0]);
		ret_code = check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{
			/* The file was found, is not a directory and has execute permissions */
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(directories[i]);
			free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(directories);
	return (ret_code);
}

/**
 * tokenize_path - Tokenizes the PATH env var into an array of path dir.
 * @data: Pointer to the program's data.
 * Return: Array of path directories.
 */
char **tokenize_path(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	/* Get the PATH value */
	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		/* Path not found */
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	/* Find the number of directories in the PATH */
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	/* Reserve space for the array of pointers */
	tokens = malloc(sizeof(char *) * counter_directories);

	/* Tokenize and duplicate each token of the path */
	i = 0;
	tokens[i] = str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);
}

/**
 * check_file - Checks if a file exists, not a dir, & has execution perms.
 * @full_path: Pointer to the full file name.
 * Return: 0 on success, or an error code if the file do not meet the crit.
 */
int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) || access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/* If the file does not exist */
	errno = 127;
	return (127);
}
