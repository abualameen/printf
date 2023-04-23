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
	int val, dgt, temp, base, w;
	int counter = 0;

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
					putchar(c);
					counter++;
					break;
				case 's':
					for (s = va_arg(args, char *); *s; s++)
					{
						putchar(*s);
						counter++;
					}
					break;
				case '%':
					putchar('%');
					counter++;
					break;
				case 'd':
				case 'i':
					val = va_arg(args, int);
					if (val < 0)
					{
						putchar('-');
						counter++;
						val = -val;
					}
					dgt = 0;
					temp = val;
					while (temp != 0)
					{
						dgt++;
						temp /= 10;
					}
					if (dgt == 0)
					{
						counter++;
					}
					else
					{
						base = 1;
						for (w = 0;  w < dgt; w++)
						{
							base *= 10;
						}
						while (base != 0)
						{
							dgt = val / base;
							putchar('0' + dgt);
							counter++;
							val %= base;
							base /= 10;
						}
					}
					break;
				default:
					putchar('%');
					putchar(*format);
					counter += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			counter++;
		}
	format++;
	}
	va_end(args);
	return (counter);
}
