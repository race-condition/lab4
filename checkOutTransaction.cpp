//-----------------------------------------------------------------------------
// CheckOutTransaction class: is a class which is responsible for creating
// CheckOutTransaction object and execute checkOut opertions on ItemCollection
// and UserCollection objects. The class implements following methods:
// -- create
// -- execute
//
// Assumptions:
// -- the create method creates and returns object CheckOutTransaction only if
//    the provided data is correct, otherwise return NULL
//--Only books can be checked out, not generic items
//-----------------------------------------------------------------------------

#include "checkOutTransaction.h"

using namespace std;

//-----------------------------------------------------------------------------
// Default constructor
//sets to default values for easy error checking
CheckOutTransaction::CheckOutTransaction()
{
   userId = 0;
   citemType = 'Z';
   itemFormat = 'Z';
   itemTitle = "Z";
}

//-----------------------------------------------------------------------------
// Default constructor
CheckOutTransaction::CheckOutTransaction
(int tempid, char itype, char iformat, string ides)
{
   userId = tempid;
   citemType = itype;
   itemFormat = iformat;
   itemTitle = ides;
}

//-----------------------------------------------------------------------------
// Destructor
CheckOutTransaction::~CheckOutTransaction(){}

//-----------------------------------------------------------------------------	
//display
void CheckOutTransaction::display()
{
   cout << "Checkout " << " " << citemType << " " << itemFormat << " " <<
   itemTitle << " ";
}

//-----------------------------------------------------------------------------
// create
// This method parses the data out of the string and then checks the data.
// If the data is correct, creates the ChechOutTransaction object and
// returns it, otherwise does not create the object and returns NULL
//parameters are userId, itemType, itemFormat, itemDescription
Transaction* CheckOutTransaction::create(ifstream& infile)
{
   int tempid;
   Transaction* fail = NULL;
   //read in the user id first
   infile >> tempid;
   if (infile.eof())
   {
    return fail;
   }
   //read in the type
   ItemFactory tempfact;
   Item* itemp = tempfact.createtrans(infile);
   cout << "........." << itemp->getTitle() << "........";
   //use the type to create an item using item factory 
   //and extract the information from the book
   if(itemp != NULL)
   {
      CheckOutTransaction* newcheck = new CheckOutTransaction
      (tempid, itemp->getItemType(), 'H', itemp->getTitle());
      return newcheck;
   }
   else
   return fail;
}

//-----------------------------------------------------------------------------
// execute
// This method executes checkOut operation on ItemCollection and
// UserCollection objects
//parameters are the itemCollection being searched and
//the usercollection being searched
void CheckOutTransaction::execute(ItemCollection* tempic, UserCollection* tempuc)
{
   //find the item that was checked out and change the quantity available if able
   Item* tempbook = new Book;
   Item* tempitem = new Book;
   //use item factory here 
   tempbook->setItemType(citemType);
   tempbook->setTitle(itemTitle);
   //attempt to retrieve the item from the itemcollection
   if(tempic->retrieve(*tempbook, tempitem))
   {
      //change the quantity of item available if it is available
      //fails if there are no copies left
      if(tempitem->getCheckedOutCopies() < tempitem->getTotalCopies()) 
      { 
         //attempt to retrieve the user who is checking out book
         //fails if user does not exsist
         User* tempuser = NULL;
         if(tempuc->retrieve(userId, tempuser))
         {
            //change the number of checked out copies available
            tempitem->setCheckedOutCopies(tempitem->getCheckedOutCopies() + 1);
            //tcopy is a copy of this transaction
           // CheckOutTransaction* tcopy = new CheckOutTransaction
              //                         (userId, citemType, itemFormat, itemTitle);
             //add this transaction to the history
            tempuser->getHistory()->add(this);
            tempuser->borrow(tempitem);
         }
      }
   }
   delete tempbook;
}



