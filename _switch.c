#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * _switch - print spesified taypes of data.
 * @format: contain data format of individual argument.
 * @f_list: function list
 * @ap: va_list'
 *
 * Return: Number of charactors printed.
 */

int _switch(const char *format, conv f_list[], va_list ap)
{
int i, j, prt, print_no;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
for (j = 0; f_list[j].str != NULL; j++)
{
if (format[i + 1] == f_list[j].str[0])
{
prt = f_list[j].fun(ap);
if (prt == -1)
return (-1);
print_no += prt;
break;
}
}
if (f_list[j].str == NULL && format[j + 1] != ' ')
{
if (format[i + 1] != '\0')
{
_putchar(format[i]);
_putchar(format[i + 1]);
print_no += 2;
}
else
return (-1);
}
i++;
}
else
print_no += _putchar(format[i]);
}
return (print_no);
}
