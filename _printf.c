#include "main.h"

/**
 * help - check the code
 * @c: param
 *
 * Return: ...
 */

int help(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

/**
 * s_handler - check the code
 * @s: param
 *
 * Return: ...
 */

int s_handler(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, _strlen(s)));
}

/**
 * _printf - check the code
 * @format: param
 *
 * Return: ...
 */

int _printf(const char *format, ...)
{
	int i;
	int len;
	char *s;
	char c;
	va_list ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's' || format[i] == 'S')
				len += s_handler(va_arg(ap, char *));
			else if (format[i] == 'c' || format[i] == 'C')
			{
				c = va_arg(ap, int);
				len += write(1, &c, 1);
			}
			else if (format[i] == 'i' || format[i] == 'd')
			{
				s = _itoa(va_arg(ap, int));
				len += write(1, s, _strlen(s));
			}
			else if (format[i] == '%')
				len += write(1, "%", 1);
			else
				len += help(format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
