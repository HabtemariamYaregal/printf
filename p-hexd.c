#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * p_heXd - print spesified taypes of data.
 * @hp: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_heXd(va_list hp)
{
static char Representation[] = "0123456789ABCDEF";
int num, temp, hlen = 0, i = 0, j = 0;
char *heX;
num = va_arg(hp, int);
temp = num;	
while (temp != 0)
{
temp /= 16;
j++;
}
heX = (char *)malloc(sizeof(char) * j);
while (num >= 15)
{
heX[i] = Representation[num % 16];
num /= 16;
i++;
}
heX[i] = Representation[num];
while (i >= 0)
{
hlen += _putchar(heX[i]);
i--;
}
free(heX);
return (hlen);
}

/**
 * p_hexd - print spesified taypes of data.
 * @hp: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_hexd(va_list hp)
{
static char Representation[] = "0123456789abcdef";
int num, temp, hlen = 0, i = 0, j = 0;
char *hex;
num = va_arg(hp, int);
temp = num;
while (temp != 0)
{
temp /= 16;
j++;
}
hex = (char *)malloc(sizeof(char) * j + 1);
while (num >= 15)
{
hex[i] = Representation[num % 16];
num /= 16;
i++;
}
hex[i] = Representation[num];
while (i >= 0)
{
hlen += _putchar(hex[i]);
i--;
}
free(hex);
return (hlen);
}
