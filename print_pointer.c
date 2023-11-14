#include "main.h"

/**
 * print_unsigned - prints value of pointer var
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_pointer(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padding = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padding_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(arguments, void *);

	CHECK(width);
	CHECK(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	CHECK(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
		padding = '0';
	if (flags & PLUS_FLAG)
		extra_c = '+', length++;
	else if (flags & SPACE_FLAG)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buff, ind, length,
		width, flags, padding, extra_c, padding_start));
}
