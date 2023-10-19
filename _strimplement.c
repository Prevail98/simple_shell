#include "shell.h"

/**
 * _string_length - Compute the length of a string.
 * @str: A pointer to the input string.
 *
 * Return: The length of the string.
 */
int _string_length(const char *str)
{
	int length = 0;

	if (!str)
		return (length);
	for (length = 0; str[length]; length++)
		;
	return (length);
}

/**
 * _string_copy - Copy the source string to the destination buffer.
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the destination buffer (dest).
 */
char *_string_copy(char *dest, const char *src)
{
	size_t index;

	for (index = 0; src[index] != '\0'; index++)
		dest[index] = src[index];
	dest[index] = '\0';

	return (dest);
}

/**
 * _string_concatenate - Concatenate two strings.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string to append.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_string_concatenate(char *dest, const char *src)
{
	char *dest_temp;
	const char *src_temp;

	dest_temp = dest;
	src_temp = src;

	while (*dest_temp != '\0')
		dest_temp++;

	while (*src_temp != '\0')
		*dest_temp++ = *src_temp++;
	*dest_temp = '\0';

	return (dest);
}

/**
 * _string_concatenate_n - Concatenate n bytes from source to destination.
 * @dest: Pointer to the destination string.
 * @src: Pointer to the source string to append.
 * @n: Number of bytes to concatenate.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_string_concatenate_n(char *dest, const char *src, size_t n)
{
	size_t dest_len = _string_length(dest);
	size_t index;

	for (index = 0; index < n && src[index] != '\0'; index++)
		dest[dest_len + index] = src[index];

	dest[dest_len + index] = '\0';

	return (dest);
}

