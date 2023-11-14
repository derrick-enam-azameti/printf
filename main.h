#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#define S_LONG 2
#define S_SHORT 1

#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

#define CHECK(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct fmt - struct
 *
 * @fmt: format
 * @fn: associated function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - struct op
 *
 * @fmt: format
 * @fm_t: associated function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list list, char buff[], int flags, int width, int precision, int size);

int print_char(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buff[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buff[],
	int flags, int width, int precision, int size);

int getter_flags(const char *format, int *i);
int getter_width(const char *format, int *i, va_list list);
int getter_precision(const char *format, int *i, va_list list);
int getter_size(const char *format, int *i);

int print_reverse(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buff[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buff[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buff[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buff[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buff[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
