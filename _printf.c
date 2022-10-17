#include "main.h"

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
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				s = va_arg(ap, char *);
				len += write(1, s, _strlen(s));
			}
			else if (format[i] == 'c')
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
				len += write(1, &format[i], 1);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
