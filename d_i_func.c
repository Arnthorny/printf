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
