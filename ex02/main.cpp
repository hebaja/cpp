#include "Account.hpp"

int	main(void)
{
	Account account1(42);
	Account account2(24);

	Account::displayAccountsInfos();
	account1.displayStatus();
	account2.displayStatus();

	account1.makeDeposit(10);
	Account::displayAccountsInfos();
	account1.displayStatus();
	account2.displayStatus();

	account1.makeWithdrawal(5);
	Account::displayAccountsInfos();
	account1.displayStatus();
	account2.displayStatus();


	
	return (0);
}
