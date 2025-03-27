#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_signed_integer(va_list args);
int print_int(va_list args);
int print_number(int n);
int print_neg_number(int n);
int print_pos_number(int n);
/**
 * struct Print_Type - Structure to map a character type to a function pointer
 * @type:the type specifier (e.g., 'c', 's' for string)
 * @print: Function pointer to a function
 * Description: This structure is used in a printf-like function
 */
typedef struct Print_Type
{
	char type;
	int (*print)(va_list args);
} Print_Type_S;
#endif
