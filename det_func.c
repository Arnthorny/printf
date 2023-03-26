#include <ctype.h>
#include "main.h"

/**
 * ret_func - Returns the corresponding function pertaining to a given index
 * @i: index
 * Return: The corresponding function
 */
specifier_func ret_func(int i)
{
	c_spe all_spe[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL},
	};

	return (all_spe[i].func);
}

/**
 * isValid - This function checks if a given char is a valid format specifier
 * @c: The char to be checked
 * Return: -1 if not a valid specifier else its index in the struct in ret_func
 */

int isValid(char c)
{
	char *valid_specifiers = "cs%";
	int i = 0;

	while (valid_specifiers[i])
	{
		if (valid_specifiers[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * check_sp - This function returns a pointer to struct.
 * @format: The formatted string at a specific index
 * @args: Variadic arguments
 * Return: Struct containing str to print and offset i or NULL.
 */
var_str *check_sp(const char *format, va_list args)
{
	int i = 1, index;
	var_str *f;

	index = isValid(format[i]);
	if (index >= 0)
	{
		f = malloc(sizeof(var_str));
		if (!f)
			exit(98);
		f->i = i;
		f->string = ret_func(index)(args);
		return (f);
	}
	else
		return (NULL);
	/**
	*while (format && format[i])
	{
		index = isValid(format[i]);
		if (index >= 0)
		{
			f = malloc(sizeof(var_str));
			if (!f)
				exit(98);

			f->i = i;
			f->string = ret_func(index)(args);
			return (f);
		}
		else if (isalpha(format[i]) || format[i + 1] == '%')
			return (NULL);
		i++;
	}
	return (NULL);
	*/
}