//
//Ziqi Wang 12/17/2018
//
#include "StockAccount.h"
void StockAccount::setCASH_BALANCE(double stockBalance) {
	CASH_BALANCE = stockBalance;
}

StockAccount::StockAccount() {
	readPortfolio();//every time construct stock account, we grab current portfolio information from txt
}

StockAccount::~StockAccount() {}

void StockAccount::buyStock(string stockName, int shares, double amount) {
	if (shares < 0)
	{
		cout << "Error: The shares number you want to buy can't be negative" << endl;
		return;
	}
	else if (shares == 0)
	{
		cout << "Error: You didn't buy anything" << endl;
		return;
	}
	iofile iofile1;
	const char*fileName = iofile1.selectFile();
	if (iofile1.SearchName(fileName, stockName) != "")
	{
		double price = atof((iofile1.SearchName(fileName, stockName)).c_str());
		timeCall timeCall1;
		string time;
		string date;
		if (price*shares <= CASH_BALANCE && amount >= price)
		{
			CASH_BALANCE -= price * shares;
			iofile iofile2;
			const char *a = CASHBALANCE;
			iofile2.writeTofile(a, CASH_BALANCE);
			if (stockList->changeStockShares(stockName, shares, price, true))//true means buy, false means sell
			{
				iofile iofile3;
				iofile3.writeToPortfolio(stockList);//every time buy stock, write it in portfolio, bankhistory and transaction history
				time = timeCall1.getTime();
				date = timeCall1.getDate();
				iofile1.writeToBankHistory(date, CASH_BALANCE, price*shares, 3);
				iofile1.writeToTransactionHistory(stockName, time, price, shares, true);
				//should I sort with random value red from results? Or just use the old value?
			}
			else
			{
				Node *newNode = new Node(stockName, price, shares);//add new stock to the end if this stock is not in the portfolio
				stockList->addToEnd(newNode);
				iofile iofile3;
				iofile3.writeToPortfolio(stockList);
				time = timeCall1.getTime();
				date = timeCall1.getDate();
				iofile1.writeToBankHistory(date, CASH_BALANCE, price*shares, 3);
				iofile1.writeToTransactionHistory(stockName, time, price, shares, true);
			}
			//true means buy, false means sell

		}
		else if (price*shares > CASH_BALANCE)
		{
			cout << "Your cash balance is not enough! Fail to buy!" << endl;
		}
		else if (price > amount)
		{
			cout << "The current price is more expensive than you want!Fail to buy!" << endl;
		}
	}
	else
	{
		cout << "This stock is not in the results!" << endl;
	}
}

