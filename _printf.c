#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include "_putchar.c"

int _printf(const char *format, ...){
    va_list args;
    int count = 0;
    int i, j;
    char *str;
    char c;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
                i++;
            }
            else if (format[i + 1] == 's')
            {
                *str = va_arg(args, char *);
                for (j = 0; str[j] != '\0'; j++)
                {
                    _putchar(str[j]);
                    count++;
                }
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