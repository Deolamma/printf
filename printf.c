#include "main.h"
#include <stdarg.h>
/**
 * vprintf - function that helps us detrmine if we have hit
 * a format specifier or regular text and acts on whatever state
 * @fmt: format elps determine when we hit a format specifier
 * @args: gives us a list of our unknown argument
 * Return: returns an int value
 */
int vprintf(const char *fmt, va_list args)
{
	int state;
	char ch;

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
			}
		} else if (state == 1)
		{
			switch (*fmt)
			{
			case 'c': {
					ch = va_arg(args, int);
					_putchar(ch);
					break;
				}
			case 's': {
					const char *s = va_arg(args, const char *);
					while (*s)
					{
						_putchar(*s++);
					}
					break;
				}
			}
			state = 0;
		}
		fmt++;
	}
	return (*(fmt));
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

	va_start(args, format);
	rval = vprintf(format, args);
	va_end(args);
	return (rval);
}

