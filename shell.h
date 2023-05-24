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
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

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
int main(void);

#endif
