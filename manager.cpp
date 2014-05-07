//-----------------------------------------------------------------------------
// Manager class: is a class which reads data from files and create users,
// items and transactions objects. The User objects are added to the
// UserCollection users and the items objects are added to the ItemCollection
// items. Transaction objects are created and the the function execute is
// called on them. The class implements following methods:
// -- buildUsers
// -- buildItems
// -- processTransaction
//
// Assumptions:
// -- three data files will be provided, one contains information of users, one
//    contains information about items, and one contains transactions that
//    users performed.
// -- the data in each file is in the correct format.
// -- if the data contain incorrect values (e.g. wrong type of book),
//    the object will not be created and therefore added/executed.

//-----------------------------------------------------------------------------

#include "manager.h"

// Default constructor
Manager::Manager()
{
   users = new UserCollection();
   items = new ItemCollection();
}

// Destructor
Manager::~Manager()
{
   delete users;
   delete items;
}

// buildUsers
// This method reads data from file and parse each line to extract user Id,
// firstName, lastName and creates a new User object. Then call method
// insert from UserCollection class.
void Manager::buildUsers(ifstream& infile)
{ 
//while we have not reached the end of the infile
   while (!infile.eof())
   {
      int tempid;
      string tempfirst;
      string templast;
      //read in id
      infile >> tempid;
      if (infile.eof()) return;
      infile.get();
      if (infile.eof()) return;
      //read first name
      getline(infile, tempfirst, ' ');
      if (infile.eof()) return;
      //read last name
      getline(infile, templast);
      if (infile.eof()) return;
      //make a new user
      User* adduser = new User(tempid, tempfirst, templast); 
      //insert the user to the usercollection
      if (users == NULL)
      {
         cout << "ERROR!!!!!!!!!!";
         return;
      }
      if (adduser != NULL)
      {
         users->insert(adduser); //here
      }
   }
}

// buildItems
// This method reads data from file and passes each line to the ItemFactory
// which creates Item object out of it. Then calls method insert from
// ItemCollection class.
void Manager::buildItems(ifstream& infile)
{
   Item* itemp;
   while (!infile.eof())
   {
      itemp = itemFactory.create(infile);
      if(itemp != NULL)
      {
         items->insert(itemp);
      }
   }
}

// ProcessTransaction
// This method read data from file and pass each line to the
// TransactionFactory object which creates Transaction object out of it.
// Then method execute is called on this object.
void Manager::processTransaction(ifstream& infile)
{
   Transaction* ttemp;
   while (!infile.eof())
   {
      ttemp = transactionFactory.createIt(infile);
      if(ttemp != NULL)
      {
         ttemp->execute(items, users);
      }
   }
}




