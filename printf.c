#include "main.h"

/**
  * _printf - This function imitates the C's printf function
  * @format: A formatted string.
  * Return: The number of bytes written.
  */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, size;
	var_str *sp_var;
	char c[1] = {0}, *buf;

	buf = malloc(BUF_SIZE);
	if (!buf)
		return (-1);
	buf[0] = '\0';
	va_start(args, format);

	while (format[i] && format)
	{
		if (format[i] == '%')
		{
			sp_var = check_sp(&format[i], args);
			if (sp_var && sp_var->string)
			{
				strcat(buf, sp_var->string);
				i += (sp_var->i + 1);
				free(sp_var->string);
				free(sp_var);
				continue;
			}
		}
		c[0] = format[i];
		strcat(buf, c);
		i++;
	}
	va_end(args);

	size = write(1, buf, strlen(buf));
	free(buf);
	return (size);
}
