#include "main.h"

/**
 * print_percent - prints a percent sign
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_percent(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	CHECK(arguments);
	CHECK(buff);
	CHECK(flags);
	CHECK(width);
	CHECK(precision);
	CHECK(size);
	return (write(1, "%%", 1));
}
