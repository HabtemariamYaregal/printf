#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int j, k;
    j = _printf("ytl%cml%ulg   k%s", 'B', -10, "stSchool");
    k = printf("ytl%cml%Xlg   k%s", 'B', 10865, "stSchool");
    printf("\n%d %d", j, k);
    return (0);
}
