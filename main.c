#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int a = 10;
	void *len = &a;

	_printf("%p", len);
	return (0);
}

