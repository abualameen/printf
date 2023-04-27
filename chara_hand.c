#include "main.h"
/**
 * chara_hand - handles characters to be printer in the formated str
 * @format_ptr: pointer to the formated str pointer
 * @args: arguments list
 * Return: 0
 */

int chara_hand(const char **format_ptr, va_list args)
{
	const char *format = *format_ptr;
	char c;
	int counter = 0;

	if (*format == '\0')
	{
		return (0);
	}
	c = va_arg(args, int);
	_putc(c);
	counter++;
	*format_ptr = format;
	return (counter);
}
