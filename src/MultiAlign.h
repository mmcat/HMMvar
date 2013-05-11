/*
 * multiAlign.h
 *
 *  Created on: Feb 17, 2013
 *      Author: mingmingliu
 */

#ifndef MULTIALIGN_H_
#define MULTIALIGN_H_

#include <string>

#include "Common.h"

using namespace std;

class MultiAlign{
public:
	MultiAlign(string path,string alignout_save_name);
	virtual ~MultiAlign();

//	string align_input_file_name_;
//	string align_output_file_name_;
//	string muscle_command_;
	string align_output_file_fasta_;
	string align_output_file_stockholm_;
	string output_path_;
        string alignout_save_file_name_;

//	void setParameters(string input,string output);
	int make_multi_align(string muscle_cmd,string align_input_file, string align_output_file);
	int fasta2stockholm(string oldfile);

private:
	int runMuscle(string muscle_cmd,string align_input_file);


};


#endif /* MULTIALIGN_H_ */
