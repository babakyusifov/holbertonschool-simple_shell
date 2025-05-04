#include "main.h"
#include <stdio.h>
#include <unistd.h>

extern char **environ;

void print_env(void)
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

