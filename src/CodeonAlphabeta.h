/*
 * CodeonAlphabeta.h
 *
 *  Created on: Mar 8, 2013
 *      Author: mingmingliu
 */

#ifndef CODEONALPHABETA_H_
#define CODEONALPHABETA_H_

#include <string>
#include <map>

using namespace std;



const string Tables[6] = {
		      "FFLLSSSSYY**CC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
		      "FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNKKSS**VVVVAAAADDEEGGGG",
		      "FFLLSSSSYY**CCWWTTTTPPPPHHQQRRRRIIMMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
		      "FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG",
		      "FFLLSSSSYY**CCWWLLLLPPPPHHQQRRRRIIMMTTTTNNKKSSSSVVVVAAAADDEEGGGG",
		      "FFLLSSSSYYQQCC*WLLLLPPPPHHQQRRRRIIIMTTTTNNKKSSRRVVVVAAAADDEEGGGG"

};

const string Starts[6] = {
		      "---M---------------M---------------M----------------------------",
		      "--------------------------------MMMM---------------M------------",
		      "----------------------------------MM----------------------------",
		      "--MM---------------M------------MMMM---------------M------------",
		      "---M----------------------------MMMM---------------M------------",
		      "-----------------------------------M----------------------------",

};

const char nucleios[4]={'t','c','a','g'};
const int codeonsize=3;
const int ntsize=4;
const char gap = '-';
const string codeongap="---";

map <string,int> Codeon;
//const map <char, vector<char> > IUPAC_DNA={{'A',{'A'}},{'M',{'A','C'}},{'T',{'T'}}};
//const map <char, vector<char> > IUPAC_AA;
void set_Codeon(){
	int id=0;
	for(int i=0; i<ntsize; i++)
		for(int j=0; j<ntsize;j++)
			for(int k=0;k<ntsize;k++){
				char buf[4];
				sprintf(buf,"%c%c%c",nucleios[i],nucleios[j],nucleios[k]);
				string triple=string(buf);
				Codeon.insert(make_pair(triple,id));
				id++;
			}

}



#endif /* CODEONALPHABETA_H_ */
