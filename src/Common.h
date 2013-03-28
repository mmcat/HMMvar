/*
 * Common.h
 *
 *  Created on: Feb 16, 2013
 *      Author: Mingming Liu
 */

#ifndef COMMON_H_
#define COMMON_H_

#define BUF_SIZE_LARGE 0x100000
#define BUF_SIZE_MED 0x10000
#define BUF_SIZE_SMALL 0x1000


#define P1 350./351
#define CONST_LOG2 0.69314718055994529
#define INTSCALE 1000.0

#define BLASTDB "/research/mingming/ncbi-blast-2.2.26+/db/nr"
#define BLASTDBCMD "~/bin/blastdbcmd"
#define PSIBLAST "~/bin/psiblast"
#define MUSCLE "~/bin/muscle"
#define HMMPATH "~/bin/"

#define VERSION "1.1"

#include <string>
#include <cstring>
#include <cstdlib>


using namespace std;



void Log(FILE* out, string message, bool with_time);
void Log(string message, bool with_time);



#endif /* COMMON_H_ */
