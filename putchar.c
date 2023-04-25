#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints out only 1 char. to stdout
 * @c: character to be printed out to stdout
 * Return: Returns an int value
 */
int _putchar(int c)
{
	return (write(1, &c, 0));
}

