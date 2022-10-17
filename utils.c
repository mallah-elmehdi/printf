#include "main.h"

/**
 * _strlen - check the code
 * @s: param
 *
 * Return: ...
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _calloc - check the code
 * @nmemb: param
 * @size: param
 *
 * Return: somthing.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ret;
	int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ret = malloc(nmemb * size);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while ((unsigned int)i < nmemb * size)
	{
		((unsigned char *)ret)[i] = '\0';
		i++;
	}
	return (ret);
}

/**
 * len_s - check the code
 * @n: param
 *
 * Return: ...
 */

int len_s(long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

/**
 * neg_case - check the code
 * @a: param
 *
 * Return: ...
 */

char *neg_case(long a)
{
	char *s;
	int count;

	a = -a;
	count = len_s(a) + 1;
	s = (char *)_calloc(sizeof(char), count);
	if (s == 0)
		return (0);
	s[0] = '-';
	s[--count] = 0;
	while (count > 1)
	{
		s[--count] = (a % 10) + 48;
		a = a / 10;
	}
	return (s);
}

/**
 * _itoa - check the code
 * @a: param
 *
 * Return: ...
 */

char *_itoa(int a)
{
	char *s;
	int count;

	if (a < 0)
		return (neg_case((long)a));
	count = len_s((long)a);
	if (a >= 0)
	{
		s = (char *)_calloc(sizeof(char), count);
		if (s == 0)
			return (0);
		s[--count] = 0;
	}
	while (count > 0)
	{
		s[--count] = (a % 10) + 48;
		a = a / 10;
	}
	return (s);
}
