#include "main.h"

/**
 * print_hexadecimal - prints unsigned num in hexadecimal form
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_hexadecimal(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(arguments, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}
