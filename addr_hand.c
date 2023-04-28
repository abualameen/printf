#include "main.h"
#include <stdint.h>
/**
 * addr_hand - handle address specifier
 * @format_ptr: pointer to format pointer
 * @args: argu list
 * Return: 0
 */

int addr_hand(const char **format_ptr, va_list args)
{
	const char *format;
	int val, q;
	int counter = 0;
	char st[100];

	format = *format_ptr;
	switch (format[-1])
	{
		case 'x':
		case 'p':
			val = va_arg(args, uint32_t);
			break;
		case 'X':
			val = va_arg(args, uint32_t);
			break;
		case 'l':
		case 'z':
			val = va_arg(args, uint64_t);
			break;
		default:
			val = va_arg(args, unsigned int);
			break;
	}
	_putc('0');
	counter++;
	_putc('x');
	counter++;
	unint_base_str(val, 16, st);
	for (q = 0; st[q]; q++)
	{
		_putc(st[q]);
		counter++;
	}
	format++;
	return (counter);
}
