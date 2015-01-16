/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <iostream>
#include <iomanip>

class BankAccount
{
public:
	BankAccount(std::string, std::string);
	BankAccount(std::string firstName, std::string lastName, double initialBalance);
	bool hasSameNameAs(std::string firstName, std::string lastName);
	std::string getFirstName();
	std::string getLastName();
	std::string getFullName();
	void displayBankAccount();
private:
	std::string m_firstName;
	std::string m_lastName;
	double m_accountBalance;
};
#endif