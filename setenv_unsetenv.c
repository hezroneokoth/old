#include "shell.h"
/**
 * the_setenv - sets environment variable
 * @args: argument array, args[1] reps Variable and args[2] reps the Value
 *
 * Return: void
 */
void the_setenv(char *args[])
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "setenv: Variable & Value must be given\n", 23);
		return;
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		write(STDERR_FILENO, "setenv: Failure setting variable\n", 33);
	}
}
/**
 * the_unsetenv - unsets environment variable
 * @args: argument array, args[1] reps variable to unset
 *
 * Return: void
 */
void the_unsetenv(char *args[])
{
	if (args[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: Variable must be given\n", 25);
		return;
	}
	if (unsetenv(args[1]) != 0)
	{
		write(STDERR_FILENO, "unsetenv: Failure unsetting environ variable\n", 49);
	}
}
