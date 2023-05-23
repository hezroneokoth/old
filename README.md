0x16. C - A SIMPLE SHELL PAIR PROJECT

Herein is an ALX SE step-by-step process to create a simple shell program based on a series of tasks.
It is a group project by Hezrone & Boitumelo and challenges our knowledge and undestanding of the basics of programming and of C.

PLAGIARISM

We are tasked to come up with solutions for the tasks below yourselves to meet the learning goals
We will NOT be able to meet the objectives of this or any following projects by copying & pasting someone else’s work
We are NOT allowed to publish any content of this project
ANY form of plagiarism is strictly forbidden and will result in removal from the program

OUTPUT

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

ALLOWED FUNCTIONS AND SYSTEM CALLS

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
write (man 2 write

CONTRIBUTORS

As indicated in the AUTHORS file, Boitumelo Rakobeloa and Hezrone Okoth are the sole contributors to this simple shell. We appreciate any requests whatsoever but we do not, at this time, require any additional functionalities.

LICENSE

These codes are in the public domain but should not be published in any other platform.
You are allowed to use or modify it anyway you would like but not in any way that infringes on copyright.
