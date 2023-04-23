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
	int val, temp, q, t; 
	int y = 0;
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
					temp = val;
					while (temp != 0)
					{
						t = temp % 10;
						arr[y] = t;
						y++;
						temp = temp / 10;
					}
					for (q = y - 1; q > -1; q--)
					{
						printf("%d", arr[q]);
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
