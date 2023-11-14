#include "main.h"

/**
 * print_octal - prints a string in reverse
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */

int print_reverse(va_list arguments, char buff[],
	int flags, int width, int precision, int size)
{
	char *string;
	int i, count = 0;

	CHECK(buff);
	CHECK(flags);
	CHECK(width);
	CHECK(size);

	string = va_arg(arguments, char *);

	if (string == NULL)
	{
		CHECK(precision);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
