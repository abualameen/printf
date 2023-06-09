#include "main.h"
int uni(void);
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
		case 'd':
			counter = deci_hand(format_ptr, args);
			break;
		case 'i':
			counter = int_hand(format_ptr, args);
			break;
		case 'b':
			counter = unsignedint_bin_hand(format_ptr, args);
			break;
		case 'u':
			counter = unsignedint_dec_hand(format_ptr, args);
			break;
		case 'o':
			counter = unsignedint_oct_hand(format_ptr, args);
			break;
		case 'x':
			counter = unsignedint_hex_hand(format_ptr, args);
			break;
		case 'X':
			counter = unsignedint_hex_hand_upp(format_ptr, args);
			break;
		case 'p':
			counter = addr_hand(format_ptr, args);
			break;
		case '\0':
			return (-1);
		default:
			counter += _putc('%');
			counter += _putc(*format);
			break;
	}
	return (counter);
}
/**
 * uni - unique
 * Return: 0
 */

int uni(void)
{
	return (0);
}
