/*
 * Sequence.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: mingmingliu
 */
#include "Sequence.h"

#include <iostream>
#include <stdio.h>
using namespace std;

Sequence::Sequence(){

}

Sequence::~Sequence(){

}

void Sequence::Print(string& filename){
	if(filename.empty()) {fprintf(stderr,"Print sequence: No output file name provided!\n");exit(0);}


	FILE* fp = fopen(filename.c_str(),"w");
	fprintf(fp,"%s\n%s\n",this->def_.c_str(),this->seq_.c_str());
	fclose(fp);
}

bool Sequence::SetSequenceFromFastaFile(const char* id, string filename){

	FILE* fp = fopen(filename.c_str(), "r");

		if (fp == NULL) {
			Log("File open error\n", true);
			cerr << filename << endl;
			exit(1);
			return false;
		}

		id_ = id;

		char* strptr;
		char buf[BUF_SIZE_LARGE];
		while (!feof(fp)) {
			if (fgets(buf, BUF_SIZE_LARGE, fp) == NULL)
				break;

			if (buf[0] == '>') {
				// def line
				strptr = strtok(buf,"\n");
				def_.assign(strptr, 100);
			} else {
				strptr = strtok(buf, " \r\n");
				if (strptr == NULL)
					break;
				seq_.append(strptr);
			}
		}

		fclose(fp);

	return true;
}

