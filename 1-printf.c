#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _1printf - main entry of the function printf
 * @format: string containing the format
 * Return: 0
 */
int _1printf(const char *format, ...)
{
        va_list args;
        int val, w;
	int counter = 0;
        char str[MAX];

        va_start(args, format);
        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        switch (*format)
                        {
                                case 'd':
                                case 'i':
                                        val = va_arg(args, int);
					printf("%d", val);
                                        int_base_str(val, 10, str);
                                        for (w = 0; str[w]; w++)
                                        {
                                                _putc(str[w]);
                                                counter++;
                                        }
                                        break;
                                default:
                                        _putc('%');
                                        _putc(*format);
                                        counter += 2;
                                        break;
                        }
                }
                else
                {
                        _putc(*format);
                        counter++;
                }
                format++;
        }
        va_end(args);
        return (counter);
}
