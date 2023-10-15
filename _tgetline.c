#include "shell.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _getline - implementation of the getline func
 * @lineptr: parameter of address
 * @n: length of string
 * @stream: The stream to receive file
I * Return: length of input string
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char c;
	int len = 120;
	size_t i = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		perror("Error!");
		exit(1);
	}
	if (*lineptr == NULL)
	{
	*n = len;
	*lineptr = (char *)malloc(*n);
	if (*lineptr == NULL)
	{
		perror("cannot allocate memory");
		exit(1);
	}
	}
	while ((c = fgetc(stream)) != EOF)
	{
		(*lineptr)[i++] = c;
		if (i >= *n)
		{
			*n *= 2;
			*lineptr = (char *)realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				perror("cannot reallocate memory");
				exit(1);
			}
		}
		if (c == '\n')
		{
			(*lineptr)[i] = '\0';
			return (i);
		}
	}
	(*lineptr)[i] = '\0';
	return (i);
}

