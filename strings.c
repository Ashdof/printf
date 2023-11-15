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
