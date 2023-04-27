#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int format_hand(const char **format_ptr, va_list args);
int chara_hand(const char **format_ptr, va_list args);
int _putc(char c);
int str_hand(const char **format_ptr, va_list args);
int perc_hand(void);
void int_base_str(int num, int base, char str[]);
int deci_hand(const char **format, va_list args);
int int_hand(const char **format_ptr, va_list args);

#endif
