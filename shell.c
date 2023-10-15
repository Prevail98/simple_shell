#include "shell.h"
#include <stdio.h>
/**
 * main - the main function
 * @ac: the parameter
 * @av: a parameter
 * @env: Envirment variable
 * Return: return 0 if sucess and 1 if it fails
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av, env);
		return (0);
	}

	return (1);
}
