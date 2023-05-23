#include "main.h"

/**
 * main - function for UNIX CLI that also handles args
 *
 * Return: EXIT_SUCCESS on success
 */
int main(void)
{
	char *line;
	char *arguments[MAX_ARGUMENTS];

	signal(SIGINT, sigint_handler);
	while (1)
	{
		prompt();
		line = read_line();

		if (line == NULL)
		{
			write(STDOUT_FILENO, "Exiting\n", 8);
			break;
		}
		if (line[0] != '\0')
		{
			int argc = create_arguments(line, arguments, MAX_ARGUMENTS);
			execute_command(arguments[0], arguments);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
