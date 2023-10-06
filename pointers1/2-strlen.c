#include "main.h"

/* Calculates the length of a string */
int _strlen(char *s)
{
	int idx, len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return(len);
}
