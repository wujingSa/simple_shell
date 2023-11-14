#include "shell.h"

/**
 * execute - Execute a command with its full path and handle built-ins.
 * @data: Pointer to the program's data structure.
 * Return: Returns zero on success, -1 on failure.
 */
int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pid;

	/* Check if the program is a built-in command */
	retval = builtins_list(data);
	if (retval != -1) /* If the program is a built-in command */
		return (retval);

	/* Check for the program in the file system */
	retval = find_program(data);
	if (retval) /* If the program is not found */
	{
		return (retval);
	}
	else /* If the program is found */
	{
		pid = fork(); /* Create a child process */
		if (pid == -1)
		{
			/* If the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			/* Child process executes the program */
			retval = execute_child_process(data);
			if (retval == -1) /* If an error occurs during execve */
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process waits and checks the exit status of the child */
			wait_and_check_status(&status);
		}
	}
	return (0);
}

/**
 * execute_child_process - Execute the program in the child process.
 * @data: Pointer to the program's data structure.
 * Return: Returns zero on success, -1 on failure.
 */
int execute_child_process(data_of_program *data)
{
	int retval;

	retval = execve(data->tokens[0], data->tokens, data->env);
	return (retval);
}

/**
 * wait_and_check_status - Wait for the child process and check status.
 * @status: Pointer to the status variable.
 */
void wait_and_check_status(int *status)
{
	wait(status);
	if (WIFEXITED(*status))
		errno = WEXITSTATUS(*status);
	else if (WIFSIGNALED(*status))
		errno = 128 + WTERMSIG(*status);
}
