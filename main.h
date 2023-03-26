#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUF_SIZE 1024

typedef char* (*specifier_func)(va_list);

/**
  * struct specifier - A structure to hold specifier char and function
  * @c: Char to identify format specifier
  * @func: function to handle specifier
  */

typedef struct specifier
{
	char c;
	specifier_func func;
} c_spe;

/**
  * struct return_string - A structure to hold vrdic string
  * @i: Total length of specifer
  * @string: String corresponding to given specifier.
  * Description: This structure holds the length of given specifier
  * E.g. '.2f' makes i = 3. string holds the post-formatted string.
  */
typedef struct return_string
{
	int i;
	char *string;
} var_str;


int _printf(const char *format, ...);
var_str *check_sp(const char *format, va_list);
specifier_func ret_func(int i);

char *print_char(va_list arg);
char *print_string(va_list arg);
char *print_percent(__attribute__((unused))va_list arg);

#endif /* MAIN_H */