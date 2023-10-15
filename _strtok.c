#include <sys/wait.h>
#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/**
 * _strtok - tokeniser
 * @str: string parameter
 * Return: Array of string
 */
char **_strtok(char *str)
{
	char **arst, *pars;
	int i = 0, j = 0;

	arst = malloc(8 * sizeof(char *));
	if (arst == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pars = strtok(str, " ");
	while (pars != NULL)
	{
		while (pars[j])
		{
			if (pars[j] == '\n')
				pars[j] = '\0';
			j++;
		}
		arst[i] = pars;
		i++;
		j = 0;
		pars = strtok(NULL, " ");
	}
	arst[i] = NULL;
	return (arst);
}
