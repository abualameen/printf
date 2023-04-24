#include "main.h"
/**
 * _printf - function name
 * @format: formated string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	
	vprintfk(format, args);
	va_end(args);
	return (0);
}
