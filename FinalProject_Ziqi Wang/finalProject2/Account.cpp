//
// Ziqi Wang 12/17/2018
//
#include "Account.h"

double Account::getCASH_BALANCE() const {
	return CASH_BALANCE;
}

Account::Account() {
	iofile iofile1;
	CASH_BALANCE = atof((iofile1.readCashBalance()).c_str());
}
Account::~Account() {}