#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
int len_s(long n);
char *neg_case(long a);
char *_itoa(int a);

#endif
