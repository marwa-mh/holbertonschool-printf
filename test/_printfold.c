#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom printf that produces output according to format
 * @format: arguments to printf
 * Return: Count of argument
 */
int _printfold(const char *format, ...)
{
	va_list args;
	int count = 0, i, j;
	char *str, c;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				count++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				for (j = 0; str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					count++;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else
			{
				_putchar('%');
				_putchar(format[(i + 1)]);
				count += 2;
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
