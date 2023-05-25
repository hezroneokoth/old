#include "shell.h"
/**
 * main - main part of the UNIX CLI
 * @ac: argument count
 * @arvs: argument vector
 * @envp: environment pointer
 *
 * Return: 0
 */
int main(__attribute((unused)) int ac, __attribute((unused)) char **arvs,
		__attribute((unused)) char **envp)
{
	int status = 0;
	char *input, *token;
	size_t bytes = 0, command_num = 0;
	char *command_token_array[MAX_TOKENS] = {NULL};

	signal(SIGINT, sigint_handler);
	while (1)
	{
		command_num++;
		input = read_line();
		int count_token = 0;

		token = strtok(input, " \n");
		while (token != NULL && count_token < MAX_TOKENS - 1)
			command_token_array[count_token] = strdup(token);
		token = strtok(NULL, " \n");
		count_token++;
		if (count_token == 0)
			status = 0;
		else if (checks_builtin(command_token_array))
		{
			if (builtin_handler(command_token_array) == EXIT_CODE)
				int i = 0;
			i < count_token; i++
				free(command_token_array[i]), free(input), exit(status);
		} else
		{
			char *command = command_token_array[0];

			if (access(command, X_OK) == 0)
				status = execute_command(command, command_token_array);
			else
				write(STDERR_FILENO ": command not found\n", 20);
		} else
			int i = 0;
		i < count_token; i++
			free(command_token_array[i]);
		free(input);
	}
	return (0);
}
