#include "main.h"

/**
 * scriptHex - print hexadecimal values in lowercase
 * @args: a variable length arguments
 *
 * description: this function converts a decimal number to
 * hexadecimal values in lowercase and prints them
 *
 * Return: number of hexadecimal characters printed
 */

int scriptHex(va_list args)
{
	unsigned int values;
	int size, i;
	char *mem;

	values = va_arg(args, unsigned int);
	if (values == 0)
		return (_script('0'));
	if (values < 1)
		return (-1);

	size = computeBaseLength(values, 16);
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		mem[i] = values % 16;
		values /= 16;
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (mem[i] > 9)
			mem[i] += 39;
		_script(mem[i] + '0');
	}
	free(mem);

	return (size);
}

/**
 * scriptHexn - print hexadecimal values in lowercase
 * @value: a variable length arguments
 *
 * description: this function converts a decimal number to
 * hexadecimal values in lowercase and prints them
 *
 * Return: number of hexadecimal characters printed
 */

int scriptHexn(unsigned long int value)
{
	long int i, size, *mem;

	size = computeBaseLength(value, 16);
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		mem[i] = value % 16;
		value /= 16;
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (mem[i] > 9)
			mem[i] += 39;
		_script(mem[i] + '0');
	}
	free(mem);

	return (size);
}

/**
 * scriptHEX - print hexadecimal values in uppercase
 * @args: a variable length arguments
 *
 * description: this function converts a decimal number to
 * hexadecimal value in uppercase and prints them
 *
 * Return: number of hexadecimal characters prints
 */

int scriptHEX(va_list args)
{
	unsigned int values;
	int size, i;
	char *mem;

	values = va_arg(args, unsigned int);
	if (values == 0)
		return (_script('0'));
	if (values < 1)
		return (-1);

	size = computeBaseLength(values, 16);
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		mem[i] = values % 16;
		values /= 16;
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (mem[i] > 9)
			mem[i] += 7;
		_script(mem[i] + '0');
	}
	free(mem);

	return (size);
}

/**
 * scriptHEXN - print hexadecimal values in uppercase
 * @arg: an unsigned integer value
 *
 * description: this function converts a decimal number to
 * hexadecimal value in and print it
 *
 * Return: number of hexadecimal characters prints
 */
int scriptHEXN(unsigned int arg)
{
	int size, i;
	char *mem;

	while (arg != 0)
	{
		arg /= 16;
		size++;
	}

	mem = malloc(sizeof(int) * size + 1);
	if (mem == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		mem[i] = arg % 16;
		arg /= 16;
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (mem[i] > 9)
			mem[i] += 39;
		_script('0' + mem[i]);
	}
	free(mem);

	return (size);
}
