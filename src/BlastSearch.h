/*
 * blastSearch.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Mingming Liu
 */

#ifndef BLASTSEARCH_H_
#define BLASTSEARCH_H_

#include <string>

#include "Common.h"

using namespace std;

class blastSearch{
public:
	blastSearch(string blast_query,string blast_output,string subject_seqs,string path);
	virtual ~blastSearch();

	string blast_output_file_name_;
//	string blast_db_name_;
	string blast_query_file_name_;
//	string psiblast_command_;
	string subject_sequences_file_name_;
	string temp_dir_;

	void searchHomoSeq(string blastdb_file_name,string psiblast_cmd);

private:

	int runBlast(string blastdb_file_name,string psiblast_cmd);




};


#endif /* BLASTSEARCH_H_ */
