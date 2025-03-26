#include "main.h"
#include <stdio.h>
int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
}
int print_signed_integer(va_list args)
{
	int len = 0;
	int c = va_arg(args, int);

	return (print_number(c));
}
int print_int(va_list args)
{
	int len = 0;

	len = 1 + print_number(va_arg(args, int));
	return (len);
}
int print_number(int n)
{
	int len = 0;
	if (n < 0)
	{
		_putchar('-');
		len++;
		n = n * -1;
	}
	if (n / 10 > 0)
	{
		len += print_number(n / 10);
		_putchar((n % 10) + '0');
	}
	else
		_putchar(n + '0');
	return (len + 1);
}
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		_putchar(*str);
		len++;
	}
	return (len);
}

