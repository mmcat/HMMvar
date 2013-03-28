/*
 * HmmVar.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: Mingming Liu
 */


#include <iostream>
#include <string>

#include "BlastSearch.h"
#include "MultiAlign.h"
#include "ScoreVar.h"
#include "Option.h"

using namespace std;


int main(int argc, char** argv){
	double cutoff = 0.90;    //cutoff for selecting homologous sequences
	Option opt;
	opt.SetOptions(argc,argv);



	ScoreVar score;
    score.SetQuerySequenceFromFastaFile(opt.query_file_name_.c_str(),opt.query_file_name_);

    Sequence wtaa;
    int type=1;
    score.translate(score.query_seq_, &wtaa,type);
    string wtaa_query_file_name=score.tmp_dir_+"/query_aa_file_wt";
    wtaa.Print(wtaa_query_file_name);
	blastSearch blast(wtaa_query_file_name, opt.blast_output_file_name_,opt.subject_sequences_file_name_,score.tmp_dir_);
	blast.searchHomoSeq(opt.blastdb_file_name_,opt.psiblast_command_);

	MultiAlign align(score.tmp_dir_);
    if (score.setHomoseq(opt.blastdbcmd_command_,opt.blastdb_file_name_,blast.subject_sequences_file_name_,blast.blast_output_file_name_,cutoff)!=-1 &&
	align.make_multi_align(opt.muscle_command_,blast.subject_sequences_file_name_,opt.muscle_output_file_name_)!=-1)

    	align.fasta2stockholm(align.align_output_file_fasta_);


    score.getVariants(opt.variants_file_name_);
	score.getScore(opt.hmmer_command_,wtaa_query_file_name,align.align_output_file_stockholm_);

	cout<<"done!"<<endl;


	return 0;
}

