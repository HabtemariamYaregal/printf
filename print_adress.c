#include "main.h"

/**
 * p_pointer - print spesified taypes of data.
 * @pb: contain data fotrmat of individual argument.
 *
 * Return: Number of charactors printed.
 */

int p_pointer(va_list pb, flag *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	unsigned long int num, temp;
	char *hex;
	int i = 0, j = 0, plen = 0;
	(void)f;

	num = va_arg(pb, unsigned long int);
	if (!num)
		return (_puts("(nil)"));
	temp = num;
	while (temp != 0)
	{
		temp /= 16;
		j++;
	}
	hex = (char *)malloc(sizeof(char) * j + 1);
	while (num >= 16)
	{
		hex[i] = Representation[num % 16];
		num /= 16;
		i++;
	}
	hex[i] = Representation[num];
	plen += _puts("0x");
	while (i >= 0)
	{
		plen += _putchar(hex[i]);
		i--;
	}
	free(hex);
	return (plen);
}

