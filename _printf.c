#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
/**
 * print_char - prints the char assigned to the %c specifier
 * @args: list of arguments in our case char value
 * Return: returns an int value for the number of char
 */
int print_char(va_list args)
{
	char ch;
	int rval = 0;

	ch = va_arg(args, int);
	_putchar(ch);
	rval++;
	return (rval);
}
/**
 * print_string - prints the string assigned to the %s specifier
 * @args: list of arguments in our case list of strings
 * Return: returns an int value for the number of char in string
 */
int print_string(va_list args)
{
	int rval = 0;
	const char *s = va_arg(args, const char *);

	while (*s)
	{
		_putchar(*s++);
		rval++;
	}
	return (rval);
}


/**
 * vprintf - function that helps us detrmine if we have hit a %
 * @fmt: format elps determine when we hit a format specifier
 * @args: gives us a list of our unknown argument
 * Return: returns an int value
 */
int vprintf(const char *fmt, va_list args)
{
	int state = 0;
	int rval = 0;

	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
			{
				state = 1;
			} else
			{
				_putchar(*fmt);
				rval++;
			}
		} else if (state == 1)
		{
			switch (*fmt)
			{
			case 'c': {
					rval = print_char(args);
					break;
				}
			case 's': {
					rval = print_string(args);
					break;
				}
			default: {
					 state = 0;
					 _putchar('%');
					_putchar(*fmt);
					rval += 2;
					break;
				}

			}
			state = 0;
		}
		fmt++;
	}
	return (rval);
}

/**
 * _printf - prints out different data types based on format specifiers
 * such as %s (String), %c (Char)
 * @format: This is usually the % before a the appropriate specifier for
 * the data type to be printed out
 * Return: Returns an int
 */
int _printf(const char *format, ...)
{
	int rval;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	rval = vprintf(format, args);
	va_end(args);
	printf("%d\n", rval);
	return (rval);
}

