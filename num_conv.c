#include "main.h"
/**
 * p_octal - print spesified taypes of data.
 * @ocp: contain data format of individual argument.
 * @f: flag.
 * @width: width length.
 *
 * Return: Number of charactors printed.
 */

int p_octal(va_list ocp, flag_t *f, int width)
{
	unsigned long int num1, temp;
	int plen = 0, i = 0, j = 0;
	int *sv;

	if (f->lng == 1)
		num1 = va_arg(ocp, unsigned long int);
	else if (f->shrt == 1)
		num1 = va_arg(ocp, unsigned int);
	else
		num1 = va_arg(ocp, unsigned int);
	for (temp = num1; temp != 0; temp /= 8)
		j++;
	if (num1 == 0)
		j = 1;
	if (f->dash != 1)
	{
		if (width > j)
		plen += print_gap(j, width, f);	}
	if (f->hash == 1 && num1 > 0)
		plen += _putchar('0');
	sv = (int *)malloc(sizeof(int) * j + 1);
	if (sv == NULL)
		return (-1);
	for ( ; num1 >= 8; num1 /= 8)
	{	sv[i] = num1 % 8;
		i++;	}
	sv[i] = num1;
	for ( ; i >= 0; i--)
		plen += _putchar(sv[i] + '0');
	if (f->dash == 1)
	{
		if (width > j)
			plen += print_gap(j, width, f);	}
	free(sv);
	return (plen);
}
/**
 * p_decimal - print spesified taypes of data.
 * @bpp: contain data format of individual argument.
 * @f: flag.
 * @width: width length.
 *
 * Return: Number of charactors printed.
 */
int p_decimal(va_list bpp, flag_t *f, int width)
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
	for (size = num2; size != 0; size /= 10)
		j++;
	if (num2 == 0)
		j = 1;
	if (f->dash != 1)
	{
		if (width > j)
			ilen += print_gap(j, width, f);	}
	v = (int *)malloc(sizeof(int) * j);
	if (v == NULL)
		return (-1);
	for ( ; num2 >= 9; num2 /= 10)
	{
		v[i] = num2 % 10;
		i++;
	}
	v[i] = num2;
	for (; i >= 0; i--)
		ilen += _putchar(v[i] + '0');
	if (f->dash == 1)
	{
		if (width > j)
			ilen += print_gap(j, width, f);	}
	free(v);
	return (ilen);
}
/**
 * p_heXd - print spesified taypes of data.
 * @php: contain data format of individual argument.
 * @f: flag pointer.
 * @width: width length
 *
 * Return: Number of charactors printed.
 */
int p_heXd(va_list php, flag_t *f, int width)
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
	{	hlen += _putchar('0');
		hlen += _putchar('X');	}
	for (temp2 = num3; temp2 != 0; temp2 /= 16)
		j++;
	if (num3 == 0)
		j = 1;
	if (f->dash != 1)
	{
		if (width > j)
			hlen += print_gap(j, width, f);	}
	heX = (char *)malloc(sizeof(char) * j);
	if (heX == NULL)
		return (-1);
	for (; num3 >= 16; num3 /= 16)
	{	heX[i] = Representation[num3 % 16];
		i++;	}
	heX[i] = Representation[num3];
	for ( ; i >= 0; i--)
		hlen += _putchar(heX[i]);
	if (f->dash == 1)
	{
		if (width > j)
			hlen += print_gap(j, width, f);	}
	free(heX);
	return (hlen);
}
/**
 * p_hexd - print spesified taypes of data.
 * @hpp: contain data format of individual argument.
 * @f: flag pointer.
 * @width: width length.
 *
 * Return: Number of charactors printed.
 */
int p_hexd(va_list hpp, flag_t *f, int width)
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
	{	hlen += _putchar('0');
		hlen += _putchar('x');	}
	for (temmp = numm; temmp != 0; temmp /= 16)
		j++;
	if (numm == 0)
		j = 1;
	if (f->dash != 1)
	{
		if (width > j)
			hlen += print_gap(j, width, f);	}
	hex = (char *)malloc(sizeof(char) * j + 1);
	for ( ; numm >= 16; numm /= 16)
	{	hex[i] = Representation[numm % 16];
		i++;	}
	hex[i] = Representation[numm];
	for ( ; i >= 0; i--)
		hlen += _putchar(hex[i]);
	if (f->dash == 1)
	{
		if (width > j)
			hlen += print_gap(j, width, f);	}
	free(hex);
	return (hlen);
}
