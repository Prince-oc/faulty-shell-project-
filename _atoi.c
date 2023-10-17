#include "shell.h"

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * is_numeric - Checks if a string contains only numeric characters.
 * @s: The string to check.
 *
 * Return: true if the string is numeric, false otherwise.
 */
bool is_numeric(const char *s)
{
    if (s == NULL || *s == '\0')
        return false;

    while (*s)
    {
        if (*s < '0' || *s > '9')
            return false;
        s++;
    }

    return true;
}

int main()
{
    const char *str1 = "12345";    // Numeric string
    const char *str2 = "abc123";   // Alphanumeric string
    const char *str3 = "   ";      // Whitespace

    printf("Is '%s' numeric? %s\n", str1, is_numeric(str1) ? "Yes" : "No");
    printf("Is '%s' numeric? %s\n", str2, is_numeric(str2) ? "Yes" : "No");
    printf("Is '%s' numeric? %s\n", str3, is_numeric(str3) ? "Yes" : "No");

    return 0;
}

