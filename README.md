0x16. C - A SIMPLE SHELL PAIR PROJECT

Herein is an ALX SE step-by-step process to create a simple shell program based on a series of tasks.
It is a group project by Hezrone & Boitumelo and challenges our knowledge and undestanding of the basics of programming and of C.

Resources
1. Unix shell
2. Thompson shell
3. Ken Thompson
4. Everything you need to know to start coding your own shell concept page
man or help:
sh (Run sh too)

Learning Goals of the Project
Explain to anyone:
1. Who designed & implemented the original Unix OS?
2. Who wrote the 1st version of the UNIX shell?
3. Who invented the B programming language?
4. How does a shell work
5. What is a pid & ppid?
6. How to manipulate the environ of the current process
7. The diff between a function & system call
8. How to create processes
9. What are the 3 prototypes of main?
10. How does the shell use the PATH to find the programs
11. How to execute another program with the execve system call
12. How to suspend the execution of a process until one of its children terminates
13. What is EOF?

Plagiarism
You are tasked to come up with solutions for the tasks below yourselves to meet the learning goals
You will NOT be able to meet the objectives of this or any following projects by copying & pasting someone else’s work
You are NOT allowed to publish any content of this project
ANY form of plagiarism is strictly forbidden and will result in removal from the program

Requirements
Allowed editors are vi, vim & emacs
All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All files should end with a new line
A README.md file at the root of the folder of the project is mandatory
Use Betty writing style
The shell should not have any memory leaks
No more than 5 functions in each file
Use system calls only when you need to (why?)
A README with a description of the project
An AUTHORS file at the root of your repo, listing individuals who contributed content to the project

Output
Unless specified otherwise, our program must have the same output as sh (/bin/sh) as well as the exact same error output. The only diff e is when we print an error, the name of the program must be equivalent to your argv[0].
Ex of error with sh:
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

Same error with your program hsh:
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

Heres a list of allowed functions & system calls:
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

Testing
Our shell should work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also this way in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

Contributing
As you indicated in the AUTHORS file, Boitumelo Rakobeloa and Hezrone Okoth are the sole contributors to this simple shell. We appreciate any requests whatsoever but we do not, at this time, require any additional functionalities.

license
These codes are in the public domain but should not be published in any other platform.
You are allowed to use or modify it anyway you would like but not in any way that infringes on copyright.
