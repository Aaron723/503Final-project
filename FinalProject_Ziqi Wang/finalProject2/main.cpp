
//Ziqi Wang 12/17/2018
#include <iostream>
#include "Linkedlist.h"
#include "fileReadWrite.h"
#include "timeCall.h"
#include "Account.h"
#include "BankAccount.h"
#include "StockAccount.h"
void mainMenu();
void StockMenu();
void BankMenu();
void bankManage();
void stockManage();



int main() {
	iofile iofile1;
	iofile1.inital();
	int choice;
	mainMenu();
	cout << "Option: ";
	cin >> choice;
	cout << "\n";
	if (choice > 3 || choice < 1)
	{
		cout << "Wrong option! The option should between 1~3" << endl;
		cout << "Option: ";
		cin >> choice;
	}
	while (1)
	{
		switch (choice)
		{
		case 1:
		{
			stockManage();
			return 0;
		}
		case 2:
		{
			bankManage();
			return 0;
		}
		case 3:
		{
			return 0;
		}
		}

	}
	return 0;
}
void mainMenu() {//interface of main menu
	cout << "Welcome to the Account Management System." << endl;
	cout << "Please select an account to access:" << endl;
	cout << "1. Stock Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit" << endl;
}
void stockManage() {
	int choice;
	StockAccount *stockAccount = new StockAccount;
	while (true)
	{
		StockMenu();
		cout << "Option: ";
		cin >> choice;
		if (choice > 7 || choice < 1)
		{
			cout << "The option number is wrong. Please enter a option between 1 and 7." << endl;
			cout << "Option: ";
			cin >> choice;
		}
		cout << "\n";
		switch (choice)
		{
		case 1:
		{
			string stockName;
			cout << "Please enter the stock symbol: ";
			cin >> stockName;
			iofile iofile1;
			string price = iofile1.SearchName(iofile1.selectFile(), stockName);
			cout << "Company symbol price per share\n";
			cout << stockName << " $" << price << endl;
			break;
		}
		case 2:
		{
			stockAccount->printPortfolio();
			break;
		}
		case 3:
		{
			string stockName;
			cout << "Please enter the stock name you wish to purchase: ";
			cin >> stockName;
			int shares;
			double expectPrice;
			cout << "Please enter the number of shares: ";
			cin >> shares;
			cout << "Please enter the maximum price you are willing to pay per share: ";
			cin >> expectPrice;
			stockAccount->buyStock(stockName, shares, expectPrice);
			cout << "\n";
			break;
		}
		case 4:
		{
			string stockName;
			cout << "Please enter the stock name you want to sell: ";
			cin >> stockName;
			int shares;
			double expectPrice;
			cout << "Please enter the number of shares: ";
			cin >> shares;
			cout << "Please enter the minmum price you are willing to sell per share: ";
			cin >> expectPrice;
			stockAccount->sellStock(stockName, shares, expectPrice);
			break;
		}
		case 5:
		{
			stockAccount->printTransactionHistory();
			cout << "\n";
			break;
		}
		case 6:
		{
			iofile iofile1;
			iofile1.DrawGraph();
			break;
		}
		case 7:
		{
			stockAccount->updatePortfolio();//update total value when exit
			main();
			return;
		}
		}
	}
	return;
}
void StockMenu() {//interface of stock account
	cout << "Please select an option:" << endl;
	cout << "1. Display the price of a stock symbol." << endl;
	cout << "2. Display the current portfolio." << endl;
	cout << "3. Buy shares." << endl;
	cout << "4. Sell shares." << endl;
	cout << "5. View transaction history." << endl;
	cout << "6. View a graph for the portfolio value." << endl;
	cout << "7. Return to main menu." << endl;

}

void BankMenu() {//interface of bank account
	cout << "Please select an option" << endl;
	cout << "1. Check account balance." << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Print out deposit/withdraw history." << endl;
	cout << "5. Return to main menu" << endl;
}
void bankManage() {
	int choice;
	BankAccount *bankAccount = new BankAccount;
	while (true) {
		BankMenu();
		cout << "Option: ";
		cin >> choice;
		if (choice > 5 || choice < 1) {
			cout << "Unavailable option! Please enter a number between 1 and 5." << endl;
			cout << "Option: ";
			cin >> choice;
		}
		cout << endl;
		switch (choice) {
		case 1:
		{
			double cash = bankAccount->getCASH_BALANCE();
			cout << setiosflags(ios::fixed) << setprecision(2);
			cout << "1. You have $" << cash << " in your bank account" << endl;
			cout << endl;
			break;
		}
		case 2:
		{
			double depositAmount;
			cout << "Please enter the amount you wish to deposit: $";
			cin >> depositAmount;
			bankAccount->deposit(depositAmount);
			break;
		}
		case 3:
		{
			double withdrawAmount;
			cout << "Please enter the amount you wish to withdraw: $";
			cin >> withdrawAmount;
			bankAccount->withdraw(withdrawAmount);
			break;
		}
		case 4:
		{
			bankAccount->printHistory();
			cout << endl;
			break;
		}
		case 5: {
			bankAccount->updatePortfolio();//update total value when exit
			main();
			return;
		}
		}
	}

}