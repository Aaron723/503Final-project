#pragma once
//
// Ziqi Wang 12/17/2018
//
#include "Account.h"
#ifndef FINALPROJECT_BANKACCOUNT_H
#define FINALPROJECT_BANKACCOUNT_H
class BankAccount :public Account {// derived class of Account
public:
	void setCASH_BALANCE(double);
	void deposit(double);
	void withdraw(double);
	void printHistory();
	void updatePortfolio();//bridge design pattern
	BankAccount();

	virtual ~BankAccount();

};
#endif //FINALPROJECT_BANKACCOUNT_H