/*
 * scoreVar.h
 *
 *  Created on: Feb 17, 2013
 *      Author: Mingming Liu
 */

#ifndef SCOREVAR_H_
#define SCOREVAR_H_

#include <string>
#include <vector>
#include <iostream>

#include "Sequence.h"
#include "variant.h"


using namespace std;

class ScoreVar{
public:
	ScoreVar();
	virtual ~ScoreVar();

	Sequence query_seq_;
	vector < Sequence > subject_seqs_;
	vector < variant > variants_;
//	string hmm_input_file_name_;
	string hmm_output_file_name_;
	string tmp_dir_;
	string score_out_file_name_;
//	string hmm_command_;

//	void SetHMMParameters(string input,string output);
	bool SetQuerySequenceFromFastaFile(const char* id, string fasta_file);
	int CreateTempDir();
	int parseBlastResults(string blastdb_cmd,string blastdb,string subject_sequence_file_name,string blast_out_file_name,double cutoff);
	int setHomoseq(string blastdb_cmd,string blastdb,string subject_sequence_file_name,string blast_out_file_name,double cutoff);
	int getScore(string hmm_path,string wtaa_file_name,string multi_align_file);
	int getVariants(string filename);
	double getNullPro(int len);
	double getOdds(double p1,double p2);
	void getMutantSeqFromVariants(variant var,Sequence* mut_seq);
	void translate(const Sequence& aa, Sequence * nt,int type);


private:

	int SetSequences();
	int CreateFastaFileUsingBlastdbcmd(string blastdb_cmd,string blastdb,string subject_seq_file_name,string file_id);
	int buildHMM(string hmm_path,string multi_align_file);
	double searchHMM(string hmm_path,string aa_file_name);


};




#endif /* SCOREVAR_H_ */
