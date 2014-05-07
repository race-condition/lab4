//-----------------------------------------------------------------------------
// User class: a class to represent the library patrons. Includes the following
// features:
//-- Get the patron's unique User ID
//-- Get the patron's last name
//-- Get the patron's first name
//-- Get the transaction history
//-- Update the patron's last name
//-- Update the patron's first name
//-- Compare
//
// Assumptions:
//-- User IDs will not start with 0
//-- Assumes User IDs will not change once assigned
//-----------------------------------------------------------------------------

#include "user.h"


using namespace std;

//---------------------------------------------------------------------------
// Constructor default
User::User()
{
   userId = 0;
   firstName = "none";
   lastName = "none";
   History temphist;
   history = temphist;
}

//---------------------------------------------------------------------------
// Constructor
// parameters are id number, first name, last name
User::User( int idnum, string fname, string lname)
{
   userId = idnum;
   firstName = fname;
   lastName = lname;
   History temphist;
   history = temphist;
}

//---------------------------------------------------------------------------    
// Destructor
//the values changed for the user's information
//hide the users information apon deletion
User::~User( )
{
   userId = 0;
   firstName = "0none";
   lastName = "0none";
   for(int i = 0; i < borrowed.size(); i++)
   {
      if(borrowed[i] != NULL)
      {
         delete borrowed[i];
      }
   }
}

//---------------------------------------------------------------------------    
// getId
// Returns the user ID
int User::getID( ) const
{
   return userId;
}

//---------------------------------------------------------------------------
// getLastName
// Return the last name of the user
string User::getLastName() const
{
   return lastName;
}

//---------------------------------------------------------------------------
// getFirstName
// Return the first name
string User::getFirstName() const
{
   return firstName;
}

//---------------------------------------------------------------------------    
// getHistory
// Returns user's transaction history
History* User::getHistory()
{
   cout << "*** Patron ID = " << getID() << endl;
   History* temp;
   temp = &history;
   return temp;
}

//---------------------------------------------------------------------------    
// setHistory
// setss user's transaction history
void User::setHistory(History& temphist)
{
   history = temphist;
}
 
//---------------------------------------------------------------------------
// setLastName
// Changes the user's last name
void User::setLastName(string lname)
{
   lastName = lname;
}

//---------------------------------------------------------------------------    
// setFirstName
// Changes the user's first name
void User::setFirstName(string fname)
{
   firstName = fname;
}

//---------------------------------------------------------------------------    
// operator<
// Overload < operator
//parameter compuser is the user being compared to
//on the right hand side
bool User::operator<(const User& compuser) const
{
   return (getID() < compuser.getID());
}

//---------------------------------------------------------------------------    
// operator==
// Overload == operator
//parameter compuser is the user being compared to
//on the right hand side
bool User::operator==(const User& compuser) const
{
   return (getID() == compuser.getID());
}

//--------------------------------------------------------------------
//adds book to borrowed list
void User::borrow(Item* tempitem)
{
   borrowed.push_back(tempitem);
}

//--------------------------------------------------------------------
//deletes book from borrowed list
void User::returnuser(Item* tempitem)
{
   for(int i = 0; i < borrowed.size(); i++)
   {
      if(*borrowed[i] == *tempitem)
      {
         delete borrowed[i];
         borrowed[i] = NULL;
      }
   }
}

//-----------------------------------------------------------------
//adds book to borrowed list
bool User::checkuser(Item* tempitem)
{
   for(int i = 0; i < borrowed.size(); i++)
   {
      if(*borrowed[i] == *tempitem)
      {
         return true;
      }
   }
   return false;
}









