/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#ifndef BANKACCOUNTNODE_H
#define BANKACCOUNTNODE_H

#include "BankAccount.h"

class BankAccountNode
{
public:
	explicit BankAccountNode(BankAccount* bankAccount);
	BankAccountNode(BankAccount* bankAccount, BankAccountNode *nextNode);
	~BankAccountNode();
	BankAccount* getBankAccount();
	BankAccountNode* getNextNode();
	void setNextNode(BankAccountNode* nextNode);

private:
	BankAccount* m_bankAccount;
	BankAccountNode* m_nextAccountNode;
};
#endif