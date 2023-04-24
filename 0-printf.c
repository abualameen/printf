#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _printf - main entry of the function printf
 * @format: string containing the format
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;
	char *s;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					counter += _putc(va_arg(args, int));
					break;
				case 's':
					for (s = va_arg(args, char *); *s; s++)
					{
						counter += _putc(*s);
					}
					break;
				case '%':
					counter += _putc('%');
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
			counter += _putc(*format);
		}
		format++;
	}
	va_end(args);
	return (counter);
}
