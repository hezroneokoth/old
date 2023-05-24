#include "shell.h"
/**
 * create_arguments - turns command line into args by splitting them
 * @line: command to split
 * @arguments: array to store args
 * @max_arguments: max no of args
 *
 * Return: no of args
 */
int create_arguments(char *line, char **arguments, int max_arguments)
{
	int argc = 0;
	char *token = strtok(line, " ");

	while (token != NULL && argc < max_arguments - 1)
	{
		arguments[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}
	arguments[argc] = NULL;
	return (argc);
}
/**
 * execute_command - execs command by forking a child process thru using execve
 * @command: command to be executed
 * @arguments: array of command args
 *
 * Return: 1 on success
 */
int execute_command(char *command, char **arguments)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		write(STDERR_FILENO, "Error: failure on fork\n", 23);
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			write(STDERR_FILENO, command, i);
			write(STDERR_FILENO, "Error: not found\n", 17);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
	return (1);
}
