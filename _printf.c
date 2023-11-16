#include "main.h"

/**
 * _printf - print to the standard output
 * @format: a pointer to a variable length arguments
 * @...: an elipsis denoting variable length arguments
 *
 * description: this function takes a variable length argument and
 * prints them to the standard output
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	spec_t specs[] = {
		{"c", scriptChar},
		{"s", scriptString},
		{"%", scriptPercent},
		{"d", scriptSignedDigits},
		{"i", scriptSignedDigits},
		{"b", scriptBinary},
		{"u", scriptUnsignedDigits},
		{"o", scriptOctal},
		{"x", scriptHex}
	};
	int done;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	done = dissect(args, format, specs);
	va_end(args);

	return (done);
}
