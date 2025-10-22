#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* constructors start */
Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
		";amount:" << this->checkAmount() <<
		";created" <<
		std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
		";amount:" << this->checkAmount() <<
		";closed" <<
		std::endl;
}
/* constructors end */

/* public start */
void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = this->checkAmount();
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
		";p_amount:" << p_amount <<
		";deposit:"<< deposit <<
		";amount:" << this->checkAmount() <<
		";nb_deposits:" << this->_nbDeposits <<
		std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
		";amount:" << this->_amount <<
		";deposits:"<< this->_nbDeposits <<
		";withdrawals:" << this->_nbWithdrawals <<
		std::endl;
}
/* public end */
	
/* static public start */
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<
		";total:" << getTotalAmount() <<
		";deposits:" << getNbDeposits() <<
		";withdrawals:" << getNbWithdrawals() <<
		std::endl;
}
/* static public end*/

/* static start */
void	Account::_displayTimestamp(void)
{
	TimePoint timePoint = std::chrono::system_clock::now();
	std::time_t now = std::chrono::system_clock::to_time_t(timePoint);
	std::cout << std::put_time(std::localtime(&now), "[%Y%m%d_%H%M%S]") << " ";
}
/* static end */
