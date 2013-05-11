/*
 * Option.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: mingmingliu
 */

#include "Option.h"
#include <cstdio>
#include <getopt.h>
#include <stdlib.h>

char usage[] =
		"USAGE:\
		\n  HMMvar [Options]\
		\n\nOptions:\
		\n  -q <string>\
		\n  -d <string>\
		\n  -v <string>\
		\n  --psiblastcmd <string>\
		\n  --musclecmd <string>\
		\n  --hmmercmd <string>\
		\n  --blastdbcmd <string>\
		\n  --subject_sequence <string>\
		\n";


Option::Option(){
}

Option::~Option(){

}

int Option::SetOptions(int argc, char** argv){
	int c;
	while (1)
		{
			static struct option long_options[] =
			{
					{"blastout", required_argument, 0, 1},
					{"save_blastout", required_argument, 0, 2},
					{"psiblastcmd", required_argument, 0, 3},
					{"blastdbcmd", required_argument, 0, 4},

					{"save_muscleout", required_argument,0,5},
					{"musclecmd", required_argument,0, 6},

					{"save_hmmerout",required_argument,0,7},
					{"hmmercmd",required_argument, 0, 8},

					{"subject_sequence",required_argument,0,9},

			};
			/* getopt_long stores the option index here. */
			int option_index = 0;
			c = getopt_long(argc, argv, "q:d:v:",
							long_options, &option_index);
			/* Detect the end of the options. */
					if (c == -1)
						break;

					switch (c)
					{
					case 0:
						break;
					case 1:
						blast_output_file_name_ = optarg;
						break;
					case 2:
						save_blastout_ = optarg;
						break;
					case 3:
						psiblast_command_ = optarg;
						break;
					case 4:
						blastdbcmd_command_ = optarg;
						break;
					case 5:
						save_muscle_ = optarg;
						break;
					case 6:
						muscle_command_ = optarg;
						break;
					case 7:
						save_hmmer_=optarg;
						break;
					case 8:
						hmmer_command_ = optarg;
						break;
					case 9:
						subject_sequences_file_name_ = optarg;
						break;
					case 'q':
						query_file_name_ = optarg;
						break;
					case 'd':
						blastdb_file_name_ = optarg;
						break;
					case 'v':
						variants_file_name_ = optarg;
						break;
					case 'b':
						blast_output_file_name_ = optarg;
						break;

					default: /* '?' */
						this->PrintUsage();
						exit(EXIT_FAILURE);
					}

		}
	if (query_file_name_.empty()
				|| variants_file_name_.empty()
				) {
			this->PrintUsage();
			exit(EXIT_FAILURE);
	}

	return 1;
}

void Option::PrintUsage()
{
	fprintf(stderr, "%s", usage);
}

