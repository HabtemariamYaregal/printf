#include "main.h"

/**
 * p_reversed - print spesified taypes of data.
 * @prp: contain data format of individual argument.
 * @f: flag.
 * @width: width.
 *
 * Return: Number of charactors printed.
 */

int p_reversed(va_list prp, flag_t *f, int width)
{
	char *sttr, *ppt;
	int rlen = 0;

	(void)f;
	(void)width;
	sttr = va_arg(prp, char*);
	if (sttr == NULL)
		return (-1);
	ppt = rev_string(sttr);
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
 * @width: width.
 *
 * Return: Number of charactors printed.
 */

int rot13(va_list rop, flag_t *f, int width)
{
	int i, x;
	char *strr;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	(void)f;
	(void)width;

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
 * @width: width.
 *
 * Return: Number of charactors printed.
 */
int p_nonp(va_list pnp, flag_t *f, int width)
{
	static const char Representation[] = "0123456789ABCDEF";
	char *ss;
	int i = 0, j = 0, k, nlen = 0, hex[2];
	(void)f;
	(void)width;

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
			if (k < 16)
			{	nlen += _putchar('0');
				nlen += _putchar(Representation[k]);	}
			if (k >= 16)
			{
				hex[j] = Representation[k % 16];
				k /= 16;
				j++;
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
 * @width: width.
 *
 * Return: Number of charactors printed.
 */

int p_string(va_list psp, flag_t *f, int width)
{
	char *strg;
	int i = 0, j, len = 0;

	(void)f;
	strg = va_arg(psp, char*);
	for (j = 0; strg[j] != '\0'; j++)
	{}
	if (f->dash != 1)
	{
		if (width > j)
			len += print_gap(j, width, f);	}
	if (strg == NULL)
		strg = "(null)";
	while (strg[i] != '\0')
	{
		len += _putchar(strg[i]);
		i++;
	}
	if (f->dash == 1)
	{
		if (width > j)
			len += print_gap(j, width, f);	}
	return (len);
}
/**
 * p_char - print spesified taypes of data.
 * @pcp: contain data format of individual argument.
 * @f: flag.
 * @width: width.
 *
 * Return: Number of charactors printed.
 */
int p_char(va_list pcp, flag_t *f, int width)
{
	char c;
	int len = 0, j;
	(void)f;

	c = va_arg(pcp, int);
	if (c == '\0')
		j = 1;
	else
		j = 1;
	if (f->dash != 1)
	{
		if (width > 1)
			len += print_gap(j, width, f);	}
	len += _putchar(c);
	if (f->dash == 1)
	{
		if (width > j)
			len += print_gap(j, width, f);	}
	return (len);
}
