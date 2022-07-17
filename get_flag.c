#include "main.h"
/**
 * get_flag - print spesified taypes of data.
 * @z: contain data format of individual argument.
 * @f: flag;
 *
 * Return: Number of charactors printed.
 */

int get_flag(char z, flag_t *f)
{
	int i = 0;

	switch (z)
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
		case 'l':
			f->lng = 1;
			i = 1;
			break;
		case 'h':
			f->shrt = 1;
			i = 1;
			break;
		case '0':
			f->zero = 1;
			i = 1;
			break;
		case '-':
			f->dash = 1;
			i = 1;
			break;
	}
	return (i);
}
