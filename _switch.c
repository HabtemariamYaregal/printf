#include "main.h"

/**
 * _switch - print spesified taypes of data.
 * @format: contain data format of individual argument.
 * @f_list: function list
 * @ap: va_list.
 * @flags: flag stricture.
 *
 * Return: Number of charactors printed.
 */

int _switch(const char *format, conver_t f_list[], va_list ap, flag_t flags)
{
	int i, j, prt = 0, printed_no = 0, k;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	i++;
			while (get_flag(format[i], &flags))
				i++;
			while ((format[i] >= '1' && format[i] <= '9') || format[i] == '*')
			{
				if (format[i] == '*')
					k = va_arg(ap, int);
				else
					k = format[i] - '0';
				i++;	}
			for (j = 0; f_list[j].str != NULL; j++)
			{
				if (format[i] == f_list[j].str[0])
				{	prt = f_list[j].fun(ap, &flags, k);
					if (prt == -1)
						return (-1);
					printed_no += prt;
					break;	}
			}
			if (f_list[j].str == NULL && format[i] != ' ')
			{
				if (format[i] != '\0')
				{	printed_no += _putchar('%');
					printed_no += _putchar(format[i]);	}
				else
					return (-1);	}
		}
		else
			printed_no += _putchar(format[i]);
	}
	return (printed_no);
}
