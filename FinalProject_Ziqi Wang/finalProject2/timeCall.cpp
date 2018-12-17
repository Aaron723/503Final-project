//
//Ziqi Wang 12/17/2018
//
#include "timeCall.h"


string timeCall::getDate() {
	string date;
	time_t seconds;
	seconds = time(NULL);
	tm * timeinfo;
	timeinfo = localtime(&seconds);
	string year = (Converter(timeinfo->tm_year + 1900)); string mon = (Converter(timeinfo->tm_mon + 1)); string day = (Converter(timeinfo->tm_mday));
	date = mon + "/" + day + "/" + year;
	return date;
}
string timeCall::Converter(int data) {// convert time/date information to string
	string ss;
	if (data >= 0 && data < 10)
		return ss = "0" + std::to_string(data);
	else
		return ss = std::to_string(data);

}
string timeCall::getTime() {
	string T;
	time_t seconds;
	seconds = time(NULL);
	tm* timeinfo;
	timeinfo = localtime(&seconds);
	string hours = (Converter(timeinfo->tm_hour)); string min = (Converter(timeinfo->tm_min)); string sec = (Converter(timeinfo->tm_sec));
	T = hours + ":" + min + ":" + sec;
	return T;
}

timeCall::~timeCall() {

}

timeCall::timeCall() {}


