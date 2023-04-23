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
	int val, t, q;
	int r = 0;
	int counter = 0;
	int arr[MAX];

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
				case 'd':
				case 'i':
					val = va_arg(args, int);
					if (val < 0)
					{
						_putc('-');
						counter++;
						val = -val;
					}
					while (val != 0)
					{
						t = val % 10;
						arr[r] = t;
						r++;
						val = val / 10;
					}
					for (q = r - 1; q > -1; q--)
					{
						_putc(arr[q] + '0');
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


