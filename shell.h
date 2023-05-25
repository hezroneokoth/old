#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 100
#define PATH_DELIMITER ':'
#define MAX_TOKENS 100
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

/**
 * struct passinfo - short description
 * @argv: first
 * @path: second
 * @argc: third
 * @line_count: fourth
 * @err_num: fifth
 * @arg: sixth
 * @linecount_flag: seventh
 * @status: 8th
 * @fname: 9th
 * @env: 10th
 * @history: 11th
 * @alias: 12th
 * @environ: 13th
 * @env_changed: 14th
 * @readfd: 15th
 * @histcount: 16th
 */
typedef struct passinfo
{
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	char *arg;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	int readfd;
	int histcount;
} info_t;
/**
 * struct builtin_command - descrption
 * @name: 1st
 * @function: 2nd
 */
struct builtin_command
{
	char *name;
	int (*function)(char **command_token_array);
} builtin_command;

/**
 * struct liststr - descrption
 * @num: 1st
 * @type: 2nd
 * @next: 3rd
 * @str: 4th
 */
typedef struct liststr
{
	int num;
	char type;
	char *str;
	struct liststr *next;
} list_t;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int the_exit(char **command_token_array);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
void the_cd(char *arg);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
void sigint_handler(int signum);
void the_setenv(char *args[]);
void the_unsetenv(char *args[]);
char *_memset(char *v, char b, unsigned int n);
void ffree(char **xx);
void *_realloc(void *xx, unsigned int old_size, unsigned int new_size);
char *read_line(void);
void prompt(void);
ssize_t our_getline(char **input, size_t *bytes, int status);
int bfree(void **vv);
size_t list_len(const list_t *x);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int _myalias(info_t *info);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int checks_builtin(char **command_token_array);
int string_equal(const char *str1, const char *str2);
int builtin_handler(char **command_token_array);
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int create_arguments(char *line, char **arguments, int max_arguments);
int execute_command(char *command, char **arguments);

#endif
