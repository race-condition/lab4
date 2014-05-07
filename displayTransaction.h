//-----------------------------------------------------------------------------
// DisplayTransaction class: is a class which is responsible for creating
// DisplayTransaction object and execute display operation on ItemCollection.
// The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// - the create method creates and returns object DisplayTransaction only if
//   the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------


#ifndef DISPLAYTRANSACTION_H
#define DISPLAYTRANSACTION_H

#include <string>
#include "transaction.h"

class DisplayTransaction: public Transaction {

public:
	// Default constructor
	DisplayTransaction();

	// Destructor
	~DisplayTransaction();
   
   //display
   void display();
	
	// create
	// This method parses the data out of the string and then checks the data.
	// If the data is correct, creates the DisplayTransaction object and
	// returns it, otherwise does not create the object and returns NULL
	virtual Transaction* create(std::ifstream&);

	// execute
	// This method executes display operation on an ItemCollection object
	virtual void execute(ItemCollection*, UserCollection*);
};

#endif
