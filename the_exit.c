#include "main.h"
/**
 * the_exit - handles shell exit built-in command
 * @command_token_array: token arrays containing the command
 *
 * Return: 0
 */
int the_exit(char **command_token_array)
{
	if (command_token_array[1] != NULL)
	{
		int exit_status = atoi(command_token_array[1]);

		exit(exit_status)
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
