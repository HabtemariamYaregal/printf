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
	va_list ap;

	unsigned int j = 0, i = 0, k = 0;
	char *str;

	va_start(ap, format);
	while (format && format[j] != '\0')
	{
		while (format[j] != '%')
		{
			printf("%c", format[j]);
			j++;
			i++;	}
		j++;
		switch (format[j])
		{ case 'c':
			printf("%c", va_arg(ap, int));
			i++;
			break;
		case's':
			str = va_arg(ap, char*);
			printf("%s", str);
			while (str[k])
			{	k++;
				i++;	}
			break;	}
		j++;
	}
	va_end(ap);
	return (i);
}
