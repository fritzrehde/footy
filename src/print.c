#include <stdio.h>

int print_help_message()
{
	fprintf(stderr, "Use --help to see all options.\n");
	return 1;
}

int print_file_content_error_message(char file_path[], char error_message[])
{
	FILE *file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "%s", error_message);
		print_help_message();
		return 1;
	}

	char s;
	while ((s = fgetc(file)) != EOF)
	{
		printf("%c", s);
	}

	fclose(file);
	return 0;
}

int print_file_content(char file_path[])
{
	print_file_content_error_message(file_path, "An error occured.\n");
	return 0;
}
