#include "main.h"
/**
 * str_hand - handles strings
 * @format_ptr - format ptr to forrmat
 * @args: args list
 * Return: 0
 */

int str_hand(const char **format_ptr, va_list args)
{
	const char *format;
	char *s;
	int counter = 0;
		
	format = *format_ptr;
	s = va_arg(args, char *);
	while (*s)
	{
		_putc(*s++);
		counter++;
	}
	*format_ptr = format + 1;
	return (counter);
}
