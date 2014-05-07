//-----------------------------------------------------------------------------
// ItemTree class: is a binary search tree ADT that contains item objects.
// Includes the following features:
//  -- Add item to the library
//  -- Display all items in the tree
//  -- Retrieve a specific item
//
// Assumptions:
//  -- item class is assumed to exist elsewhere
//  -- assumes valid item input
//-------------------------------------------------------------------------

#include "itemTree.h"

using namespace std;

//-------------------------------------------------------------------
// Constructor
ItemTree::ItemTree()
{
   root = NULL;
}

//-------------------------------------------------------------------
// Destructor
ItemTree::~ItemTree()
{
   makeEmpty();
}

//-----------------------------------------------------------
//Empties a tree
void ItemTree::makeEmpty(){
	emptyhelper(root);
	root = NULL;
}

//-----------------------------------------------------------
//Empty helper recursive

void ItemTree::emptyhelper(Node* current)
{
	if (current != NULL){
		emptyhelper(current->left);
		emptyhelper(current->right);
		delete current;
		current = NULL;
	}
	return;
}

//-------------------------------------------------------------
// Insert
// Insert item into the tree
bool ItemTree::insert(Item* iteminsert)
{
   if(root == NULL)
   {
      root = new Node(iteminsert);
      return true;
   }
   Node* current = root;
   while(current != NULL)
   {
      if(*current->item < *iteminsert)
      {
         if(current->right == NULL)
         {
            current->right = new Node(iteminsert);
            return true;
         }
         current = current->right;
      }
      else
      {
         if(current->left == NULL)
         {
            current->left = new Node(iteminsert);
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

void ItemTree::display() const 
{
   if(root != NULL)
   {
      if (root->item->getItemType() == 'P')
      {
         cout << "Periodical: " << endl;
         cout << "AVAIL YEAR  MO  TITLE" << endl;
      }
      else if (root->item->getItemType() == 'F')
      {
         cout << "Fiction: " << endl;
         cout << "AVAIL AUTHOR     TITLE YEAR" << endl;
      }
      else
      {
         cout << "Youth: " << endl;
         cout << "AVAIL AUTHOR     TITLE YEAR" << endl;
      }
   }
	sideways(root, 0);
}

//-------------------------------------------------------------------
//helper for display
void ItemTree::sideways(Node* current, int level) const 
{
	if (current != NULL) {
		level++;
		sideways(current->right, level);
       // display information of object
		current->item->getDescription();
		cout << endl;
		sideways(current->left, level);
	}
}

//-------------------------------------------------------------------
//retrieve item return true if successful
//first item parameter is for comparison
//second item parameter is for returning the item found
//IMPORTANT: items to be retrieve must be declared as
//  Item* find = new Fiction; 
//(where Ficiton is the specific type of item to find)

bool ItemTree::retrieve(const Item& itemcomp, Item*& itemfound) const
{
    if(root == NULL)
   {
      return false;
   }
   Node* current = root;
   while(!(*current->item == itemcomp))
   {
      if(*current->item < itemcomp)
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
   itemfound = current->item;
   return true;
}



