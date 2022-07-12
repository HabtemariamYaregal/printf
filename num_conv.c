#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
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
	free(s);
	return (plen);
}
/**
 * p_decimal - print spesified taypes of data.
 * @bp: contain data format of individual argument.
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
	free(v);
	return (ilen);
}
/**
 * p_heXd - print spesified taypes of data.
 * @hp: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */
int p_heXd(va_list hp)
{
	static const char Representation[] = "0123456789ABCDEF";
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
	while (num >= 16)
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
	static const char Representation[] = "0123456789abcdef";
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
	while (num >= 16)
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

