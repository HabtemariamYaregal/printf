#include "main.h"
/**
 * p_octal - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int p_octal(va_list pop, flag *f)
{
	unsigned long int num1, j;
	int plen = 0, size = 0, i = 0;
	int *sv;
	(void)f;

	num1 = va_arg(pop, unsigned int);
	if (num1 == 0)
	{
		_putchar('0');
		return (1);
	}
	j = num1;
	while (j != 0)
	{
		j = j / 10;
		size++;
	}
	sv = (int *)malloc(sizeof(int) * size + 1);
	if (sv == NULL)
		return (-1);
	while (num1 >= 8)
	{
		sv[i] = num1 % 8;
		num1 = num1 / 8;
		i++;
	}
	sv[i] = num1;
	while (i >= 0)
	{
		plen += _putchar(sv[i] + '0');
		i--;
	}
	free(sv);
	return (plen);
}
/**
 * p_decimal - print spesified taypes of data.
 * @bpp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */
int p_decimal(va_list bpp, flag *f)
{
	int *v, i = 0, j = 0, ilen = 0;
	unsigned int num2, size;
	(void)f;

	num2 = va_arg(bpp, unsigned int);
	size = num2;
	while (size != 0)
	{
		size /= 10;
		j++;
	}
	v = (int *)malloc(sizeof(int) * j);
	if (v == NULL)
		return (-1);
	while (num2 >= 9)
	{
		v[i] = num2 % 10;
		num2 /= 10;
		i++;
	}
	v[i] = num2;
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
 * @php: contain data format of individual argument.
 * @f: flag pointer.
 *
 * Return: Number of charactors printed.
 */
int p_heXd(va_list php, flag *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	unsigned long int num3, temp2;
	int hlen = 0, i = 0, j = 0;
	char *heX;
	(void)f;

	num3 = va_arg(php, unsigned int);
	temp2 = num3;
	while (temp2 != 0)
	{
		temp2 /= 16;
		j++;
	}
	heX = (char *)malloc(sizeof(char) * j);
	if (heX == NULL)
		return (-1);
	while (num3 >= 16)
	{
		heX[i] = Representation[num3 % 16];
		num3 /= 16;
		i++;
	}
	heX[i] = Representation[num3];
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
 * @hpp: contain data format of individual argument.
 * @f: flag pointer.
 *
 * Return: Number of charactors printed.
 */
int p_hexd(va_list hpp, flag *f)
{
	static const char Representation[] = "0123456789abcdef";
	unsigned long int numm, temmp;
	int hlen = 0, i = 0, j = 0;
	char *hex;
	(void)f;

	numm = va_arg(hpp, unsigned int);
	temmp = numm;
	while (temmp != 0)
	{
		temmp /= 16;
		j++;
	}
	hex = (char *)malloc(sizeof(char) * j + 1);
	while (numm >= 16)
	{
		hex[i] = Representation[numm % 16];
		numm /= 16;
		i++;
	}
	hex[i] = Representation[numm];
	while (i >= 0)
	{
	hlen += _putchar(hex[i]);
		i--;
	}
	free(hex);
	return (hlen);
}
