#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom printf that produces output according to format
 * @format: arguments to printf
 * Return: Count of argument
 */
int _printfo(const char *format, ...)
{
	va_list args;
	int len = 0, i, j;
	Print_Type_S print_type[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_signed_integer},
		{'i', print_int}};

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (j = 0; j < 4; j++)
				if (print_type[j].type == format[i + 1])
				{
					len += print_type[j].print(args);
					break;
				}
			if (j == 4)
			{
				_putchar('%');
				len++;
				if (format[i + 1] != '%')
				{
					_putchar(format[i + 1]);
					len++;
				}
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}

