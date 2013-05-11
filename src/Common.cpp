/*
 * Common.cpp
 *
 *  Created on: Feb 16, 2013
 *      Author: mingmingliu
 */

#include <time.h>
#include <cstdio>
#include "Common.h"


void Log(FILE* out, string message, bool with_time)
{
	if (with_time) {
		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);

		fprintf(out, "[%02d:%02d:%02d] %s", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message.data());
	} else {
		fprintf(out, "%s", message.data());
	}
	fflush(out);
}

void Log(string message, bool with_time)
{
	Log(stdout, message, with_time);
}



