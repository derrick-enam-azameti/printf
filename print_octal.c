#include "main.h"

/**
 * print_octal - prints unsigned number in octal form
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_octal(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arguments, unsigned long int);
	unsigned long int f_num = num;

	CHECK(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH_FLAG && f_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}
