#include "main.h"
#include <stdio.h>
/**
 * print_char - print character
 * @args: args
 * Return: int
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
/**
 * print_signed_integer - print signed integer
 * @args: args
 * Return: int
 */
int print_signed_integer(va_list args)
{
	int c = va_arg(args, int);

	return (print_number(c));
}
/**
 * print_int - print int
 * @args: args
 * Return: int
 */
int print_int(va_list args)
{
	int len = 0;

	len =  print_number(va_arg(args, int));
	return (len);
}
/**
 * print_number - print number
 * @n: the number
 * Return: int
 */
int print_number(int n)
{
	int len = 0;

	if (n < 0)
	{
		_putchar('-');
		len = print_neg_number(n);
	}
	else
	{
		len = print_pos__number(n);
	}
	return (len);
}
int print_neg_number(int n)
{
	int len = 1;

	if (n / 10 < 0)
	{
		len = print_neg_number(n / 10);
		_putchar(((n % 10) * -1) + '0');
	}
	else
		_putchar(-1 * n + '0');
	return (len + 1);
}
int print_pos_number(int n)
{
	int len = 0;

	if (n / 10 > 0)
	{
		len = print_pos_number(n / 10);
		_putchar((n % 10) + '0');
	}
	else
		_putchar(n + '0');
	return (len + 1);
}
/**
 * print_string - print string
 * @args: args
 * Return: int
 */
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
		str++;
	}
	return (len);
}

