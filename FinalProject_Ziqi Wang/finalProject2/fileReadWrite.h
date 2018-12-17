#pragma once
//
//Ziqi Wang 12/17/2018
//

#include<vector>
#include<yvals.h>
#if (_MSC_VER>=1600)
#define __STDC_UTF_16__
#endif // (_MSC_VER>=1600)
#include "mex.h"
#include<engine.h>
#include <time.h>
#include <cmath>
#include "Linkedlist.h"
#include <fstream>
#include <iomanip>
#include <ostream>
#include<algorithm>
#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmex.lib")
#pragma comment(lib, "libeng.lib")

#define RESULT_1 "Result_1.txt";
#define RESULT_2 "Result_2.txt";
#define CASHBALANCE "bankCashBalance.txt";
#define BANKHISTORY "bankAccountHistory.txt";
#define TRANACTIONHISTORY "transactionHistory.txt";
#define PORTFOLIO "portfolio.txt";
#define TOTALVALUE  "totalValue.txt";
#ifndef FINALPROJECT_FILEREADWRITE_H
#define FINALPROJECT_FILEREADWRITE_H
class iofile {//class for write and read files
public:
	iofile();

	virtual ~iofile();
	void writeToPortfolio(LinkedList*);
	void writeTofile(const char*, double);
	void writeToBankHistory(string, double, double, int);
	void writeToTransactionHistory(string, string, double, int, bool);
	void readFromHistory(const char*);
	void writeTototalValue(double, string, string);
	string GetData(string str, string dataType);
	string SearchName(const char* fileName, string name);
	const char* selectFile();
	string readCashBalance();
	void DrawGraph();
	void inital();// at the beginning of the main, read cash balance, set file format.
private:
};
#endif //FINALPROJECT_FILEREADWRITE_H
