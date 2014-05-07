//-----------------------------------------------------------------------------
// History class: Represents the history of a patron's transactions. Includes
// the following features:
//  -- Add a new HistoryEntry item to the list
//  -- Display all transaction history for the user
// Assumptions:
//  -- Assumes deleting items from the history will not be necessary
//  -- if an item is mistakenly checked out or returned, performing the
//     opposite function should serve to "undo" the action
//  -- Assumes there is not a need to paginate the history
//  -- Assumes there is not a need to display partial history
//-----------------------------------------------------------------------------

#include "history.h"
#include "transaction.h"

using namespace std;
//-------------------------------------------------------------------------
//constructor
History::History()
{
   data.push_front(NULL);
}

//-------------------------------------------------------------------------
// destructor
History::~History()
{
   while (!data.empty() && data.front() != NULL)
   {
         //show the first data member
         delete data.front();
         //delete last shown data member
         data.pop_front();
   }  
}

//-----------------------------------------------------------------------------
// add a new item
void History::add( Transaction* addtrans )
{
   data.push_front(addtrans);
}

//----------------------------------------------------------------------------
// display the transaction history
void History::display( ) //running over end somewhere
{
   if(!data.empty() && data.front() != NULL){
      list <Transaction*> templist;
      templist = data;
      //while there are transactions in the list
      while (!data.empty() && data.front() != NULL)
      {
         cout << "display" <<endl;
         //show the first data member
         data.front()->display();
         //delete last shown data member
         data.pop_front();
      }  
      //assign the templist back to data to maintain info
      data = templist;
   }
}

//----------------------------------------------------------------------------
// operator=

History& History::operator=(const History & hist){
   this->data = hist.data;
   return *this;
}

