//-----------------------------------------------------------------------------
// User Collection class: a collection that stores library patrons. Includes 
// the following features:
//  -- Add users to the library
//  -- Display a list of library patrons
//  -- Retrieve a specific user
//
// Assumptions:
//  -- Assumes there is not a need to remove a user from the list
//-----------------------------------------------------------------------------

#include "userCollection.h"

using namespace std;

//--------------------------------------------------------------------------------
//constructor
UserCollection::UserCollection()
{
   root = NULL;
}

//---------------------------------------------------------------------------
// Destructor
UserCollection::~UserCollection()
{
   makeEmpty();
}

//-----------------------------------------------------------
//Empties a tree
void UserCollection::makeEmpty(){
	emptyhelper(root);
	root = NULL;
}

//-----------------------------------------------------------
//Empty helper recursive
void UserCollection::emptyhelper(Node* current)
{
	if (current != NULL){
		emptyhelper(current->left);
		emptyhelper(current->right);
		delete current;
		current = NULL;
	}
	return;
}

//------------------------------------------------------------------------------
// insert
// Inserts a user
//parameter is inserted user
bool UserCollection::insert(User* userins)
{
   if(root == NULL)
   {
      root = new Node(userins);
      return true;
   }
   Node* current = root;
   while(current != NULL)
   {
      if(*current->user < *userins)
      {
         if(current->right == NULL)
         {
            current->right = new Node(userins);
            return true;
         }
         current = current->right;
      }
      else
      {
         if(current->left == NULL)
         {
            current->left = new Node(userins);
            return true;
         }
         current = current->left;
      }
   }
   return false;
}

//-------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
void UserCollection::display() const 
{
	sideways(root, 0);
}

//-------------------------------------------------------------------
//helper for display
void UserCollection::sideways(Node* current, int level) const 
{
	if (current != NULL) {
		level++;
		sideways(current->right, level);
		
       // display information of object
		cout << current->user->getID() << " "<<
		current->user->getFirstName() << " "<<
		current->user->getLastName() << endl;
		sideways(current->left, level);
	}
}
    
//-----------------------------------------------------------------------------
// retrive
// Retrives user's object
//parameter id is the id of the user to find
//userout is the user that was found (if any)
bool UserCollection::retrieve(int id, User*& userout) const
{
 if(root == NULL)
   {
      return false;
   }
   Node* current = root;
   while(current->user->getID() != id)
   {
      if(current->user->getID() < id)
      {
         if(current->right == NULL)
         {
            return false;
         }
         current = current->right;
      }
      else
      {
         if(current->left == NULL)
         {
            return false;
         }
         current = current->left;
      }
   }
   userout = current->user;
   return true;
}
