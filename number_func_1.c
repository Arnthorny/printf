#include "main.h"

/**
 * print_hex -  Handles %h
 * @arg: Variadic Argunemt
 *
 * Return: pointer to a string.
 */
char *print_hex(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char *str = conv_base(num, 16);
	int i;

	if (!str)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] = str[i] + 32;
	}
	return (str);
}
