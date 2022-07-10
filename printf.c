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

	unsigned int j = 0, i = 0, k = 0, m;
	char *str;

	va_start(ap, format);
	while (format && format[j] != '\0')
	{
		while (format[j] != '%')
		{	printf("%c", format[j]);
			j++;
			i++;	}
		j++;
		switch (format[j])
		{ case 'c':
			i++;
			printf("%c", va_arg(ap, int));
			break;
		case 'i':
			i++;
			printf("%i", va_arg(ap, int));
			break;
		case 'd':
			m = va_arg(ap, int);
			printf("%d", m);
			while (m != 0)
			{	m /= 10;
				i++; }
			break;
		case's':
			str = va_arg(ap, char*);
			while (str[k])
			{	k++;
				i++;	}
			printf("%s", str);
			break;	}
		j++;
	}
	printf("\n%d\n", i);
	va_end(ap);
}
