#include "main.h"
/**
 * p_pointer - print spesified taypes of data.
 * @ptp: contain data fotrmat of individual argument.
 *
 * Return: Number of charactors printed.
 */
int p_pointer(va_list ptp, flag *f)
{
	static const char Representation[] = "0123456789ABCDEF";
	unsigned long int nuum, teemp;
	char *hexx;
	int i = 0, j = 0, plen = 0;
	(void)f;

	nuum = va_arg(ptp, unsigned long int);
	if (!nuum)
		return (_puts("(nil)"));
	teemp = nuum;
	while (teemp != 0)
	{
		temp /= 16;
		j++;
	}
	hexx = (char *)malloc(sizeof(char) * j + 1);
	while (nuum >= 16)
	{
		hexx[i] = Representation[nuum % 16];
		nuum /= 16;
		i++;
	}
	hexx[i] = Representation[nuum];
	plen += _puts("0x");
	while (i >= 0)
	{
		plen += _putchar(hexx[i]);
		i--;
	}
	free(hexx);
	return (plen);
}
