#pragma once
//
//Ziqi Wang 12/17/2018
//
#include "Account.h"
#include "Linkedlist.h"
#ifndef FINALPROJECT_STOCKACCOUNT_H
#define FINALPROJECT_STOCKACCOUNT_H
class StockAccount : public Account {
public:
	StockAccount();

	virtual ~StockAccount();

	void buyStock(string, int, double);

	void sellStock(string, int, double);

	void printPortfolio();

	void printTransactionHistory();

	void readPortfolio();

	void setCASH_BALANCE(double);

	void updatePortfolio();
private:
	LinkedList *stockList = new LinkedList;
	double totalPortfolio = 0;
};
#endif //FINALPROJECT_STOCKACCOUNT_H
