#include "main.h"

/**
 * print_int - prints int
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_int(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int check_neg = 0;
	long int n = va_arg(arguments, long int);
	unsigned long int x;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	x = (unsigned long int)n;

	if (n < 0)
	{
		x = (unsigned long int)((-1) * n);
		check_neg = 1;
	}

	while (x > 0)
	{
		buff[i--] = (x % 10) + '0';
		x /= 10;
	}

	i++;

	return (write_number(check_neg, i, buff, flags, width, precision, size));
}
