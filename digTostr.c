#include "main.h"

/**
 * count_digits - Count the number of digits in the base required
 * @num: The number
 * @base: Required base
 *
 * Return: Number of digits.
 */
int count_digits(long num, long base)
{
	num = num >= 0 ? num : -(num);
	return (num < base ? 1 : 1 + count_digits(num / base, base));
}

/**
 * digTostr - Convert number to a string
 * @num: Number
 *
 * Return: String of number
 */
char *digTostr(long num)
{
	int lenStr = num < 0 ? 1 : 0;
	char *str;

	lenStr += (count_digits(num, 10));

	str = malloc(sizeof(*str) * (lenStr + 1));
	if (!str)
		return (NULL);

	str[lenStr--] = '\0';
	str[0] = num >= 0 ? '0' : '-';
	num = num >= 0 ? num : -(num);

	while (num)
	{
		str[lenStr--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/**
 * conv_base - convert to required base.
 * @num: number in base 10
 * @base: new base
 *
 * Return: New number
 */
char *conv_base(unsigned long num, unsigned long base)
{
	char base_case[] = "0123456789ABCDEF";
	int len = count_digits(num, base);
	char *result = malloc(len + 1);

	result[len] = '\0';
	while (len)
	{
		result[--len] = base_case[num % base];
		num /= base;
	}
	return (result);
}
