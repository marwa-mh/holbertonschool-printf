#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom printf that produces output according to format
 * @format: arguments to printf
 * Return: Count of argument
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0, i, j;
	Print_Type_S print_type[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_char},
		{'d', print_signed_integer},
		{'i', print_int}};

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (j = 0; j < 5; j++)
				if (print_type[j].type == format[i + 1])
				{
					len += print_type[j].print(args);
					break;
				}
			if (j == 5)
			{
				_putchar('%');
				len = len + 1 + print_type[0].print(args);
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

