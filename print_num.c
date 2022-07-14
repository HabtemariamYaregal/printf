#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"
/**
 * p_intiger - print spesified taypes of data.
 * @ip: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_intiger(va_list ip)
{
	int no, ilen = 0, i = 0, j = 0, temp;
	char *p;
	unsigned int num;

	no = va_arg(ip, int);
	temp = num;
	if (no < 0)
	{
		num = no * -1;
		ilen += _putchar('-');
	}
	else
		num = no;
	if (num == 0)
		ilen += _putchar('0');
	while (temp != 0)
	{
		temp /= 10;
		j++;
	}
	p = (char *)malloc(sizeof(char) * j + 1);
	if (p == NULL)
		return (-1);
	while (num != 0)
	{
		p[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ilen += _putchar(p[i]);
		i--;
	}
	free(p);
	return (ilen);
}
