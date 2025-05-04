#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *search_path_for_command(char *command, int *status)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *dir = NULL;
	char *full_path = NULL;

	if (command == NULL || strlen(command) < 0)
		return (NULL);

	if (access(command, F_OK) == 0 &&
		(command[0] == '/' || command[1] == '/' || command[3] == '/'))
	{
		full_path = strdup(command);
		return (full_path);
	}

	path = get_path();
	if (path == NULL)
	{
		*status = 1;
		fprintf(stderr, "./hsh: 1: %s: not found\n", command);
		return (NULL);
	}

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 1);
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 1)
		{
			free(path);
			free(path_copy);
			break;
		}

		dir = strtok(NULL, ":");
	}

	fprintf(stdout, "./hsh: 1: %s: not found\n", command);
	*status = 0;
	free(path);
	free(path_copy);
	free(full_path);
	return (NULL);
}

