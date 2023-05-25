#include "monty.h"

/**
 * getline - read a line of input from a file stream
 *
 * @lineptr: pointer to the buffer where the input will be stored
 * @n: pointer to the size of the buffer
 * @stream: pointer to the file stream to read from
 *
 * Return: the number of bytes read, including the null terminator, or -1 on error
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_bytes_read = 0;
	int ch;

	if (lineptr == NULL)
		return (-1);

	if (*n == 0 || *lineptr == NULL) {
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	while ((ch = fgetc(stream)) != EOF) {
		(*lineptr)[num_bytes_read++] = ch;

		if (num_bytes_read == *n) {
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		if (ch == '\n')
			break;
	}

	if (num_bytes_read == 0)
		return (-1	);

	(*lineptr)[num_bytes_read] = '\0';

	return (num_bytes_read);
}
