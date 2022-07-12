#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * p_percent - print spesified taypes of data.
 * @list: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */
int p_percent(__attribute__((unused))va_list list)
{
int len = 0;
len += _putchar('%');
return (len);
}

/**
 * p_octal - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_octal(va_list ap)
{
int num, plen = 0, j, size = 0, i = 0;
int *s;
num = va_arg(ap, int);
if (num < 0)
num = num * -1;
j = num;
while (j != 0)
{
j = j / 10;
size++;
}
s = (int *)malloc(sizeof(int) * size + 1);
while (num >= 8)
{
s[i] = num % 8;
num = num / 8;
i++;
}
s[i] = num;
while (i >= 0)
{
plen += _putchar(s[i] + '0');
i--;
}
free (s);
return (plen);
}
