#include "main.h"

/**
 * print_number - Print an integer recursively
 * @n: Integer to print
 *
 * Return: Number of character printed
 */
int print_number(int n)
{
	int count = 0;
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}

	if (n >= 10)
	{
		count += print_number(n / 10);
	}
	c = '0' + (n % 10);
	write(1, &c, 1);
	count++;

	return (count);
}
/**
 * print_int - Print an integer
 * @args: Argument list
 *
 * Return: Number of character printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);

	return (print_number(n));
}
/**
 * print_char - Print a character
 * @args: Argument list
 *
 * Return: Number of character printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string
 * @args: Argument list
 *
 * Return: Number of character printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0, count = 0;
	char *null_str = "(null)";

	if (!s)
	{
		while (null_str[i])
		{
			write(1, &null_str[i], 1);
			i++;
			count++;
		}
		return (count);
	}

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

/**
 * _printf - Copy of printf function
 * @format: format string
 *
 * Return: Number of character printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	{
		if (format != NULL && format[0] == '%' && format[1] == '\0')
		return (-1);
	}
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
