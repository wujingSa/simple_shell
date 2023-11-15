#include "main.h"

/**
 * aux_help_env - Provides information about the 'env' command
 * Return: no return
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Display the environment variables of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_setenv - Provides information about the 'setenv' command
 * Return: no return
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add or modify an environment variable.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_unsetenv - Provides information about the 'unsetenv' command
 * Return: no return
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an environment variable completely.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_general - Entry point for general help information
 * Return: no return
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally. Type 'help' to see the list.";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about a specific function.\n\n ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - Provides information about the 'exit' command
 * Return: no return
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit the shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a specified status (N). If omitted, ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "the status is that of the last executed command.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
