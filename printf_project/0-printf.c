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
	int counter = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					counter++;
					break;
				case 's':
					for (s = va_arg(args, char *); *s; s++)
						putchar(*s);
						counter++;
					break;
				case '%':
					putchar('%');
					counter++;
					break;
				default:
					putchar('%');
					putchar(*format);
					counter + = 2;
					break;
		}
		else
			putchar(*format);
			counter++;
		format++;
	}
	va_end(args);
	return (counter);
}
