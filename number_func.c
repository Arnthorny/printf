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
 * @arg: Variadic Argumeny
 *
 * Return: pointer to string
 */
char *print_bin(va_list arg)
{
	int num = va_arg(arg, int);

	return (conv_base(num, 2));
}
