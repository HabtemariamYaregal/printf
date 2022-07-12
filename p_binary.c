#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_int_binary - prints an integer.
 * @ap: argument
 * Return: 0
 */
int print_int_binary(va_list ap)
{

unsigned int n = va_arg(ap, unsigned int);
unsigned int printed;

print_binary(n, &printed);
print_binary(n, &printed);

return (printed);
}
/**
 * print_binary - function that prints the binary representation of a number
 * @n: number to be printed in binary
 * @printed: hold the number of characters printed
 */
void print_binary(unsigned int n, unsigned int *printed)
{
if (n > 1)
{
*printed += 1;
print_binary(n >> 1, printed);
}
_putchar((n & 1) + '0');
}
