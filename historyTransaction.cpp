//-----------------------------------------------------------------------------
// HistoryTransaction class: is a class which is responsible for creating
// HistoryTransaction object and execute history operation on an UserCollection
// object. The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// -- the create method creates and returns object HistoryTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#include "historyTransaction.h"

using namespace std;

// Default constructor
HistoryTransaction::HistoryTransaction()
{
   userID = 0;
}

//constructor
HistoryTransaction::HistoryTransaction(int tempid)
{
   userID = tempid;
}

//display
void HistoryTransaction::display()
{
   cout << "History" << " " << userID << " ";
}

// Destructor
HistoryTransaction::~HistoryTransaction(){}

//set user id
void HistoryTransaction::setUserID(string tempid)
{
   userID = atoi(tempid.c_str());
}

// create
// This method parses the date out of the string and then checks the data.
// If the data is correct, creates the HistoryTransaction object and
// returns it, otherwise does not create the object and returns NULL
Transaction* HistoryTransaction::create(ifstream& infile)
{
   int tempid;
   //read in the user id first
   infile >> tempid;
   HistoryTransaction* transhist = new HistoryTransaction(tempid);
   return transhist;  
}

// execute
// This method executes history operation on an UserCollection object
void HistoryTransaction::execute(ItemCollection* tempic, UserCollection* tempuc)
{
    User* tempuser = NULL;
         if(tempuc->retrieve(userID, tempuser))
         {
            //tcopy is a copy of this transaction
            HistoryTransaction* tcopy = new HistoryTransaction(userID);
             //add this transaction to the history
            //tempuser->getHistory()->add(tcopy);
            //Display history of transactions (includes this transaction)
            tempuser->getHistory()->display();
            cout << endl;
            //cout << endl;
        }
}





