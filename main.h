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
 * @lng: long int flag
 * @shrt: short num flag
 * @zero: zero flag
 * @dash: width flag
 */
struct flag_char
{
	int space;
	int plus;
	int hash;
	int lng;
	int shrt;
	int zero;
	int dash;
};
typedef struct flag_char flag_t;
/**
 * struct convert - holds conversion letters.
 * @str: The operator
 * @fun: The function associated
 */
struct convert
{
	char *str;
	int (*fun)(va_list, flag_t *f, int width);
};
typedef struct convert conver_t;

int print_numm(unsigned long int nm);
int print_gap(int num, int wd, flag_t *f);

int _putchar(char c);
int p_binary(va_list bnp, flag_t *f, int width);
int p_char(va_list pcp, flag_t *f, int width);
int p_numbers(va_list vap, flag_t *f, int width);
int p_string(va_list psp, flag_t *f, int width);
int p_percent(va_list, flag_t *f, int width);
int p_octal(va_list ocp, flag_t *f, int width);
int p_decimal(va_list dpp, flag_t *f, int width);
int p_hexd(va_list hpp, flag_t *f, int width);
int p_heXd(va_list php, flag_t *f, int width);
int p_nonp(va_list pnp, flag_t *f, int width);
int p_reversed(va_list prp, flag_t *f, int width);
int rot13(va_list rop, flag_t *f, int width);
int get_flag(char z, flag_t *f);
int _puts(char *str);
int p_intiger(va_list iip, flag_t *f, int width);
int p_pointer(va_list ptp, flag_t *f, int width);
char *rev_string(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int _switch(const char *format, conver_t f_list[], va_list ap, flag_t flags);
int _printf(const char *format, ...);
#endif
