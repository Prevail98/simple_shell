#include "shell.h"
#include <signal.h>

/**
 * signal_handle - Handles SIGINT signal
 * @signal: Signal number
 * Return: Nothing
 */
void signal_handle(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}

/**
 * print_error - Displays an error 
 * @str: The command that was not found
 * Return: Nothing
 */
void print_error(char *str)
{
	char *error_message = ": No such file or directory\n";
	size_t i = 0, len;

	while (str[i] != '\0')
	{
		i++;
	}
	len = i;
	write(STDERR_FILENO, str, len);
	write(STDERR_FILENO, error_message, _strlen(error_message));
}


