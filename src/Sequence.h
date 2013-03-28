/*
 * Sequence.h
 *
 *  Created on: Feb 17, 2013
 *      Author: Mingming Liu
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include <string>
#include "Common.h"

using namespace std;

class Sequence {
public:
	Sequence();
	virtual ~Sequence();

	bool SetSequence();
	bool SetSequence(char* id, string blast_db_file, string blastdbcmd);
	bool SetSequenceFromFastaFile(const char* id, string filename);
	void Print(string& filename);

	string id_;
	string seq_;
	string def_;
//	int cluster_id_;
	double e_value_;
	double bit_score_;
	double weight_;

	static char buf_[BUF_SIZE_LARGE];
};


#endif /* SEQUENCE_H_ */
