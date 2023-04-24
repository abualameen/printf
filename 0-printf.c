#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _vprintf - main entry of the function printf
 * @format: string containing the format
 * Return: 0
 */

int _vprintf(const char *format, va_list args)
{
	char c;
	char *s;
	/*int val, q;*/
	int counter = 0;
	int state = 0;
/*	char str[MAX];*/

	while (*format)
	{
		if (state == 0)
		{
			if (*format == '%')
			{
				state = 1;
			}
			else
			{
				_putc(*format);
				counter++;
			}
		}
		else if (state == 1)
		{
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
			/*	case 'd':
				
				case 'i':
					val = va_arg(args, int);
					printf("%d", val);
					int_base_str(val, 10, str);
					for (q = 0; str[q]; q++)
					{
						_putc(str[q]);
						counter++;
					}
					break;*/
				state = 0;
			}
		}
		format++;
	}
	va_end(args);
	return (counter);
}
