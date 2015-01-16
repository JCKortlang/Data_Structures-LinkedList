/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/
#include "BankAccount.h"

BankAccount::BankAccount(std::string firstName, std::string lastName)
{
		m_firstName = firstName;
		m_lastName = lastName;
};
BankAccount::BankAccount(std::string firstName, std::string lastName, double initialBalance)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_accountBalance = initialBalance;
};
bool BankAccount::hasSameNameAs(std::string firstName, std::string lastName)
{
	if (firstName.compare(m_firstName) == 0 && lastName.compare(m_lastName) == 0)
		return true;
	else
		return false;
}
std::string BankAccount::getFirstName()
{
	return m_firstName;
}
std::string BankAccount::getLastName()
{
	return m_lastName;
}
void BankAccount::displayBankAccount()
{
	std::cout << "Customer Name: " << m_firstName << " " << m_lastName << std::endl << "Balance Amount: " << std::setprecision(2) << std::fixed << m_accountBalance << " dollars" << std::endl;
};
