#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * p_string - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_string(va_list ap)
{
	char *strg;
	int i = 0, len = 0;

	strg = va_arg(ap, char*);

	while (strg[i] != '\0')
	{
	len += _putchar(strg[i]);
	i++;
	}
	return (len);
}
/**
 * p_char - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_char(va_list ap)
{
	char c;
	int len = 0;

	c = va_arg(ap, int);
	len += _putchar(c);
	return (len);
}
