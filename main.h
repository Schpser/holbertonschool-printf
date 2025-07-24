#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int print_number(int n);
int print_int(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int _printf(const char *format, ...);

unsigned int print_binary(va_list args);

#endif /*MAIN_H*/
