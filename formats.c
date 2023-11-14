#include "main.h"

/**
 * scriptChar - print a character
 * @args: variable length arguments
 *
 * description: this function prints a character
 *
 * Return: number of characters printed
 */

int scriptChar(va_list args)
{
	char c;

	c = va_arg(args, int);
	_script(c);

	return (1);
}

/**
 * scriptString - print array of characters
 * @args: variable length arguments
 *
 * Return: number of characters printed
 */

int scriptString(va_list args)
{
	int len = 0;
	char *text;

	text = va_arg(args, char *);
	if (!text)
		text = "(null)";
	for (; text[len] != '\0'; len++)
		_script(text[len]);

	return (len);
}

/**
 * scriptPercent - print the percentage sign
 * @args: a variable length arguments
 *
 * Return: length of printed characters
 */

int scriptPercent(__attribute__((unused)) va_list args)
{
	char mod = '%';
	_script(mod);

	return (1);
}
