#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * p_decimal - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_decimal(va_list bp)
{
int *v, i = 0, j = 0, ilen = 0;
unsigned int num, size;
num = va_arg(bp, unsigned int);
size = num;
while (size != 0)
{
size /= 10;
j++;
}
v = (int *)malloc(sizeof(int) * j);
while (num >= 9)
{
v[i] = num % 10;
num /= 10;
i++;
}
v[i] = num;
while (i >= 0)
{
ilen += _putchar(v[i] + '0');
i--;
}
free (v);
return (ilen);
}
