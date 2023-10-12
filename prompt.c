#include "shell.h"
#include <stdio.h>
#include <sys/wait.h>

#define MAX_COMMAND 10

void prompt(char **av, char **env)
{

	char *str = NULL;
	int j, i, status;
	size_t t = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	pid_t child_pid;


	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("tegtim$ ");

		num_char = getline(&str, &t, stdin);
		if (num_char == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		
		}

		j = 0;
		argv[j] = strtok(str, " ");
		while (argv[j])
			argv[++j] = strtok(NULL, " ");

		child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: file not found\n", av[0]);
		}
		else
			wait(&status);


	}
}
