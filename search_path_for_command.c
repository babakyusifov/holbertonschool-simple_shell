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

	if (command == NULL || *command == '\0')
		return (NULL);

	if (access(command, F_OK) == 0 &&
		(command[0] == '/' || strncmp(command, "./", 2) == 0))
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
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	fprintf(stdout, "./hsh: 1: %s: not found\n", command);
	*status = 0;
	free(path);
	free(path_copy);
	return (NULL);
}

