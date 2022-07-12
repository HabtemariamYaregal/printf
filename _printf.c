#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - print spesified taypes of data.
 * @format: contain data format of individual argument.
 * struct convert - stricture.
 *
 * Return: Number of charactors printed.
 */
int _printf(const char *format, ...)
{
int print_len;
/*convert f_list - convert*/
struct convert f_list[] = {
{"c", p_char},
{"s", p_string},
{"%", p_percent},
{"d", p_num},
{"i", p_num},
{"o", p_octal},
{"u", p_decimal},
{"x", p_hexd},
{"X", p_heXd},
{NULL, NULL}
};
va_list ap;
if (format == NULL)
return (-1);
va_start(ap, format);
/*Calling _switch  function*/
print_len = _switch(format, f_list, ap);
va_end(ap);
return (print_len);
}
