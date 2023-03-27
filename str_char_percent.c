#include "main.h"

/**
 * print_char - This functions handles a variadic char
 * @arg: Variadic arguments.
 * Return: A null-byte terminated string containg the char.
 */
char *print_char(va_list arg)
{
	char c = (char) va_arg(arg, int);
	char *str = malloc(sizeof(*str) + 1);

	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';

	return (str);
}

/**
 * print_string - This functions handles a variadic string
 * @arg: Variadic arguments.
 * Return: A null-byte terminated string.
 */
char *print_string(va_list arg)
{
	char *str = va_arg(arg, char*);
	char *strC = malloc(sizeof(*strC) * (strlen(str) + 1));

	if (!strC)
		return (NULL);
	strC = strcpy(strC, str);

	return (strC);
}

/**
 * print_percent - This functions handles an escaped percent sign
 * @arg: Variadic arguments.
 * Return: A null-byte terminated string containg the percent.
 */
char *print_percent(__attribute__((unused))va_list arg)
{
	char *str = malloc(sizeof(*str) + 1);

	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
