#include "main.h"
#include <stdio.h>

void print_env(void)
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

