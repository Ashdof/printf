#include "main.h"

/**
 * scriptBinaryChars - print binary values
 * @str: a pointer to the binary values
 *
 * description: this function prints binary values
 *
 * Return: nothing
 */

void scriptBinaryChars(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_script(str[i]);
}

/**
 * _strncpy - copy bytes
 * @dest: a pointer to the destination space in memory
 * @src: a pointer to the string to copy
 * @n: maximum number of bytes to copy
 *
 * description: this function copies n bytes from src to dest
 *
 * Return: a pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * computeBaseLength - compute length
 * @value: the value to compute its length
 * @base: the base value
 *
 * description: this function computes the length of a number
 *
 * Return: length
 */

unsigned int computeBaseLength(unsigned int value, int base)
{
	unsigned int i;

	for (i = 0; value > 0; i++)
		value /= base;

	return (i);
}
