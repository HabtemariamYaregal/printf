#include "main.h"

/**
 * p_reversed - print spesified taypes of data.
 * @prp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int p_reversed(va_list prp, flag *f)
{
	char *str, *ppt;
	int rlen = 0;
	(void)f;

	str = va_arg(prp, char*);
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
 * @rop: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int rot13(va_list rop, flag *f)
{
	int i, x;
	char *strr;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)f;

	strr = va_arg(rop, char *);
	if (strr == NULL)
		return (-1);
	for (i = 0; strr[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (strr[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(strr[i]);
	}
	return (i);
}
/**
 * p_nonp - print spesified taypes of data.
 * @pnp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */
int p_nonp(va_list pnp, flag *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	char *ss;
	int i = 0, j = 0, k, nlen, hex[2];
	(void)f;

	ss = va_arg(pnp, char*);
	if (ss == NULL)
		return (-1);
	while (ss[i] != '\0')
	{
		if ((ss[i] > 0 && ss[i] < 32) || ss[i] >= 127)
		{
			k = ss[i];
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
			nlen += _putchar(ss[i]);
		i++;
	}
	return (nlen);
}
/**
 * p_string - print spesified taypes of data.
 * @psp: contain data format of individual argument.
 * @f: flag argument.
 *
 * Return: Number of charactors printed.
 */

int p_string(va_list psp, flag *f)
{
	char *strg;
	int i = 0;

	(void)f;
	strg = va_arg(psp, char*);
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
 * @psp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */
int p_char(va_list pcp, flag *f)
{
	char c;
	(void)f;

	c = va_arg(pcp, int);
	_putchar(c);
	return (1);
}
