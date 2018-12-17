#pragma once
//
//Ziqi Wang 12/17/2018
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <time.h>
#include <string>
#include <iostream>
using std::string;
#ifndef FINALPROJECT_TIMECALL_H
#define FINALPROJECT_TIMECALL_H
class timeCall {
public:
	timeCall();

	string getDate();

	string getTime();

	string Converter(int);

	virtual ~timeCall();
};
#endif //FINALPROJECT_TIMECALL_H
