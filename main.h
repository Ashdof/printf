#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * specs - a struct for specifiers
 * @specs: a pointer to the specifier
 * @action: a function pointer to the function to execute
 *
 * Description: a structure for determining the type of function to
 * invoke based on the given specifier
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
int scriptOctal(va_list);
int scriptBinary(va_list);
int scriptHex(va_list);
int scriptHEX(va_list);
int scriptNonAscii(va_list);
int scriptHEXN(unsigned int);
int scriptAddress(va_list);
int scriptHexn(unsigned long int);
int scriptInvertString(va_list);

/* Miscellaneous functions */
int _strlen(char *);
void scriptStringChars(char *);
char *invertString(char *);
char *_strncpy(char *, char *, int);
unsigned int computeBaseLength(unsigned int, int);

#endif /* MAIN_H */
