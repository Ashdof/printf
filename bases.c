#include "main.h"

/**
 * scriptBinary - convert and print binary values
 * @args: a variable length arguments
 *
 * description: this function converts a number in base 10 to binary
 * and then prints the binary values
 *
 * Return: number of binary values printed
 */

int scriptBinary(va_list args)
{
	unsigned int values;
	int size, i;
	char *mem, *str;

	values = va_arg(args, unsigned int);
	if (values == 0)
		return (_script('0'));
	if (values < 1)
		return (-1);

	/** compute number of binary characters */
	size = computeBaseLength(values, 2);

	/** allocate space in memory for binary values */
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (-1);

	/** store either 0s and 1s in memory base on results */
	for (i = 0; values > 0; i++)
	{
		if (values % 2 == 0)
			mem[i] = '0';
		else
			mem[i] = '1';
		values /= 2;
	}
	mem[i] = '\0';

	/** invoke function to reverse binary values */
	str = invertString(mem);
	if (str == NULL)
		return (-1);

	/** print reversed binary values */
	scriptStringChars(str);

	/** return allocated space to the OS */
	free(mem);
	free(str);
	return (size);
}

/**
 * scriptOctal - convert and print octal values
 * @args: a variable length arguments
 *
 * description: this function converts a number in base 10 to octal
 * values
 *
 * Return: number of octal values printed
 */

int scriptOctal(va_list args)
{
	unsigned int values;
	int size, i;
	char *mem, *str;

	values = va_arg(args, unsigned int);
	if (values == 0)
		return (_script('0'));
	if (values < 1)
		return (-1);

	/** compute number of octal characters */
	size = computeBaseLength(values, 8);

	/** allocate space in memory for octal values */
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (-1);

	/** compute and store octal values */
	for (i = 0; values > 0; i++)
	{
		mem[i] = (values % 8) + 48;
		values /= 8;
	}
	mem[i] = '\0';

	/** reverse octal values */
	str = invertString(mem);
	if (str == NULL)
		return (-1);

	/** print reversed octal values */
	scriptStringChars(str);

	/** free alocated memory */
	free(mem);
	free(str);

	return (size);
}

/**
 * scriptAddress - print memory address
 * @args: a variable length argument
 *
 * description: this function prints the memory address of a value
 * in lowercase hexadecimal value
 *
 * Return: number of characters printed
 */
int scriptAddress(va_list args)
{
	void *value;
	long int ptr;
	int hex;
	char *str = "(nil)";

	value = va_arg(args, void *);
	if (!value)
	{
		for (; *str != '\0'; str++)
			_script(*str);
		return (5);
	}

	ptr = (unsigned long int) value;
	_script('0');
	_script('x');
	hex = scriptHexn(ptr);
	hex += 2;

	return (hex);
}
