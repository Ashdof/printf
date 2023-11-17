#include "main.h"

/**
 * invertString - reverse a string
 * @str: a pointer to the string to reverse
 *
 * description: this function changes the positions of characters
 * in a string
 *
 * Return: nothing
 */

char *invertString(char *str)
{
	int size, i;
	char temp, *mem;

	for (size = 0; str[size] != '\0'; size++)
		;
	mem = malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (NULL);
	_strncpy(mem, str, size);

	for (i = 0; i < size; i++, size--)
	{
		temp = mem[size - 1];
		mem[size - 1] = mem[i];
		mem[i] = temp;
	}

	return (mem);
}

/**
 * scriptNonAscii - print non-printable characters
 * @args: a variable length arguments
 *
 * description: this function prints non-ASCII characters in
 * hexadecimal uppercase values
 *
 * Return: number of characters printed
 */

int scriptNonAscii(va_list args)
{
	int hex, i, size = 0;
	char *p;

	p = va_arg(args, char *);
	if (p == NULL)
		p = "(nil)";

	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] < 32 || p[i] >= 127)
		{
			_script('\\');
			_script('x');
			size += 2;
			hex = p[i];

			if (hex < 16)
			{
				_script('0');
				size++;
			}
			size += scriptHEXN(hex);
		}
		else
		{
			_script(p[i]);
			size++;
		}
	}

	return (size);
}
