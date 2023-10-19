#include "shell.h"

/**
 * custom_alias - Handles alias-related operations, such as printing, setting,
 * or retrieving aliases.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int custom_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int i, ret = 0;
	char *value;

	if (!args[0])
	{
		while (temp)
		{
			print_custom_alias(temp);
			temp = temp->next;
		}
		return (ret);
	}
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		value = _find_character(args[i], '=');
		if (!value)
		{
			while (temp)
			{
				if (_strcmp(args[i], temp->name) == 0)
				{
					print_custom_alias(temp);
					break;
				}
				temp = temp->next;
			}
			if (!temp)
				ret = create_error(args + i, 1);
		}
		else
			set_custom_alias(args[i], value);
	}
	return (ret);
}

/**
 * set_custom_alias - Updates an existing alias or creates a new one.
 * @alias_name: Name of the alias.
 * @value: Value of the alias. It begins with '='.
 */
void set_custom_alias(char *alias_name, char *value)
{
	alias_t *temp = aliases;
	int len, j, k;
	char *new_value;

	*value = '\0';
	value++;
	len = _string_length(value) - _strspn(value, "'\"");
	new_value = malloc(sizeof(char) * (len + 1));

	if (!new_value)
		return;
	for (j = 0, k = 0; value[j]; j++)
	{
		if (value[j] != '\'' && value[j] != '"')
			new_value[k++] = value[j];
	}
	new_value[k] = '\0';

	while (temp)
	{
		if (_strcmp(alias_name, temp->name) == 0)
		{
			free(temp->value);
			temp->value = new_value;
			break;
		}
		temp = temp->next;
	}
	if (!temp)
		add_custom_alias_end(&aliases, alias_name, new_value);
}

/**
 * print_custom_alias - Prints the alias in the format name='value'.
 * @alias: Pointer to an alias.
 */
void print_custom_alias(alias_t *alias)
{
	char *alias_string;
	int len = _string_length(alias->name) + _string_length(alias->value) + 4;

	alias_string = malloc(sizeof(char) * (len + 1));
	if (!alias_string)
		return;
	_string_copy(alias_string, alias->name);
	_string_concatenate(alias_string, "='");
	_string_concatenate(alias_string, alias->value);
	_string_concatenate(alias_string, "'\n");

	write(STDOUT_FILENO, alias_string, len);
	free(alias_string);
}

/**
 * replace_aliases - Replaces aliases in the arguments with their values.
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the modified arguments.
 */
char **replace_aliases(char **args)
{
	alias_t *temp;
	int i;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_string_length(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				 _string_copy(new_value, temp->value);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			temp = temp->next;
		}
	}

	return (args);
}

