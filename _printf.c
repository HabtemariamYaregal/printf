#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * _printf - print spesified taypes of data.
 * @format: contain data format of individual argument.
 * struct convert - stricture.
 *
 * Return: Number of charactors printed.
 */
int _printf(const char *format, ...)
{
	int print_len;
	/*convert f_list - convert*/
	struct convert f_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"o", p_octal},
		{"u", p_decimal},
		{"x", p_hexd},
		{"X", p_heXd},
		{NULL, NULL}
	};
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	/*Calling _switch  function*/
	print_len = _switch(format, f_list, ap);
	va_end(ap);
	return (print_len);
}

/**
 * _switch - print spesified taypes of data.
 * @format: contain data format of individual argument.
 * @f_list: function list
 * @ap: va_list'
 *
 * Return: Number of charactors printed.
 */

int _switch(const char *format, conv f_list[], va_list ap)
{
	int i, j, prt, print_no;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].str != NULL; j++)
			{
				if (format[i + 1] == f_list[j].str[0])
				{
					prt = f_list[j].fun(ap);
					if (prt == -1)
						return (-1);
					print_no += prt;
					break;
				}
			}
			if (f_list[j].str == NULL && format[j + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					print_no += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
			print_no += _putchar(format[i]);
	}
	return (print_no);
}

/**
 * p_string - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_string(va_list ap)
{
	char *strg;
	int i = 0, len = 0;

	strg = va_arg(ap, char*);
	while (strg[i] != '\0')
	{
		len += _putchar(strg[i]);
		i++;
	}
	return (len);
}
/**
 * p_char - print spesified taypes of data.
 * @ap: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_char(va_list ap)
{
	char c;
	int len = 0;

	c = va_arg(ap, int);
	len += _putchar(c);
	return (len);
}
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
	int num, plen = 0, j, size = 0, en, i = 0;
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
	free (s);
	return (plen);
}
int p_decimal(va_list bp)
{
	int i = 0, j = 0, ilen = 0;
	unsigned int num, *v, size;

	num = va_arg(bp, unsigned int);
	if (num < 0)
	{
		num = UINT_MAX - num + 1;
	}
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
	free (v);
	return (ilen);
}
int p_heXd(va_list hp)
{
	static char Representation[] = "0123456789ABCDEF";
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
	while (num >= 15)
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
int p_hexd(va_list hp)
{
        static char Representation[] = "0123456789abcdef";
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
        while (num >= 15)
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

