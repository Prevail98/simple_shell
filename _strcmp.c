#include "shell.h"

/**
 * _strchr - Locate a character in a string.
 * @str: The string to be searched.
 * @c: The character to be found.
 *
 * Return: If c is found - a pointer to the first occurrence.
 *         If c is not found - NULL.
 */
char *_strchr(char *str, char c)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		if (str[index] == c)
			return (str + index);
	}

	return (NULL);
}

/**
 * _strspn - Get the length of a prefix substring.
 * @str: The string to be measured.
 * @prefix: The prefix to be measured.
 *
 * Return: The number of bytes in str that
 *         consist only of bytes from prefix.
 */
int _strspn(char *str, char *prefix)
{
	int byte_count = 0;
	int index;

	while (*str)
	{
		for (index = 0; prefix[index]; index++)
		{
			if (*str == prefix[index])
			{
				byte_count++;
				break;
			}
		}
		str++;
	}
	return (byte_count);
}

/**
 * _strcmp - Compare two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if str1 = str2
 *         Negative byte difference if str1 < str2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * _strncmp - Compare two strings up to the first n bytes.
 * @str1: Pointer to the first string.
 * @str2: Pointer to the second string.
 * @n: The number of bytes to compare.
 *
 * Return: Less than 0 if str1 is shorter than str2.
 *         0 if str1 and str2 match up to n bytes.
 *         Greater than 0 if str1 is longer than str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; str1[i] && str2[i] && i < n; i++)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}

