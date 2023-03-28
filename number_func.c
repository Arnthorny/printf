#include "main.h"

/**
 * print_int - Handles %i an %d
 * @arg: Variadic Argument
 *
 * Return: pointer to string
 */
char *print_int(va_list arg)
{
	int num = va_arg(arg, int);

	return (digTostr(num));
}

/**
 * print_bin - Handles %b
 * @arg: Variadic Argument
 *
 * Return: pointer to string
 */
char *print_bin(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);

	return (conv_base(num, 2));
}

/**
 * print_u_int - Handles %u
 * @arg: Variadic Argument
 *
 * Return: pointer to string
 */
char *print_u_int(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);

	return (digTostr(num));
}

/**
 * print_oct - Handles %o
 * @arg: Variadic Argument
 *
 * Return: pointer to string
 */
char *print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);

	return (conv_base(num, 8));
}

/**
 * print_HEX - Handles %X
 * @arg: Variadic Argument
 *
 * Return: pointer to string
 */
char *print_HEX(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);

	return (conv_base(num, 16));
}
