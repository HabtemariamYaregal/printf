#include "main.h"
/**
 * p_intiger - print spesified taypes of data.
 * @iip: contain data format of individual argument.
 * @f: flag;
 *
 * Return: Number of charactors printed.
 */

int p_intiger(va_list iip, flag *f)
{
	long int no, ilen = 0, i = 0, j = 0, ttemp;
	unsigned long int nnum;
	char *p;

	if (f->lng == 1)
		no = va_arg(iip, long int);
	else if (f->shrt == 1)
		no = va_arg(iip, int);
	else
		no = va_arg(iip, int);
	if (f->space == 1 && f->plus == 0 && no >= 0)
		ilen += _putchar(' ');
	if (f->plus == 1 && no >= 0)
		ilen += _putchar('+');
	if (no < 0)
	{	nnum = no * -1;
		ilen += _putchar('-');	}
	else
		nnum = no;
	if (nnum == 0)
	{	ilen += _putchar('0');
		return (1);	}
	ttemp = nnum;
	while (ttemp != 0)
	{	ttemp /= 10;
		j++;	}
	p = (char *)malloc(sizeof(char) * j + 1);
	if (p == NULL)
		return (-1);
	while (nnum != 0)
	{	p[i] = (nnum % 10) + '0';
		nnum /= 10;
		i++;
	}	i--;
	while (i >= 0)
	{	ilen += _putchar(p[i]);
		i--;	}
	free(p);
	return (ilen);
}
