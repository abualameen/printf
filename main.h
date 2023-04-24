#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
void _printf(const char *format, ...);
int _putc(char c);
#define MAX 100
int vprintfk(const char *format, va_list args);
void int_base_str(int num, int base, char str[]);





#endif
