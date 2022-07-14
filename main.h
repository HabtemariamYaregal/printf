#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
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
int p_char(va_list pcp, flag *f);
int p_numbers(va_list vap, flag *f);
int p_string(va_list psp, flag *f);
int p_percent(va_list, flag *f);
int print_int_binary(va_list ap);
void print_binary(unsigned int n, unsigned int *printed);
int p_octal(va_list ocp, flag *f);
int p_decimal(va_list dpp, flag *f);
int p_hexd(va_list hpp, flag *f);
int p_heXd(va_list php, flag *f);
int p_nonp(va_list pnp, flag *f);
int p_reversed(va_list prp, flag *f);
int rot13(va_list rop, flag *f);
int get_flag(char s, flag *f);
int _puts(char *str);
int p_intiger(va_list iip, flag *f);
int p_pointer(va_list ptp, flag *f);
char *rev_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _switch(const char *format, conv f_list[], va_list ap, flag flags);
int _printf(const char *format, ...);
#endif
