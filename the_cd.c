#include "shell.h"
/**
 * the_cd - changes the current directory of the process
 * @arg: argument rep the directory to change to
 *
 * Return: void
 */
void the_cd(char *arg)
{
	char cwd[PATH_MAX];
	char *home = getenv("HOME");
	char *oldpwd = getenv("OLDPWD");

	if (arg == NULL || (arg[0] == '-' && arg[1] == '\0'))
	{
		if (arg && arg[0] == '-' && arg[1] == '\0')
			arg = oldpwd;
		else
			arg = home;
		if (arg == NULL)
		{
			write(STDERR_FILENO, "cd: $HOME not set\n", 18);
			return;
		}
	}
	if (chdir(arg) != 0)
	{
		write(STDERR_FILENO, "cd: Failed to change directory\n", 31);
		return;
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
		setenv("OLDPWD", oldpwd, 1);
	} else
		write(STDERR_FILENO, "cd: Failed to find current directory\n", 37);
}
