#include "main.h"

/**
 * _printf - print spesified taypes of data.
 * @format: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */
int _printf(const char *format, ...)
{
int print_len;
/*convert f_list - convert*/
conv f_list[] = {
{"c", p_char},
{"s", p_string},
{"S", p_nonp},
{"p", p_pointer},
{"%", p_percent},
{"r", p_reversed},
{"d", p_intiger},
{"i", p_intiger},
{"o", p_octal},
{"u", p_decimal},
/*{"b", print_int_binary},*/
{"x", p_hexd},
{"X", p_heXd},
{"R", rot13},
{NULL, NULL}
};
flag flags = {0, 0, 0, 0, 0};
va_list ap;
if (format == NULL)
return (-1);
va_start(ap, format);
/*Calling _switch  function*/
print_len = _switch(format, f_list, ap, flags);
va_end(ap);
return (print_len);
}
