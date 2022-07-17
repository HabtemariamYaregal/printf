#include "main.h"
/**
 * p_intiger - print spesified taypes of data.
 * @iip: contain data format of individual argument.
 * @f: flag;
 * @width: width.
 *
 * Return: Number of charactors printed.
 */

int p_intiger(va_list iip, flag_t *f, int width)
{
	long int no, temp;
	int j = 0, ilen = 0;
	unsigned long int nnum;

	if (f->lng == 1)
		no = va_arg(iip, long int);
	else if (f->shrt == 1)
		no = va_arg(iip, int);
	else
		no = va_arg(iip, int);
	for (temp = no; temp != 0; temp /= 10)
		j++;
	if (no == 0)
		j = 1;
	if (no < 0)
		j++;
	if (width > j)
		ilen += print_gap(j, width, f);
	if (f->space == 1 && f->plus == 0 && no >= 0)
		ilen += _putchar(' ');
	if (f->plus == 1 && no >= 0)
		ilen += _putchar('+');
	if (no < 0)
	{	nnum = no * -1;
		ilen += _putchar('-');	}
	else
		nnum = no;
	ilen += print_numm(nnum);
	return (ilen);
}
/**
 * print_gap - print spesified taypes of data.
 * @wd: width.
 * @nuum: num length.
 * @f: flag;
 *
 * Return: Number of charactors printed.
 */
int print_gap(int nuum, int wd, flag_t *f)
{
	int len = 0, gap;

	if (f->hash == 1 || f->plus == 1 || f->space == 1)
		gap = wd - nuum - 1;
	else if (nuum < 0)
		gap = wd - nuum - 1;
	else
		gap = wd - nuum;
	while (gap > 0)
	{
		len += _putchar(' ');
		gap--;
	}
	return (len);
}
/**
 * print_numm - print spesified taypes of data.
 * @nm: number to be printed.
 *
 * Return: Number of charactors printed.
 */
int print_numm(unsigned long int nm)
{
	char *v;
	unsigned long int temp;
	int i = 0, j = 0, vlen = 0;

	if (nm == 0)
	{
		vlen += _putchar('0');
		return (vlen);
	}
	for (temp = nm; temp != 0; temp /= 10)
		j++;
	v = (char *)malloc(sizeof(char) * j + 1);
	if (v == NULL)
		return (-1);
	while (nm != 0)
	{
		v[i] = (nm % 10) + '0';
		nm /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		vlen += _putchar(v[i]);
		i--;
	}
	free(v);
	return (vlen);
}
/**
 * p_binary - print spesified taypes of data.
 * @bnp: contain data format of individual argument.
 * @f: flag;
 * @width: width length.
 *
 * Return: Number of charactors printed.
 */
int p_binary(va_list bnp, flag_t *f, int width)
{
	char *bn;
	unsigned int num, n;
	int i = 0, j, k, len = 0;
	(void)f;
	(void)width;

	num = va_arg(bnp, unsigned int);
	n = num;
	if (num == 0)
	{
		len += _putchar('0');
		return (len);
	}
	while (n > 0)
	{
		n = n / 2;
		k++;
	}
	bn = (char *)malloc(sizeof(char) * k);
	if (bn == NULL)
		return (-1);
	while (num > 0)
	{
		bn[i] = (num % 2) + '0';
		num = num / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		len += _putchar(bn[j]);
	free(bn);
	return (len);
}
