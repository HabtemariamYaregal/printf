#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * p_num - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_num(va_list ap)
{
int n;
int len = 0;
n = va_arg(ap, int);
len += _putchar(n);
return (len);
}
