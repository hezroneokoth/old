#include "shell.h"
/**
 * fork - fork from parent process
 * @command_token_array: an array of command token
 * @command: a string command
 *
 * Return: description
 */
int fork(char *command, char **command_token_array)
{
	pid_t pid;
	int status, is_execve_error;

	pid = fork();
	if (pid == -1)
	{
		perror("fork() Error: fork child unable to be created");
		return (-1);
	}
	if (pid == 0)
	{
		is_execve_error = execve(command, command_token_array, __environ);
		if (is_execve_error == -1)
		{
			perror("execve: ");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		free(command);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
