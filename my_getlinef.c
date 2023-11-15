#include "shell_version_two.h"

/**
* bring_line - asgns the line variable for get_line
* @lineptr: Buff that store the input str
* @buff: str that is been called to line
* @n: size of line
* @g: size of buffer
*/
void bring_line(char *lineptr, size_t *n, char *buff, size_t g)
{

if (*lineptr == NULL)
{
if  (g > BUFSIZE)
*n = g;

else
*n = BUFSIZE;
*lineptr = buff;
}
else if (*n < g)
{
if (g > BUFSIZE)
*n = g;
else
*n = BUFSIZE;
*lineptr = buff;
}
else
{
_strcpy(*lineptr, buff);
free(buff);
}
}

/**
* my_getlinef: read an entr line from stream
* @linepter: A pter to the buf where the line stro
* @n: A pter to the size of the buffer
* @stream: Stream to read from
* Return: number of bytes
*/
ssize_t my_getlinef(char *lineptr, size_t *n,File *stream)
{
int i;
sssize_t input;
ssize_t rtval;
char *buff;
char t = 'z';

if (input == 0)
fflush(stream);
else
return (-1);
input = 0;

buff = malloc(sizeof(char) * BUFSIZE);
if (buff == 0)
return (-1);
while (t != '\n')
{
i = read(STDIN_FILENO, &t, 1);
if (i == -1 || (i == 0 && input == 0))
{
free(buff);
return (-1);
}
if (i == 0 && input != 0)
{
input++;
break;
}
if (input >= BUFSIZE)
buff = _realloc(buffer, input, input + 1);
buff [input] = t;
input++;
}
buff [input] = '\0';
bring_line(lineptr, n, buff, input);
rtval = input;
if (i != 0)
input = 0;
return (rtval);
}
}
