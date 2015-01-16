/*	Author: Jan Christian Chavez-Kortlang
*	Student ID: 1202073942
*	Class: CSE310 - Nakamura M/W @ 10:30am
*/

#include "LinkedList.h"
#include "Assignment1.h"

LinkedList* list = new LinkedList();
bool quitProgram = false;

int main()
{
	char userInput;

	displayUserOptions();

	while (!quitProgram)
	{
		std::cout << "What action would you like to perform?" << std::endl;
		std::cin >> userInput;
		processResponse(userInput);
	}
	return 0;
}

void displayUserOptions()
{
	std::cout << "Choose an Action" << std::endl
		<< "----- -----" << std::endl
		<< "A\tAdd a Customer" << std::endl
		<< "D\tDisplay Customer(s)" << std::endl
		<< "Q\tQuit" << std::endl
		<< "R\tRemove a Customer" << std::endl
		<< "?\tDisplay Help" << std::endl;
}
bool processResponse(char response)
{
	if (response == 'a' || response == 'A')
	{
		addCustomerAction();
	}
	else if (response == 'd' || response == 'D')
	{
		displayCustomerAction();
	}
	else if (response == 'q' || response == 'Q')
	{
		quitAction();
	}
	else if (response == 'r' || response == 'R')
	{
		removeCustomerAction();
	}
	else if (response == '?')
	{
		displayUserOptions();
	}
	else
	{
		std::cout << "Your input was invalid." << std::endl;
		return false;
	}
	return true;
}
void addCustomerAction()
{
	std::string firstName, lastName;
	double initialBalance;
	int index;

	std::cout << "Please enter the customer's information." << std::endl;
	std::cout << "First Name:" << std::endl;
	std::cin >> firstName;
	while (firstName.empty())
	{
		std::cout << "Name should not be empty. Enter a proper first name." << std::endl;
		std::cin >> firstName;
	}
	std::cout << "Last Name:" << std::endl;
	std::cin >> lastName;
	while (lastName.empty())
	{
		std::cout << "Name should not be empty. Enter a proper last name." << std::endl;
		std::cin >> lastName;
	}
	std::cout << "Enter a cash amount." << std::endl;
	std::cin >> initialBalance;
	while (initialBalance < 0)
	{
		std::cout << "The specified balance is invalid. Input a positive value." << std::endl;
		std::cin >> initialBalance;
	}
	std::cout << "Enter the index in which to insert the customer." << std::endl;
	std::cin >> index;
	while (index < 0)
	{
		std::cout << "Index value cannot be negative. Try again." << std::endl;
		std::cin >> index;
	}
	
	if (list->addElement(firstName, lastName, initialBalance, index))
		std::cout << "The customer " << firstName << " " << lastName << " added" << std::endl;
	else 
		std::cout << "The customer " << firstName << " " << lastName << " was NOT added" << std::endl;
}
void displayCustomerAction()
{
	list->printList();
}
void removeCustomerAction()
{
	if (list == NULL || list ->getSize() == 0)
		std::cout << "The list is empty. There are no accounts to remove." << std::endl;
	else
	{
		std::string firstName, lastName;

		std::cout << "Please enter a customer to remove:" << std::endl;
		std::cout << "Enter a first name:" << std::endl;
		std::cin >> firstName;
		std::cout << "Enter a last name:" << std::endl;
		std::cin >> lastName;
		if (list->removeElement(firstName, lastName))
			std::cout << "The customer " << firstName << " " << lastName << " removed" << std::endl;
		else
			std::cout << "The customer was not found." << std::endl;
	}
}

void quitAction()
{
	quitProgram = true;
	list->~LinkedList();
}