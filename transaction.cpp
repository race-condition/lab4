//-----------------------------------------------------------------------------
// Transaction class: is a an abstract class which is a unified interface of
// all of the Transaction available within program. Includes the following
// features:
// -- create a Transaction object
// -- execute certain actions of a Transaction
//-----------------------------------------------------------------------------

#include "transaction.h"

using namespace std;

// Constructor
Transaction::Transaction(){}
    
// Destructor
Transaction::~Transaction(){}

//display
void Transaction::display()
{
   cout << endl;
}
