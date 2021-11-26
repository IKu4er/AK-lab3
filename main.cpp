#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

/*
|	Lab 3
|	IV-91
|	Ivan Kucherenko
*/

int main(int argc, char* argv[]) {
	const char* short_options = "hvs::f:";
	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{"size",optional_argument,NULL,'s'},
		{"file",required_argument,NULL,'f'},
		{NULL,0,NULL,0}
	};

	int rez;
	int check_h = 1;
	int check_v = 1;
	int check_s = 1;
	int check_n = 1;
	int option_index;

	opterr=0;
	while ((rez = getopt_long(argc, argv, short_options,
		long_options, &option_index)) != -1) {

		switch (rez) {
		case 'h': {
			if (check_h > 0){
				printf("You`ve used help option.\nUnfortunatelly program is help-less :(\nTry -h or --help.\n\n");
			}
			check_h--;
			break;
		};
		case 'v': {
			if (check_v > 0){
				printf("You`ve used version option.\nCurrent version = 1.0.0.\nTry -v or --version.\n\n");
			}
			check_v--;
			break;
		};
		case 's': {
			if (check_s > 0){
				if (optarg != NULL)
					printf("You`ve used size option with value %s\nTry -s or --size.\n\n", optarg);
				else
					printf("You`ve used size option without value\nTry -s or --size.\n\n");
			}
			check_s--;
			break;
		};

		case 'n': {
			if (check_n > 0){
				printf("You`ve used name option (value is needed).\nName = %s\nTry -n or --name.\n\n", optarg);
			}
			check_n--;
			break;
		};
		case '?': default: {
			printf("Error.\nError code: 404.\nError, think first man and go to help!\n\n");
			break;
		};
		};
	};
	return 0;
};