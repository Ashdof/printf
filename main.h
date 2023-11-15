#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

struct specs
{
	char *specs;
	int (*action)(va_list vl);
};
typedef struct specs spec_t;

int _script(char);
int scriptChar(va_list);
int scriptString(va_list);
int scriptPercent(va_list);
int dissect(va_list, const char *, spec_t *);
int _printf(const char *, ...);
int scriptSignedDigits(va_list args);

#endif /* MAIN_H */
