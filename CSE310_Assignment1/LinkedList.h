	/*	Author: Jan Christian Chavez-Kortlang
	*	Student ID: 1202073942
	*	Class: CSE310 - Nakamura M/W @ 10:30am
	*/

	#ifndef LINKEDLIST_H
	#define LINKEDLIST_H

	#include "BankAccountNode.h"

	class LinkedList
	{
	public:
		LinkedList();
		~LinkedList();
		explicit LinkedList(BankAccountNode* HEADnode);
		bool addElement(std::string firstName, std::string lastName, double initBalance, unsigned int index);
		bool removeElement(std::string firstName, std::string lastName);
		void printList();
		BankAccountNode* getNodeAt(unsigned int index);
		int getSize();
		BankAccountNode* getHEAD();
	private:
		BankAccountNode* m_HEAD;
		unsigned int m_listSize;
	};
	#endif