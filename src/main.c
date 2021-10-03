#include <stdlib.h>
#include <stddef.h>
#include <getopt.h>
#include "options.h"
#include "print.h"

/* Method headers */
int print_help_message();
int print_file_content(char file_path[]);
int print_file_content_error_message(char file_path[], char error_message[]);
int set_apikey(char apikey[]);

int main(int argc, char *const *argv)
{
	static struct option longopts[] = {
		{"league", required_argument, NULL, 'l'},
		{"team", required_argument, NULL, 't'},
		{"fixtures", required_argument, NULL, 'f'},
		{"standings", no_argument, NULL, 's'},
		{"apikey", required_argument, NULL, 'a'},
		{"supported", required_argument, NULL, 'u'},
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};

	int opt;
	while ((opt = getopt_long(argc, argv, "l:t:f:sa:u:h", longopts, NULL)) != -1)
	{
		switch (opt)
		{
			case 'l': /* league */
				break;

			case 't': /* team */
				break;

			case 'f': /* fixtures */
				fixtures(optarg);
				break;

			case 's': /* standings */
				break;

			case 'a':
				set_apikey(optarg);
				return 0;

			case 'u': /* supported */
				supported(optarg);
				return 0;

			case 'h': /* help */
				print_file_content("doc/help.txt");
				return 0;

			default: /* '?' */
				print_help_message();
				return 0;
		}
	}

	return 0;
}

/* Helper functions */
// TODO
int set_apikey(char apikey[])
{
	return 0;
}
