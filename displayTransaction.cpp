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

#include "displayTransaction.h"

using namespace std;

//Default constructor
DisplayTransaction::DisplayTransaction(){}

// Destructor
DisplayTransaction::~DisplayTransaction(){}
   
//display
void DisplayTransaction::display()
{
   cout << "Display";
}
	
// create
// This method parses the data out of the string and then checks the data.
// If the data is correct, creates the DisplayTransaction object and
// returns it, otherwise does not create the object and returns NULL
Transaction* DisplayTransaction::create(ifstream& infile)
{
   DisplayTransaction* distemp = new DisplayTransaction;
   return distemp;
}

// execute
// This method executes display operation on an ItemCollection object
void DisplayTransaction::execute(ItemCollection* tempcoll, UserCollection* tempuser)
{
   cout << "ItemCollection: " <<endl;
   tempcoll->display();
}
