#include "shell.h"

/**
 * main - Entry point for the shell.
 * @ac: The number of arguments.
 * @av: An array of argument strings.
 * @env: The array of environment variables.
 * Return: The exit status.
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	signal(SIGINT, handleCtrlC);

	if (!isatty(STDIN_FILENO))
	{
		while (1)
			sisifo(env);
	}
	else
	{
		while (1)
			sisifo(env);
	}

	return (0);
}

/**
 * handleCtrlC - Handles the SIGINT signal (Ctrl+C).
 * @sig: The signal number.
 */
void handleCtrlC(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * initializeData - Initializes data for the shell.
 * @env: The array of environment variables.
 * Return: A structure containing initialized data.
 */
shellData *initializeData(char **env)
{
	shellData *data = malloc(sizeof(shellData));

	if (data == NULL)
		exitWithError("malloc error");

	data->env = env;

	return (data);
}

/**
 * sisifo - Runs the main loop of the shell.
 * @env: The array of environment variables.
 */
void sisifo(char **env)
{
	char *input;
	size_t len = 0;
	ssize_t read;

	shellData *data = initializeData(env);

	write(STDOUT_FILENO, "$ ", 2);

	read = getline(&input, &len, stdin);
	if (read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(input);
		free(data);
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(input, "exit\n") == 0)
	{
		free(input);
		free(data);
		exit(EXIT_SUCCESS);
	}

	/* Other processing for the input */

	free(input);
	free(data);
}

