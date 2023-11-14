#include "main.h"

/**
 * print_non_printable - prints ascii codes in hexa form of non printable chars
 * @arguments: argument list
 * @buff: buffer array
 * @flags: checks flags in use
 * @width: width
 * @precision: precision indicator
 * @size: size indicator
 *
 * Return: number of printed chars
 */
int print_non_printable(va_list arguments, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *string = va_arg(arguments, char *);

	CHECK(flags);
	CHECK(width);
	CHECK(precision);
	CHECK(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[i] != '\0')
	{
		if (is_printable(string[i]))
			buffer[i + offset] = string[i];
		else
			offset += append_hexa_code(string[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
