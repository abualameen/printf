#include "main.h"

/**
 * format_hand - takes care of all format specifier
 * @format_ptr: pointer to the format pointer
 * @args: list
 * Return: 0
 */


int format_hand(const char **format_ptr, va_list args)
{
	const  char *format;
	int counter = 0;

	format = *format_ptr;
	switch (*format)
	{
		case 'c':
			counter = chara_hand(format_ptr, args);
			break;
		case 's':
			counter = str_hand(format_ptr, args);
			break;
		case '%':
			counter = perc_hand();
			break;
		default:
			counter += _putc('%');
			counter += _putc(*format);
			break;
	}
	return (counter);
}
