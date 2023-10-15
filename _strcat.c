#include "shell.h"
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _strcat - Function to add source string to the destination string
 * @des: destination parameter
 * @src: source parameter
 * Return: Concatenated string
 */
char *_strcat(char *des, char *src)
{
	int x, y, z, i = 0, j = 0;
	char *ptr, *mal;

	x = strlen(des);
	y = strlen(src);
	z = x + y + 1;
	mal = malloc(sizeof(char) * z);
	if (mal == NULL)
		return (NULL);
	for (i = 0; i < x; i++)
	{
		mal[i] = des[i];
	}
	while (j < y)
	{
		mal[i] = src[j];
		i++;
		j++;
	}
	mal[i] = '\0';
	ptr = mal;
	return (ptr);
}
