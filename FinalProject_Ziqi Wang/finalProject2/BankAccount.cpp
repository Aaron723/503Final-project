//
// Ziqi Wang 12/17/2018
//
#include "BankAccount.h"
void BankAccount::setCASH_BALANCE(double bankBalance) {
	CASH_BALANCE = bankBalance;
}

BankAccount::BankAccount() {}

void BankAccount::deposit(double cash) {
	if (cash < 0)
	{
		cout << "Error:You can't deposit negative money" << endl;
		return;
	}
	else if (cash == 0)
	{
		cout << "You just do nothing to your cash balance" << endl;
		return;
	}
	CASH_BALANCE += cash;
	iofile fout;
	const char*a = CASHBALANCE;
	fout.writeTofile(a, CASH_BALANCE);
	timeCall timeCall1;
	string date = timeCall1.getDate();
	fout.writeToBankHistory(date, CASH_BALANCE, cash, 1);
	cout << "Deposit success!\n";
}
void BankAccount::withdraw(double cash) {
	if (cash < 0)
	{
		cout << "Error: You can't withdraw negative mony" << endl;
		return;
	}
	else if (cash == 0)
	{
		cout << "You just do nothing to your cash balance" << endl;
		return;
	}
	if (CASH_BALANCE >= cash)
	{
		CASH_BALANCE -= cash;
		cout << "Withdraw success" << endl;
		iofile fout;
		const char*a = CASHBALANCE;
		fout.writeTofile(a, CASH_BALANCE);
		timeCall timeCall1;
		string date = timeCall1.getDate();
		fout.writeToBankHistory(date, CASH_BALANCE, cash, 2);
	}

	else
		cout << "Operation fail! the deposit is less than your withdraw" << endl;

}
void BankAccount::printHistory() {
	iofile iofile1;
	string balance = iofile1.readCashBalance();
	cout << "The cash balance of this account is " << balance << endl;
	const char*fileName = BANKHISTORY;
	iofile1.readFromHistory(fileName);
}
BankAccount::~BankAccount() {}

void BankAccount::updatePortfolio() {
	iofile iofile1;
	double sum = 0;
	const char*a = PORTFOLIO;
	ifstream file(a);
	if (!file.is_open())
	{
		cout << "There is no stock in your portfolio." << endl;
	}
	else
	{
		while (!file.eof())
		{
			char line[100];
			file.getline(line, 100);
			string str = line;
			stringstream ss(str);
			string name;
			getline(ss, name, '\t');
			string shares;
			getline(ss, shares, '\t');

			iofile iofile1;
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			int int_shares = atoi(shares.c_str());
			sum += price * int_shares;
		}


		file.close();
	}

	sum += CASH_BALANCE;
	timeCall timeCall1;
	string time = timeCall1.getTime();
	string date = timeCall1.getDate();
	iofile1.writeTototalValue(sum, time, date);
}
