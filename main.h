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

#endif
