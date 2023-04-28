#include "main.h"
#include <stdio.h>
/**
 * _putchar - prints out only 1 char. to stdout
 * @c: character to be printed out to stdout
 * Return: Returns an int value
 */
int _putchar(int c)
{
	if (c == '\n')
	{
		putchar('\n');
	} else
	{
		putchar(c);
	}
	return (0);
}

