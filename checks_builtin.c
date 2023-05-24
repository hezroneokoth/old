#include "shell.h"

/**
 * checks_builtin - checks whether a command is built-in
 * @command_token_array: command token array
 *
 * Return: 1 if built-in command, OR 0 if not
 */
int checks_builtin(char **command_token_array)
{
	int builtin_index;
	const char *builtin[] = {"env", "exit", NULL};

	if (command_token_array == NULL || command_token_array[0] == NULL)
		return (0);
	for (builtin_index = 0; builtin[builtin_index] != NULL; builtin_index++)
	{
		if (string_equal(command_token_array[0], builtin[builtin_index]))
			return (1);
	}
	return (0);
}
/**
 * builtin_handler - handle execution of built-in commands
 * @command_token_array: command token array
 *
 * Return: 1 if the built-in command is executed, OR 0
 */
int builtin_handler(char **command_token_array)
{
	int builtin_index;
	const char *builtin[] = {"env", "exit", NULL};

	int (*builtin_functions[])(char **) = {&_myenv, &the_exit};
	if (command_token_array == NULL || command_token_array[0] == NULL)
		return (0);

	for (builtin_index = 0; builtin[builtin_index] != NULL; builtin_index++)
	{
		if (string_equals(command_token_array[0], builtin[builtin_index]))
			return (builtin_functions[builtin_index](command_token_array));
	}
	return (0);
}

/**
 * string_equal - compare 2 strings for equality
 * @str1: 1st string
 * @str2: 2nd string
 *
 * Return: 1 if the strings are equal, OR 0
 */
int string_equal(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return ((*str1 == '\0' && *str2 == '\0'));
}
