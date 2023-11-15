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

/**
 * scriptSignedDigits - print a negative number
 * @args: variable length arguments
 *
 * description: this function prints a series of negative digits
 *
 * Return: number of digits printed
 */

int scriptSignedDigits(va_list args)
{
	int num, len = 0, div = 1;
	unsigned int value;

	num = va_arg(args, int);

	/** handle negative values */
	if (num < 0)
	{
		len += _script('-');
		value = num * -1;
	}
	else
		value = num;

	/**
	 * compute value for divisor for which first digits from
	 * the left of value can be obtained
	 */
	while (value / div > 9)
		div *= 10;

	/** compute and print one digit at a time from left */
	for (; div != 0; div /= 10)
	{
		len += _script('0' + value / div);
		value %= div;
	}

	return (len);
}

/**
 * scriptUnsignedDigits - print a positive number
 * @args: variable length arguments
 *
 * description: this function prints a series of positive digits
 *
 * Return: number of digits printed
 */

int scriptUnsignedDigits(va_list args)
{
	int len = 0, div = 1;
	unsigned int value;

	/** obtain values of variable length */
	value = va_arg(args, int);
	if (value < 1)
		return (-1);

	/**
	 * compute value for divisor for which the first digits from
	 * the left of value can be obtained
	 */
	while (value / div > 9)
		div *= 10;

	/** compute and print one digit at a time from left */
	for (; div != 0; div /= 10)
	{
		len += _script('0' + value / div);
		value %= div;
	}

	return (len);
}
