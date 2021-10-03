#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "print.h"

int fixtures(char *argument)
{
	// seperate argument into two strings
	char *saveptr;
	const char *comma = ",";
	char *past_string = strtok_r(argument, comma, &saveptr);
	char *future_string = strtok_r(NULL, comma, &saveptr);
	if (past_string == NULL || future_string == NULL)
	{
		fprintf(stderr, "Usage: footy -f/--fixtures <number>,<number>\n");
		print_help_message();
		return 1;
	}

	// convert strings into integers
	char **ptr = NULL;
	int past = (int) strtol(past_string, ptr, 10);
	int future = (int) strtol(future_string, ptr, 10);

	// reject negative values
	if (past < 0 || future < 0)
	{
		fprintf(stderr, "Past and future game values cannot be negative.\n");
		print_help_message();
		return 1;
	}

	// TODO: complete method
	printf("%d\n", past);
	printf("%d\n", future);

	return 0;
}

int supported(char *argument)
{
	// construct "doc/league.txt" or "doc/team.txt" from argument
	char docs_path[30] = "doc/";
	strcat(docs_path, argument);
	strcat(docs_path, ".txt");

	print_file_content_error_message(docs_path, "Usage: footy -u/--supported [league|team].\n");

	return 0;
}
