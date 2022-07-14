#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
/**
 * struct flag_char - holds conversion letters.
 * @space: space flag
 * @plus: plus flag
 * @hash: hash flag
 */

struct flag_char
{
	int space;
	int plus;
	int hash;
};
typedef struct flag_char flag;
/**
 * struct convert - holds conversion letters.
 * @str: The operator
 * @fun: The function associated
 */

struct convert
{
	char *str;
	int (*fun)(va_list, flag *f);
};
typedef struct convert conv;

int _putchar(char c);
int p_char(va_list ap, flag *f);
int p_numbers(va_list ap, flag *f);
int p_string(va_list ap, flag *f);
int p_percent(va_list, flag *f);
int print_int_binary(va_list ap);
void print_binary(unsigned int n, unsigned int *printed);
int p_octal(va_list ap, flag *f);
int p_decimal(va_list bp, flag *f);
int p_hexd(va_list hp, flag *f);
int p_heXd(va_list hp, flag *f);
int p_nonp(va_list ap, flag *f);
int p_reversed(va_list rp, flag *f);
int rot13(va_list rp, flag *f);
int get_flag(char s, flag *f);
int _puts(char *str);
int p_intiger(va_list ip, flag *f);
int p_pointer(va_list pb, flag *f);
char *rev_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _switch(const char *format, conv f_list[], va_list ap, flag flags);
int _printf(const char *format, ...);
#endif
