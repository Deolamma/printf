#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * print_char - prints the char assigned to the %c specifier
 * @args: list of arguments in our case char value
 * Return: nothing
 */
void print_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);
	_putchar(ch);
}
/**
 * print_string - prints the string assigned to the %s specifier
 * @args: list of arguments in our case list of strings
 * Return: nothing
 */
void print_string(va_list args)
{
	const char *s = va_arg(args, const char *);

	while (*s)
	{
		_putchar(*s++);
	}
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
	int i;
	int rval = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			if (format[i] == '\\' && format[i + 1] == 'n')
			{
				_putchar('\n');
				i++;
			} else
				_putchar(format[i]);
		} else if (format[i + 1] == 'c')
		{
			print_char(args);
			i++;
		} else if (format[i + 1] == 's')
		{
			print_string(args);
			i++;
		} else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		} else
			_putchar(format[i]);
		rval++;
	}
	va_end(args);
	return (rval);
}

