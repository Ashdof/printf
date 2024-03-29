#include "main.h"

/**
 * scriptStringChars - print binary values
 * @str: a pointer to the binary values
 *
 * description: this function prints binary values
 *
 * Return: nothing
 */

void scriptStringChars(char *str)
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
 * _strlen - compute length of string
 * @s: a pointer to the string
 *
 * description: this function computes the length of a string
 * pointed to by s
 *
 * Return: number of characters as length
 */

int _strlen(char *s)
{
	char *p = s;

	while (*p)
		p++;

	return (p - s);
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

/**
 * rot13String - encript a string
 * @s: a pointer to the string to encript
 *
 * description: this function encripts a string by rotating the
 * characters by 13 places
 *
 * Return: a pointer to the encripted string
 */

char *rot13String(char *s)
{
	int i, j = 0;
	char *letas = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqr \
		       stuvwxyz";
	char *keys = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcde \
		       fghijklm";

	while (s[j])
	{
		for (i = 0; i < 52; i++)
		{
			if (s[j] == letas[i])
			{
				s[j] = keys[i];
				break;
			}
		}
		j++;
	}

	return (s);
}
