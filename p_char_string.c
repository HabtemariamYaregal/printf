#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * p_string - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */
int p_nonp(va_list ap)
{
	static const char Representation[] = "013456789ABCDEF";
	char *s;
	int i = 0, j = 0, k, nlen;
	int hex[2];

	s = va_arg(ap, char*);
	while (s[i] != '\0')
	{
		if (s[i] <= 32 || s[i] >= 127)
		{
			k = s[i];
			nlen += _putchar('\');
			nlen += _putchar('x');
			if (k <= 16)
			{
				nlen += _putchar('0');
				nlen += Representation[k % 16];
			}
			if (k > 16)
			{
				while (k >= 16)
				{
					hex[j] = Representation[k % 16];
					k /= 16;
					j++;
				}
				hex[j] = Representation[k];
				while (j >= 0)
				{
					nlen += _putchar(hex[j]);
					j--;
				}
			}
		}
		nlen += _putchar(s[i]);
		i++;
	}
	return (nlen);
}
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
