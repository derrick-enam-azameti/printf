#include "main.h"

/**
 * print_percent - prints an unsigned num
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_binary(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, i, sum;
	unsigned int a[32];
	int count;

	CHECK(buff);
	CHECK(flags);
	CHECK(width);
	CHECK(precision);
	CHECK(size);

	x = va_arg(arguments, unsigned int);
	y = 2147483648;
	a[0] = x / y;
	i = 1;

	while (i < 32)
	{
		y /= 2;
		a[i] = (x / y) % 2;
		i++;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
