#include "main.h"
int _putc(char c);
int str_len(const char *f);
/**
 * _printf - print arguments
 * @format: string to be printed
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;
	char *str;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				counter += _putc(va_arg(args, int));
			}
			else if (*format == '\0')
				return (-1);
			else if (*format == 's')
			{
				for (str = va_arg(args, char *); *str; str++)
				{
					if (!str)
					{
						str = "(null)";
						counter += write(1, str, str_len(str));
					}
					counter += _putc(*str);
				}
			}
			else if (*format == '%')
			{
				counter += _putc('%');
			}
			else if (*format != 'c' || *format != 's' || *format != '%')
			{
				counter += _putc('%');
				counter += _putc('r');
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


/**
 * _putc - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putc(char c)
{
	return (write(1, &c, 1));
}

/**
 * str_len - comput len of str
 * @str: string
 * Return: 0
 */
int str_len(const char *f)
{
	int e;
	int count;

	for (e = 0; f[e] != '\0'; e++)
	{
		count++;
	}
	return (count);
}
