/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#include "BankAccountNode.h"

BankAccountNode::BankAccountNode(BankAccount* bankAccount)
{
	m_bankAccount = bankAccount;
};
BankAccountNode::BankAccountNode(BankAccount* bankAccount, BankAccountNode *nextNode)
{
	m_bankAccount = bankAccount;
	m_nextAccountNode = nextNode;
};

/*
	Deletes all of the BankAccountNode's references. Will recursively delete an entire Linked List if the nextNode is not dereferences before this is called.
*/
BankAccountNode::~BankAccountNode()
{
	if (m_bankAccount != NULL)
		delete m_bankAccount;
	if (m_nextAccountNode != NULL)
		delete m_nextAccountNode;
};
BankAccount* BankAccountNode::getBankAccount()
{
	return m_bankAccount;
}
BankAccountNode* BankAccountNode::getNextNode()
{
	return m_nextAccountNode;
}
void BankAccountNode::setNextNode(BankAccountNode* nextNode)
{
	m_nextAccountNode = nextNode;
}