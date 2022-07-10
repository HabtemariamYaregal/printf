#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - print spesified taypes of data.
 * @format: contain data format of individual argument.
 *
 * Return: Number of charactors printed.
 */
int _printf(const char *format, ...)
{
	int print_len;
	struct convert f_list[] = {
		{"c", p_char},
		{"s", p_string},
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
int _switch(const char *format, struct convert f_list[], va_list ap)
{
	int i, j, prt;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].str != NULL; j++)
			{
				if (format[i + 1] == f_list[j].str[0])
				{
					prt += f_list[j].fun(ap);
					break;
				}
			}
			if (f_list[j].str == NULL)
			{
				_putchar(format[i]);
			}
			i++;
		}
		else
			prt += _putchar(format[i]);
	}
	return (prt);
}
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
int p_char(va_list ap)
{
	char c;
	int len = 0;

	c = va_arg(ap, int);
	len += _putchar(c);
	return (len);
}


