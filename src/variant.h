/*
 * Variant.h
 *
 *  Created on: Feb 17, 2013
 *      Author: Mingming Liu
 */

#ifndef VARIANT_H_
#define VARIANT_H_

#include <string>

using namespace std;

class variant{
public:
	variant();
	virtual ~variant();
	string varinat_str_;
	string variant_id_;
	double wt_proba_;
	double mt_proba_;
	double odds_;



	int pos;


};


#endif /* VARIANT_H_ */
