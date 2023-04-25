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
        int base;
        int dgts, dgt, temp;
        int val, q;
        int counter = 0;

        va_start(args, format);
        while (*format)
        {
		if (format == NULL)
			return (-1);
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
						if (s == NULL)
						{
							return(-1);
						}
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
                                        if (val < 0)
                                        {
                                                _putc('-');
                                                counter++;
                                                val = -val;
                                        }
                                        dgts = 0;
                                        temp = val;
                                        while (temp != 0)
                                        {
                                                dgts++;
                                                temp /= 10;
                                        }
                                        if (dgts == 0)
                                        {
                                                _putc('0');
                                                counter++;
                                        }
                                        else
                                        {
                                                base = 1;
                                                for (q = 1; q < dgts; q++)
                                                {
                                                        base *= 10;
                                                }
                                                while (base != 0)
                                                {
                                                        dgt = val / base;
                                                        _putc(dgt + '0');
                                                        counter++;
                                                        val %= base;
                                                        base /= 10;
                                                }
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
