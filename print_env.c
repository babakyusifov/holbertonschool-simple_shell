#include "main.h"

void print_env(void)
{
	int i = 0;

	for (; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

