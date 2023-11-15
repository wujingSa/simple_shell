/**
 * get_sigint - Signal handler for Ctrl + C (SIGINT)
 * @sig: The signal number
 *
 * Description: Handles the Ctrl + C signal (SIGINT) by writing a message
 * ("\n^-^ ") to the standard output.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

