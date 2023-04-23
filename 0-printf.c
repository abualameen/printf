#include "main.h"
#include <stdarg.h>
/**
 * _printf - this function prints according to format
 * @format: given format
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	char c;
	char *s;
	int counter = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == c)
			{
				c = va_arg(args, int);
				_putc(c);
				counter++;
			}
			else if (*format == '%')
			{
				_putc('%');
				counter++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s)
					_putc(*s);
					counter++;
					s++;
			}
		}
		else
			_putc(*format);
			counter++;
			format++;

	}
	va_end(args);
	return (counter);
}
