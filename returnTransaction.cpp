//-----------------------------------------------------------------------------
// ReturnTransaction class: is a class which is responsible for creating
// ReturnTransaction object and execute return operation on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// -- the create method creates and returns object ReturnTransaction only if
//    the provided data is correct, otherwise return NULL
//-----------------------------------------------------------------------------

#include "returnTransaction.h"

using namespace std;

//-----------------------------------------------------------------------------
// Default constructor
//sets to default values for easy error checking
ReturnTransaction::ReturnTransaction()
{
   userId = 0;
   citemType = 'Z';
   itemFormat = 'Z';
   itemTitle = "Z";
}

//-----------------------------------------------------------------------------
// Default constructor
ReturnTransaction::ReturnTransaction
(int tempid, char itype, char iformat, string ides)
{
   userId = tempid;
   citemType = itype;
   itemFormat = iformat;
   itemTitle = ides;
}

//-----------------------------------------------------------------------------
// Destructor
ReturnTransaction::~ReturnTransaction(){}

//-----------------------------------------------------------------------------	
//display itemtype, itemformat, and title 
void ReturnTransaction::display()
{
   cout << "Return " << " " << citemType << " " << itemFormat << " " <<
   itemTitle << " ";
}

//-----------------------------------------------------------------------------
// create
// This method parses the data out of the string and then checks the data.
// If the data is correct, creates the ChechOutTransaction object and
// returns it, otherwise does not create the object and returns NULL
//parameters are userId, itemType, itemFormat, itemDescription
Transaction* ReturnTransaction::create(ifstream& infile)
{
   int tempid;
   //read in the user id first
   infile >> tempid;
   //read in the type
   ItemFactory tempfact;
   Item* itemp = tempfact.createtrans(infile);
   //use the type to create an item using item factory 
   //and extract the information from the book
   ReturnTransaction* newcheck = new ReturnTransaction
   (tempid, itemp->getItemType(), 'H', itemp->getTitle());
   return newcheck;
}

//-----------------------------------------------------------------------------
// execute
// This method execute return operation on a ItemCollection and
// UserCollection objects.
void ReturnTransaction::execute(ItemCollection* tempic, UserCollection* tempuc)
{
   //find the item that was checked out and change the quantity available if able
   Item* tempbook = new Book;
   Item* tempitem = new Book;
   tempbook->setItemType(citemType);
   tempbook->setTitle(itemTitle);
   //attempt to retrieve the item from the itemcollection
   if(tempic->retrieve(*tempbook, tempitem))
   {
      //change the quantity of item available if it is available
      //fails if there are no checked out copies
      if(tempitem->getCheckedOutCopies() > 0) 
      { 
         //attempt to retrieve the user who is checking out book
         //fails if user does not exsist
         User* tempuser = NULL;
         if(tempuc->retrieve(userId, tempuser))
         {
            //check if this user borrowed this item
            if(!tempuser->checkuser(tempitem))
            {
               //if not do not allow return
               cout << "You can't return a book you didn't check out." << endl;
               delete tempbook;
               delete tempitem;
               return;
            }
            //change the number of checked out copies available
            tempitem->setCheckedOutCopies(tempitem->getCheckedOutCopies() - 1);
            //tcopy is a copy of this transaction
            ReturnTransaction* tcopy = new ReturnTransaction
                                       (userId, citemType, itemFormat, itemTitle);
            //add this transaction to the history
            tempuser->getHistory()->add(tcopy);
            //remove from borrowed books
            tempuser->returnuser(tempitem);
         }
      }
   }
   delete tempbook;
   delete tempitem;
}
	
	
	
