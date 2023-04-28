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
	int q = 0;
	void *val;
	int counter = 0;
	char st[sizeof(void *) * 2 + 1];
	unsigned long num;
	unsigned long base = 16;
	char hex_digits[] = "0123456789abcdef";
	char buf[1024];
	int len = 0;

	format = *format_ptr;
	val = va_arg(args, void *);
	num = (unsigned long) val;
	do {
		st[q++] = hex_digits[num % base];
		num /= base;
	} while (num);
	st[q] = '\0';
	buf[len++] = '0';
	buf[len++] = 'x';
	for (q = str_len(st) - 1; q >= 0; q--)
	{
		buf[len++] = st[q];
	}
	for (q = 0; q < len; q++)
	{
		counter += _putc(buf[q]);
	}
	*format_ptr = format;
	return (counter);
}
