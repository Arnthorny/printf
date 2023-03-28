#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * c_count_digits - Count the number of digits in unsigned
 * number in the base required
 * @num: The number
 * @base: Required base
 *
 * Return: Number of digits.
 */
int c_count_digits(size_t num, size_t base)
{
	return (num < base ? 1 : 1 + count_digits(num / base, base));
}

/**
  *custom_hex - This function converts decimal value to '0x + HEX value'
  *@value: The value to be converted
  *Return: Pointer to a string containing thr converted value
  */

char *custom_hex(size_t value)
{

	int lenVal = c_count_digits(value, 16), i;
	char *str;
	char *val_hex = conv_base(value, 16);
	char *pad = "0x";

	str = malloc(sizeof(*str) * (lenVal + strlen(pad) + 1));
	if (!str)
		return (NULL);

	for (i = 0; val_hex[i]; i++)
	{
		if (val_hex[i] >= 'A' && val_hex[i] <= 'F')
			val_hex[i] = val_hex[i] + 32;
	}

	str[0] = '\0';

	str = strcat(str, pad);
	str = strcat(str, val_hex);

	free(val_hex);
	return (str);
}

/**
  *print_pointer - A function to conv vrdic arg to pointer-esque.
  *string to a custom string given %p.
  *@args: Variadic list.
  *Return: Pointer to string.
  */

char *print_pointer(va_list args)
{
	char *str;
	size_t val;

	val = va_arg(args, size_t);

	str = custom_hex(val);
	return (str);

}
