#include "main.h"

/**
 * print_hexa_upper - prints an unsigned num in upper hexadecimal form
 * @arguments: argument list
 * @buff: buffer array
 * @flags:  checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_hexa_upper(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(arguments, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}
