#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>

struct convert{
        char *str;
        int (*fun)(va_list);
};
typedef struct convert conv;

int _putchar(char c);
int p_char(va_list ap);
int p_string(va_list ap);
int p_percent(va_list);
int _switch(const char *format, struct convert f_list[], va_list ap);
int _printf(const char *format, ...);
#endif
