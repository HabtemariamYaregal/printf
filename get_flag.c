#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * get_flag - print spesified taypes of data.
 * @s: contain data format of individual argument.
 * @f: flag;
 *
 * Return: Number of charactors printed.
 */

int get_flag(char s, flag *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	return (i);
}
