#include <stddef.h>
#include <stdio.h>
#include <getopt.h>

int main(int argc, char *const *argv)
{
	int opt;
	FILE *helpFile;
	char errorMessage[] = "usage: football [-h/--help]\n";

	static struct option longopts[] = {
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};

	while ((opt = getopt_long(argc, argv, "h", longopts, NULL)) != -1)
	{
		switch (opt)
		{
			case 'h': // Help: Print documentation
				helpFile = fopen("help.txt", "r");
				if (!helpFile)
				{
					fprintf(stderr, "Error opening the help-documentation\n");
					return 1;
				}
				char s;
				while ((s = fgetc(helpFile)) != EOF)
				{
					printf("%c", s);
				}
				fclose(helpFile);
				return 0;

			default: /* '?' */
				fprintf(stderr, errorMessage, argv[0]);
				return 1;
		}
	}

	return 0;
}
