run	:Assignment1.o LinkedList.o BankAccount.o BankAccountNode.o
		g++ -o run Assignment1.o LinkedList.o BankAccount.o BankAccountNode.o

Assignment1.o	:Assignment1.cpp Assignment1.h LinkedList.h
			g++ -c Assignment1.cpp

LinkedList.o		:LinkedList.cpp LinkedList.h
			g++ -c LinkedList.cpp

BankAccountNode.o	:BankAccountNode.cpp BankAccountNode.h BankAccount.h
			g++ -c BankAccountNode.cpp

BankAccount.o		:BankAccount.cpp BankAccount.h 
			g++ -c BankAccount.cpp
			
