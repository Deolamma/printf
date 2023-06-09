#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _pstr - prints string
 * @str: pointer to a char array
 * Return: nothing
 */
void _pstr(char *str)
{
	while (*str)
		_putchar(*str++);
}
/**
 * print_int - prints an int value based on its format specifier
 * @args: this is the list of argument gotten from va_list
 * return: return nothing
 */
void print_int(va_list args)
{
	int argn = va_arg(args, int);
	int d[20] = {0};
	int a;
	int b;
	int is_negative = 0;

	if (argn < 0)
	{
		is_negative = 1;
		argn = -argn;
	}
	if (argn == 0)
	{
		_putchar('0');
		return;
	}
	a = 0;
	while (argn > 0)
	{
		d[a++] = argn % 10;
		argn /= 10;
	}
	if (is_negative)
	{
		_putchar('-');
	}
	for (b = a - 1; b >= 0; b--)
	{
		_putchar('0' + d[b]);
	}
}
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
 * Return: int value
 */
int print_string(va_list args)
{
	const char *s = va_arg(args, const char *);

	if (s == NULL)
	{
		_pstr("(null)");
		return (-1);
	}
	while (*s)
	{
		_putchar(*s++);
	}
	return (0);
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
		} else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			print_int(args);
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

