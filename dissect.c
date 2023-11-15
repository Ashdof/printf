#include "main.h"

/**
 * dissect - analayse arguments and execute appropriate action
 * @vl: a variable length argument of type va_list.
 * @format: a pointer to the string of characters to analayse
 * @spec: a struct of type specs
 *
 * description: this function takes a variable length argument  of
 * type va_list, accesses each argument and compares it with value
 * of type specs to determine what format specifier to use
 * depending on the inputs
 *
 * Return: length of characters printed to the standard output
 */

int dissect(va_list vl, const char *format, spec_t spec[])
{
	int temp, j, i = 0, done = 0;

	/* loop through format string */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			/** loop and find a matching pair */
			for (j = 0; spec[j].specs != NULL; j++)
			{
				if (format[i] == spec[j].specs[0])
				{
					temp = spec[j].action(vl);
					if (temp == -1)
						return (-1);
					done += temp;
					break;
				}
			}

			if (spec[j].specs == NULL && format[i] != ' ')
			{
				_script(format[i]);
				_script(format[i + 1]);
				done += 2;
			}
		}
		else
		{
			_script(format[i]);
			done++;
		}
	}

	return (done);
}
