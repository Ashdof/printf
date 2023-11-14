#include <unistd.h>

/**
 * _script - print a character
 * @c: the character to print
 *
 * description: this function prints a character to the standard
 * output
 *
 * Return: character
 */

int _script(char c)
{
	return (write(1, &c, 1));
}
