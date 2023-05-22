#include <main.h>
#include <unistd.h>
#include <stdio.h>
/**
 * prompt - the prompt for the simple shell
 *
 * Return: Always 0
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		if (write(STDOUT_FILENO, "$ ", 2) == -1)
		{
			perror("Error: failure on write.");
		}
	}
}
