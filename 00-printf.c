#include "main.h"
#include <stddef.h>
/**
 * _printf - function name
 * @format: formated string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;
	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	
	vprintfk(format, args);
	va_end(args);
	return (0);
}
