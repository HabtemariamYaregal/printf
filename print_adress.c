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
	char *hexx;
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
	hexx = (char *)malloc(sizeof(char) * j + 1);
	while (num >= 16)
	{
		hexx[i] = Representation[num % 16];
		num /= 16;
		i++;
	}
	hexx[i] = Representation[num];
	plen += _puts("0x");
	while (i >= 0)
	{
		plen += _putchar(hexx[i]);
		i--;
	}
	free(hexx);
	return (plen);
}
