/*
 * Option.h
 *
 *  Created on: Feb 18, 2013
 *      Author: mingmingliu
 */

#ifndef OPTION_H_
#define OPTION_H_

#include<string>
using namespace std;

class Option{
public:
	Option();
	virtual ~Option();

	string save_blastout_;
	string save_muscle_;
	string save_hmmer_;



	string blast_output_file_name_;
	string psiblast_command_;
	string blastdbcmd_command_;
	string query_file_name_;
	string blastdb_file_name_;
	string variants_file_name_;

	string muscle_output_file_name_;
	string muscle_command_;

	string hmmer_output_file_name_;
	string hmmer_command_;

	string subject_sequences_file_name_;


	int SetOptions(int argc, char** argv);

	void PrintOptions(FILE* out);
	void PrintUsage();


};


#endif /* OPTION_H_ */
