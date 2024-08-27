# 42Get_next_line
My project get_next_line from School 42

![42Get_next_line-cover](cover-get_next_line-bonus.png)

<table>
  <tr><td>Function name</td><td>get_next_line</td></tr>
  <tr><td>Prototype</td><td>char *get_next_line(int fd);</td></tr>
  <tr><td>Turn in files</td><td>get_next_line.c, get_next_line_utils.c, get_next_line.h</td></tr>
  <tr><td>Parameters</td><td>fd: The file descriptor to read from</td></tr>
  <tr><td>Return value</td><td>Read line: correct behavior</br>NULL: there is nothing else to read, or an error occurred</td></tr>
  <tr><td>External functions</td><td>read, malloc, free</td></tr>
  <tr><td>Description</td><td>Write a function that returns a line read from a file descriptor</td></tr>
</table>

## Mandatory part

* Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
* Make sure that your function works as expected both when reading a file and when
reading from the standard input.
* Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
* Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
* Add all the helper functions you need in the get_next_line_utils.c file
* Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n</br>
It will define the buffer size for read().</br>
The buffer size value will be modified by your peer-evaluators and the Moulinette
in order to test your code.
* You will compile your code as follows (a buffer size of 42 is used as an example):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
* We consider that get_next_line() has an undefined behavior if the file pointed to
by the file descriptor changed since the last call whereas read() didn’t reach the
end of file.
* We also consider that get_next_line() has an undefined behavior when reading
a binary file. However, you can implement a logical way to handle this behavior if
you want to.

# Forbidden
* You are not allowed to use your libft in this project.
* lseek() is forbidden.
* Global variables are forbidden.

## Bonus part

This project is straightforward and doesn’t allow complex bonuses. However, we trust
your creativity. If you completed the mandatory part, give a try to this bonus part.
Here are the bonus part requirements:
* Develop get_next_line() using only one static variable.
* Your get_next_line() can manage multiple file descriptors at the same time.</br>
For example, if you can read from the file descriptors 3, 4 and 5, you should be
able to read from a different fd per call without losing the reading thread of each
file descriptor or returning a line from another fd.</br>
It means that you should be able to call get_next_line() to read from fd 3, then
fd 4, then 5, then once again 3, once again 4, and so forth.</br>

Append the _bonus.[c\h] suffix to the bonus part files.</br>
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:
* get_next_line_bonus.c
* get_next_line_bonus.h
* get_next_line_utils_bonus.c

<img align="right" src="get_next_linee.png">
