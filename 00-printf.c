#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - main entry of the function printf
 * @format: string containing the format
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vprintf(format, args);
	va_end(args);
	return (0);
}
