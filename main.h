#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * specs - a structure
 * @specs: a pointer to a space in memory
 * @action: a function pointer
 *
 * description: this is a structure
 */
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
int scriptSignedDigits(va_list);
int scriptUnsignedDigits(va_list);

/* Miscellaneous functions */
void scriptBinaryChars(char *);
char *invertString(char *);
char *_strncpy(char *, char *, int);
unsigned int computeBaseLength(unsigned int, int);

#endif /* MAIN_H */
