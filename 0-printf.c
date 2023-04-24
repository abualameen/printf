#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - main entry of the function printf
 * @format: string containing the format
 * Return: 0
 */
int _printf(const char *format, ...)
{
        va_list args;
        char c;
        char *s;
/*      int dgts, dgt, temp, val, q, base;*/
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
                                case 'c':
                                        c = va_arg(args, int);
                                        _putc(c);
                                        counter++;
                                        break;
                                case 's':
                                        for (s = va_arg(args, char *); *s; s++)
                                        {
                                                _putc(*s);
                                                counter++;
                                        }
                                        break;
                                case '%':
                                        _putc('%');
                                        counter++;
                                        break;
                                case 'i':
                                case 'd':
                                        val = va_arg(args, int);
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
