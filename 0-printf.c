#include "main.h"
int str_len(const char *f);

/**
 * _printf - main function
 * @format: argument
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;

	va_start(args, format);
	/*_int_hand(format, args);*/
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += format_hand(&format, args);
		}
		else if (*format == '\0')
		{
			return (-1);
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
