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

#ifndef HISTORYTRANSACTION_H
#define HISTORYTRANSACTION_H

#include "transaction.h"
#include <stdlib.h>
#include <string>

class HistoryTransaction : public Transaction {

public:

    // Default constructor
    HistoryTransaction();
    
     //constructor
    HistoryTransaction(int);

    // Destructor
    ~HistoryTransaction();
    
    //set id
    void setUserID(std::string);
    
    //display
   void display();

    // create
    // This method parses the date out of the string and then checks the data.
    // If the data is correct, creates the HistoryTransaction object and
    // returns it, otherwise does not create the object and returns NULL
    virtual Transaction* create(std::ifstream&);

    // execute
    // This method executes history operation on an UserCollection object
    virtual void execute(ItemCollection*, UserCollection*);

private:
   
   //user id
   int userID;

};

#endif
