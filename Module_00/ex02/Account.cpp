#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstdio>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	int p_amount = _amount;
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused\n";
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

Account::Account(int initial_deposit) {
	_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::_displayTimestamp( void ) {
	time_t now = time(0);
	tm *ltm = localtime(&now);
	printf("[%d%.2d%.2d_%.2d%.2d%.2d] ",1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday, 5+ltm->tm_hour, 30+ltm->tm_min, ltm->tm_sec);
}