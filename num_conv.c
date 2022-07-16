#include "main.h"
/**
 * p_octal - print spesified taypes of data.
 * @ocp: contain data format of individual argument.
 * @f: flag.
 *
 * Return: Number of charactors printed.
 */

int p_octal(va_list ocp, flag_t *f)
{
	unsigned long int num1, j;
	int plen = 0, size = 0, i = 0;
	int *sv;

	if (f->lng == 1)
		num1 = va_arg(ocp, unsigned long int);
	else if (f->shrt == 1)
		num1 = va_arg(ocp, unsigned int);
	else
		num1 = va_arg(ocp, unsigned int);
	if (f->hash == 1 && num1 > 0)
		plen += _putchar('0');
	if (num1 == 0)
	{	plen += _putchar('0');
		return (plen);	}
	j = num1;
	while (j != 0)
	{	j = j / 10;
		size++;	}
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
int p_decimal(va_list bpp, flag_t *f)
{
	int *v, i = 0, j = 0, ilen = 0;
	unsigned long int num2, size;
	(void)f;

	if (f->lng == 1)
		num2 = va_arg(bpp, unsigned long int);
	else if (f->shrt == 1)
		num2 = va_arg(bpp, unsigned int);
	else
		num2 = va_arg(bpp, unsigned int);
	size = num2;
	if (size == 0)
	{	ilen += _putchar('0');
		return (ilen);	}
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
int p_heXd(va_list php, flag_t *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	unsigned long int num3, temp2;
	int hlen = 0, i = 0, j = 0;
	char *heX;

	if (f->lng == 1)
		num3 = va_arg(php, unsigned long int);
	else if (f->shrt == 1)
		num3 = va_arg(php, unsigned int);
	else
		num3 = va_arg(php, unsigned int);
	if (f->hash == 1 && num3 > 0)
	{
		hlen += _putchar('0');
		hlen += _putchar('X');
	}
	temp2 = num3;
	if (temp2 == 0)
	{	hlen += _putchar('0');
		return (hlen);	}
	while (temp2 != 0)
	{	temp2 /= 16;
		j++;	}
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
int p_hexd(va_list hpp, flag_t *f)
{
	static const char Representation[] = "0123456789abcdef";
	unsigned long int numm, temmp;
	int hlen = 0, i = 0, j = 0;
	char *hex;

	if (f->lng == 1)
		numm = va_arg(hpp, unsigned long int);
	else if (f->shrt == 1)
		numm = va_arg(hpp, unsigned int);
	else
		numm = va_arg(hpp, unsigned int);
	if (f->hash == 1 && numm > 0)
	{
		hlen += _putchar('0');
		hlen += _putchar('x');
	}
	temmp = numm;
	if (temmp == 0)
	{	hlen += _putchar('0');
		return (hlen);	}
	while (temmp != 0)
	{	temmp /= 16;
		j++;	}
	hex = (char *)malloc(sizeof(char) * j + 1);
	while (numm >= 16)
	{	hex[i] = Representation[numm % 16];
		numm /= 16;
		i++;	}
	hex[i] = Representation[numm];
	while (i >= 0)
	{
	hlen += _putchar(hex[i]);
		i--;
	}
	free(hex);
	return (hlen);
}
