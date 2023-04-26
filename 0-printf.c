#include "main.h"
int _putc(char c);
int str_len(const char *f);
void int_base_str(int num, int base, char str[]);
void _int_hand(const char *format, va_list args);

/**
 * _printf - main function
 * @format: argument
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;
	char *str;

	va_start(args, format);
	_int_hand(format, args);
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
					if (str == NULL)
					{
						str = "(nill)";
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
				counter += _putc(*format);
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
 * @f: string
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

/**
 * _int_hand - entry of the function printf
 * @format: string containing the format
 * @args: args list
 * Return: 0
 */

void _int_hand(const char *format, va_list args)
{
	int val, q;
	int counter = 0;
	char st[100];

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				val = va_arg(args, int);
				int_base_str(val, 10, st);
				for (q = 0; st[q]; q++)
				{
					_putc(st[q]);
					counter++;
				}
			}
			else if (*format == 'i')
			{
				val = va_arg(args, int);
				int_base_str(val, 10, st);
				for (q = 0; st[q]; q++)
				{
					_putc(st[q]);
					counter++;
				}
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
}
/**
 * int_base_str - converts int to str
 * @num: num to be converted
 * @base: base of num
 * @str: buffer container
 * Return: 0
 */
void int_base_str(int num, int base, char str[])
{
	int i = 0;
	int j, sign;
	int digit;
	char temp;

	sign = num;
	if ((sign) < 0)
		num = -num;

	do {
		digit = num % base;
		if (digit < 10)
			str[i++] = digit + '0';
		else
			str[i++] = digit - 10 + 'a';
		} while ((num /= base) > 0);
		if (sign < 0)
			str[i++] = '-';

		str[i] = '\0';
		for (j = 0; j < i / 2; j++)
	{
			temp = str[j];
			str[j] = str[i - j - 1];
			str[i - j - 1] = temp;
	}
}
