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

/**
 * print_rot13 -  Handles %R
 * @arg: variadic argument
 *
 * Return: pointer to a string
 */
char *print_rot13(va_list arg)
{	
	char *str = va_arg(arg, char *);
	char *strC, *rev_str;

	str = str ? str : "";

	strC = malloc(sizeof(*strC) * (strlen(str) + 1));
	if (!strC)
		return (NULL);
	
	rev_str = rot13(str);
	strcpy(strC, rev_str);
	return (strC);

}

