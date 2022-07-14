#include "main.h"

/**
 * p_reversed - print spesified taypes of data.
 * @rp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int p_reversed(va_list rp, flag *f)
{
	char *str, *ppt;
	int rlen = 0;
	(void)f;

	str = va_arg(rp, char*);
	if (str == NULL)
		return (-1);
	ppt = rev_string(str);
	if (ppt == NULL)
		return (-1);
	for (rlen = 0; ppt[rlen] != '\0'; rlen++)
		_putchar(ppt[rlen]);
	free(ppt);
	return (rlen);
}
/**
 * rot13 - print spesified taypes of data.
 * @rp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int rot13(va_list rp, flag *f)
{
	int i, x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)f;

	str = va_arg(rp, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}
/**
 * p_nonp - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */
int p_nonp(va_list ap, flag *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	char *s;
	int i = 0, j = 0, k, nlen, hex[2];
	(void)f;

	s = va_arg(ap, char*);
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			k = s[i];
			nlen += _putchar('\\');
			nlen += _putchar('x');
			if (k <= 16)
			{	nlen += _putchar('0');
				nlen += _putchar(Representation[k]);	}
			if (k > 16)
			{
				while (k >= 16)
				{	hex[j] = Representation[k % 16];
					k /= 16;
					j++;	}
				hex[j] = Representation[k];
				while (j >= 0)
				{
					nlen += _putchar(hex[j]);
					j--;
				}
			}
		}
		else
			nlen += _putchar(s[i]);
		i++;
	}
	return (nlen);
}
/**
 * p_string - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 * @f: flag argument.
 *
 * Return: Number of charactors printed.
 */

int p_string(va_list ap, flag *f)
{
	char *strg;
	int i = 0;

	(void)f;
	strg = va_arg(ap, char*);
	if (strg == NULL)
		strg = "(null)";
	while (strg[i] != '\0')
	{
		_putchar(strg[i]);
		i++;
	}
	return (i);
}
/**
 * p_char - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int p_char(va_list ap, flag *f)
{
	char c;
	(void)f;

	c = va_arg(ap, int);
	_putchar(c);
	return (1);
}
