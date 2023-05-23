#include "main.h"

/**
 * main - program for the UNIX command line interpreter.
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *line;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		prompt();
		line = read_line();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (line[0] != '\0')
		{
			execute_command(line);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
