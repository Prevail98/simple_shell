#include "shell.h"
/**
 * _remove - delete the newline character
 * @str: string
 * Return: modified string
 */
char *_remove(char **str)
{
	char *ptr = *str;
	size_t k = 0;

	while (ptr[k])
	{
		if (ptr[k] == '\n')
			ptr[k] = '\0';
		k++;
	}
	return (ptr);
}
/**
 * _strlen - calculate string's length
 * @str: string
 * Return: string length
 */
size_t _strlen(char *str)
{
	size_t k = 0;

	while (str[k])
		k++;
	return (k);
}
/**
 * empty_string - deletes string contents
 * @str: string
 * Return: Empty string
 */
char *empty_string(char **str)
{
	size_t length;
	char *ptr = *str;

	length = _strlen(ptr);
	length--;
	while (ptr[length])
	{
		ptr[length] = '\0';
		if (length == 0)
			return (ptr);
		length--;
	}
	return (ptr);
}
/**
 * _strdup - a func that duplicates a string
 * @strd: string dulpicate
 * @ostr: original string
 * Return: string duplicate
 */
char *_strdup(char **strd, char *ostr)
{
	char *ptr = *strd;
	size_t k = 0;

	while (ostr[k])
	{
		ptr[k] = ostr[k];
		k++;
	}
	ptr[k] = ostr[k];

	return (ptr);
}
/**
 * _append - appends a string
 * @str: First string
 * @buffer: Append characters
 * Return: Appended string
 */
char *_append(char *str, char *buffer)
{
	char *ptr = str;
	size_t k = 0, j = 0;

	k =  _strlen(ptr);

	while (buffer[j] != '\0')
	{
		if (buffer[j] == ' ')
		{
			while (buffer[j] != '\0')
			{
				ptr[k] = buffer[j];
				k++;
				j++;
			}
			ptr[k] = buffer[j];
			return (ptr);
		}
		j++;
	}
	return (ptr);
}

