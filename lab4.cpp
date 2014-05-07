//---------------------------------------------------------------------------
// lab4.cpp
//---------------------------------------------------------------------------
// This code tests the functionality of the classes to perform a few
// operation in the library, such as: check out, return, display and history.
//
// Assumptions:
//   -- text files "users.txt" and "items.txt" and "transactios.txt" exist
//      and are formatted as described
//---------------------------------------------------------------------------

#include "manager.h"


#include "itemCollection.h" //just for test
#include "itemTree.h" //teststuff
#include "periodical.h" //just for test
#include "item.h" //just for test
#include "book.h" //just for test
#include "user.h" //just for test
#include "history.h" //just for test
#include "transaction.h"  //just for test
#include "historyTransaction.h"  //just for test
#include "userCollection.h" //just for test
#include "checkOutTransaction.h" //test
#include "returnTransaction.h"//test
#include "displayTransaction.h"//test
#include "transactionFactory.h"//test
#include "itemFactory.h"//test
#include <string>


#include <fstream>
#include <iostream>

using namespace std;

int main() {
	Manager* manager = new Manager;
	// check if the file with users exists
	ifstream infile1("data4patrons.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager->buildUsers(infile1); 
	// check if the file with items exists
	ifstream infile2("data4books.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager->buildItems(infile2); 

	// check if the file with transactions exists
	ifstream infile3("commandlist.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	manager->processTransaction(infile3);
   delete manager;
	return 0;

}
