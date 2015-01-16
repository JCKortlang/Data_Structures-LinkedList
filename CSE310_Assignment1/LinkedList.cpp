/*	Author: Jan Christian Chavez-Kortlang
	Student ID: 1202073942
	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#include "LinkedList.h"

LinkedList::LinkedList()
{
	m_HEAD = NULL;
}
LinkedList::LinkedList(BankAccountNode* HEADnode)
{
	m_HEAD = HEADnode;
	if (m_HEAD == NULL)
		m_listSize = 0;
	else
		m_listSize = 1;
};
LinkedList::~LinkedList()
{
	//~BankAccountNode() cycles through its references and deletes them as well.
	if (m_HEAD != NULL)
		delete m_HEAD;

	std::cout << "The number of deleted customers is: " << m_listSize << std::endl;
	m_listSize = 0;
}

/*
	Takes its parameters and creates a BankAccount obj, inserts the obj into a BankAccountNode obj, and places the node obj into its corresponding index.
*/
bool LinkedList::addElement(std::string firstName, std::string lastName, double initBalance, unsigned int index)
{
	if (index > m_listSize || initBalance < 0 || lastName.empty() || firstName.empty())
	{
		std::cerr << "Invalid parameter." << std::endl;
		return false;
	}
	else if (index == 0)
	{
		BankAccount* account = new BankAccount(firstName, lastName, initBalance);
		BankAccountNode* node = new BankAccountNode(account,m_HEAD);
		m_HEAD = node;
	}
	else
	{
		BankAccountNode* iterator = getNodeAt(index - 1);
		BankAccount* account = new BankAccount(firstName, lastName, initBalance);
		BankAccountNode* node = new BankAccountNode(account, iterator->getNextNode());
		iterator->setNextNode(node);
	}
	m_listSize++;
	return true;
}

/*
	Iterators through the existing nodes and compares the parameters to each node's corresponding BankAccount. If a match is found it dereferences, deletes the node, and returns true.
*/
bool LinkedList::removeElement(std::string firstName, std::string lastName)
{
	BankAccountNode *iterator = NULL, *iterator2 = NULL;
	iterator = m_HEAD;

	//Cycle through the list until a match is found or it reaches the end.
	while (iterator != NULL && !iterator->getBankAccount()->hasSameNameAs(firstName, lastName))
	{
		//iterator 2 is always one node behind iterator. - Allows for deletion.
		iterator2 = iterator;
		iterator = iterator->getNextNode();
	}
	//Check to see if the iterator is a match.
	if (iterator != NULL && iterator->getBankAccount()->hasSameNameAs(firstName, lastName))
	{
		//Iterator matches and is pointing at the HEAD.
		if (iterator2 == NULL)
		{
			m_HEAD = iterator->getNextNode();
		}
		//Iterator matches and is not pointing at the HEAD.
		else
		{
			iterator2->setNextNode(iterator->getNextNode());
		}
		//Set the next reference == NULL because ~BankAccountNode() will cycle through any existing references and delete them as well.
		iterator->setNextNode(NULL);
		delete iterator;
		m_listSize--;
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Iterates through the list and invokes each node's BankAccount()->displayBankAccount() function.
*/
void LinkedList::printList()
{
	BankAccountNode* iterator = m_HEAD;
	for (unsigned int i = 0; i < m_listSize; i++)
	{
		iterator->getBankAccount()->displayBankAccount();
		iterator = iterator->getNextNode();
	}
}

/*
	Attempts to iterate to the specified index and return the BankAccountNode obj.
*/
BankAccountNode* LinkedList::getNodeAt(unsigned int index)
{
	if (index >= m_listSize)
	{
		std::cerr << "Specified index is invalid." << std::endl;
		return NULL;
	}
	else
	{
		BankAccountNode* iterator = m_HEAD;
		for (unsigned int i = 0; i < index; i++)
		{
			iterator = iterator->getNextNode();
		}
		return iterator;
	}
}

/*
	Returns the number of elements within the list.
*/
int LinkedList::getSize()
{
	return m_listSize;
}