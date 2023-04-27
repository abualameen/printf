#include "main.h"
/**
 * unsignedint_bin_hand - handles unsigned in to binary
 * @format_ptr: format str
 * @args: args list
 * Return: 0
 */

int unsignedint_bin_hand(const char **format_ptr, va_list args)
{
	int val, q;
	int counter = 0;
	char st[100];
	const char *format;

	format = *format_ptr;
	val = va_arg(args, int);
	unint_base_str(val, 2, st);
	for (q = 0; st[q]; q++)
	{
		_putc(st[q]);
		counter++;
	}
	format++;
	return (counter);
}
