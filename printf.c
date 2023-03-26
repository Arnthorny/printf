#include "main.h"

/**
  * _printf - This function imitates the C's printf function
  * @format: A formatted string.
  * Return: The number of bytes written.
  */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, size = 0;
	var_str *sp_var;
	char c[2] = {0};

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);

	while (format[i] && format)
	{
		if (format[i] == '%')
		{
			sp_var = check_sp(&format[i], args);
			if (sp_var && sp_var->string)
			{
				write(1, sp_var->string, strlen(sp_var->string));
				size += strlen(sp_var->string);
				i += (sp_var->i + 1);
				free(sp_var->string);
				free(sp_var);
				continue;
			}
		}
		c[0] = format[i];
		write(1, c, 1);
		size++;
		i++;
	}
	va_end(args);
	return (size);
}