void StockAccount::sellStock(string stockName, int shares, double amount) {// similar to what we do in buy, but remove stock if share==0
	if (shares < 0)
	{
		cout << "Error: The shares number you want to sell can't be negative" << endl;
		return;
	}
	else if (shares == 0)
	{
		cout << "You didn't sell anything" << endl;
		return;
	}
	iofile iofile1;
	const char*fileName = iofile1.selectFile();
	if (iofile1.SearchName(fileName, stockName) != "")
	{
		double price = atof((iofile1.SearchName(fileName, stockName)).c_str());
		if (price < amount)
			cout << "current price is lower than your expect price! Fail to sell!" << endl;
		else if (stockList->changeStockShares(stockName, shares, price, false))
		{
			const char *a = CASHBALANCE;
			CASH_BALANCE += shares * price;
			iofile1.writeTofile(a, CASH_BALANCE);
			cout << "Sucessfully sell the stock!" << endl;
			timeCall timeCall1;
			string time = timeCall1.getTime();
			string date = timeCall1.getDate();
			iofile1.writeToBankHistory(date, CASH_BALANCE, price*shares, 4);
			iofile1.writeToTransactionHistory(stockName, time, price, shares, false);
			iofile iofile2;
			iofile2.writeToPortfolio(stockList);
		}
	}
	else
	{
		cout << "This stock is not in the results! Fail to sell!" << endl;
	}


}
//read stock from stocklist, update each stock's price and sort stock list, then print portfolio.
void StockAccount::printPortfolio() {
	iofile iofile1;
	double sum = 0;
	if (stockList->getMySize() != 0)
	{
		Node* currentNode = stockList->getMyHead();
		while (currentNode != stockList->getMyTail())
		{
			string name = currentNode->getStockName();
			if (name == "")
				break;
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			currentNode->setStockPrice(price);
			sum += price * currentNode->getShares();
			currentNode = currentNode->getNext();
		}
		if (currentNode == stockList->getMyTail())
		{
			string name = currentNode->getStockName();
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			currentNode->setStockPrice(price);
			sum += price * currentNode->getShares();
		}
		Sorter sorter;
		cout << "Please choose if you want to print in decent order or ascend order(1 means decent, 2 means asecnd)\n";
		int i;
		cin >> i;
		if (i < 1 || i>2)
		{
			cout << "Wrong sort choice, please enter again" << endl;
			cin >> i;
		}
		else if (i == 2)
			sorter.Sort(stockList, make_shared<ascendSortStrategy>());
		else if (i == 1)
			sorter.Sort(stockList, make_shared<decentSortStrategy>());
		string cashbal = iofile1.readCashBalance();
		cout << setiosflags(ios::fixed) << setprecision(2);
		cout << "Cash Balance = $" << cashbal << endl;
		cout << std::left << setw(20) << "Company Symbol" << std::left << setw(10)
			<< "Number" << std::left << setw(10) << "Price" << std::left << setw(15) << "Total value" << "\n";
		stockList->printList();
		cout << "Total portfolio = $" << CASH_BALANCE + sum << endl;
	}
	else
	{
		cout << "There is no stock in the portfolio" << endl;
		cout << setiosflags(ios::fixed) << setprecision(2);
		string cashbal = iofile1.readCashBalance();
		cout << "Cash Balance = $" << cashbal << endl;
		cout << "Total portfolio = $" << CASH_BALANCE + sum << endl;
	}
}

void StockAccount::printTransactionHistory() {
	char line[100];
	ifstream file;
	const char*a = TRANACTIONHISTORY;
	file.open(a);
	if (file.is_open())
	{

		while (!file.eof()) {
			file.getline(line, 100);
			string str = line;
			cout << str << endl;
		}
		file.close();
	}
	else
	{
		file.close();
		//       cout<<"Error: fail to open transactionHistory.txt"<<endl;
	}
}

void StockAccount::readPortfolio() {
	const char*a = PORTFOLIO;
	ifstream file(a);
	if (!file.is_open())
	{
		//       cout<<"There is no stock in your portfolio."<<endl;
	}
	else
	{
		double totalValue = 0;
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
			if (name == "")
				return;
			iofile iofile1;
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			int int_shares = atoi(shares.c_str());
			Node* newNode = new Node(name, price, int_shares);
			stockList->addToEnd(newNode);
			totalValue += price * int_shares;
		}
		totalPortfolio = totalValue + CASH_BALANCE;
		Sorter sorter;
		sorter.Sort(stockList, make_shared<decentSortStrategy>());
	}

}

void StockAccount::updatePortfolio() {
	iofile iofile1;
	double sum = 0;
	if (stockList->getMySize() != 0)
	{
		Node* currentNode = stockList->getMyHead();
		while (currentNode != stockList->getMyTail())
		{
			string name = currentNode->getStockName();
			if (name == "")
				break;
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			currentNode->setStockPrice(price);
			
			sum += price * currentNode->getShares();
			currentNode = currentNode->getNext();
		}
		if (currentNode == stockList->getMyTail())
		{
			string name = currentNode->getStockName();
			double price = atof((iofile1.SearchName(iofile1.selectFile(), name)).c_str());
			currentNode->setStockPrice(price);
			sum += price * currentNode->getShares();
		}

	}
	sum += CASH_BALANCE;
	timeCall timeCall1;
	string time = timeCall1.getTime();
	string date = timeCall1.getDate();
	iofile1.writeTototalValue(sum, time, date);
}
