#include "main.h"

/**
 * print_char - prints a char
 * @arguments: argument list
 * @buff: buffer array
 * @flags:  checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_char(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(arguments, int);

	return (handle_write_char(c, buff, flags, width, precision, size));
}
