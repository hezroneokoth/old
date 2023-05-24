#include "shell.h"
/**
 * our_getline - our own getline function to read input line
 *
 * @input: pointer to input string
 * @bytes: pointer to size of allocated mem
 * @status: error exit status
 * Return: the no of chars read from input
 */
ssize_t our_getline(char **input, size_t *bytes, int status)
{
	static char buffer[1024];
	static size_t buffer_index;
	static ssize_t buffer_size;
	ssize_t number_of_chars_read = 0;
	char current_char;

	if (buffer_index >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, sizeof(buffer));
		buffer_index = 0;
	}
	while (buffer_index < buffer_size)
	{
		current_char = buffer[buffer_index++];

		if (number_of_chars_read + 1 >= *bytes)
		{
			*bytes *= 2;
			*input = (char *)realloc(*input, *bytes);
			if (*input == NULL)
			{
				exit(status);
			}
		}
		(*input)[number_of_chars_read++] = current_char;
		if (current_char == '\n')
			break;
	}
	(*input)[number_of_chars_read] = '\0';
	if (buffer_size == 0
			(buffer_size < sizeof(buffer) && buffer_index >= buffer_size))
	{
		free(*input);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", strlen("\n"));
		exit(status);
	}
	return (number_of_chars_read);
}
