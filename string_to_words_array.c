#include "main.h"

char **string_to_words_array(char *line, int *status)
{
	char *line_copy = NULL;
	char **argv = NULL;
	char *arg = NULL;
	size_t argc = 0;
	size_t i = 0;

	line_copy = strdup(line); 
	if (line_copy == NULL)
	{
		*status = 1;
		return (NULL);
	}

	arg = strtok(line_copy, " \n");
	while (arg) 
	{
		argc++;
		arg = strtok(NULL, " \n");
	}

	if (argc == 0)
	{
		free(line_copy);
		argv = malloc(sizeof(char *) * 1); 
		if (argv == NULL)
		{
			*status = 1;
			return (NULL);
		}
		argv[0] = NULL;
		return (argv); 
	}

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		free(line_copy);
		*status = 1;
		return (NULL);
	}

	arg = strtok(line, " \n");
	for (i = 0; i < argc; i++) 
	{
		*(argv + i) = arg; 
		arg = strtok(NULL, " \n");
	}
	
	argv[i] = NULL; 
	free(line_copy);
	(void)status;
	return (argv); 
}

