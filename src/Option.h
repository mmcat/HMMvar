/*
 * Option.h
 *
 *  Created on: Feb 18, 2013
 *      Author: Mingming Liu
 */

#ifndef OPTION_H_
#define OPTION_H_

#include<string>
using namespace std;

class Option{
public:
	Option();
	virtual ~Option();

	int flag_save_blastout_;
	int flag_save_muscle_;
	int flag_save_hmmer_;

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
