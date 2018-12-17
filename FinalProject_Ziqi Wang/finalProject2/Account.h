#pragma once
//
//Ziqi Wang 12/17/2018
//
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "fileReadWrite.h"
#include "timeCall.h"
#include <sstream>
using namespace std;
#ifndef FINALPROJECT_ACCOUNT_H
#define FINALPROJECT_ACCOUNT_H
class Account {//abstract class for bank account and stock account
public:
	virtual ~Account();

	Account();

	double getCASH_BALANCE() const;

	virtual void updatePortfolio() = 0;

	virtual void setCASH_BALANCE(double) = 0;


protected:
	double CASH_BALANCE;
};
#endif //FINALPROJECT_ACCOUNT_H
