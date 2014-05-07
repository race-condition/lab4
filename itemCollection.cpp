//-----------------------------------------------------------------
// This is a collection of of the items contained in the library.
//Includes:
//--All of the items are stored in a BST in the form of a list.
//--Contains methods for inserting, retrieving and displaying items
//contained in the itemcollection.
//Assumptions:
//--itemcollection assumes access to itemTree class (BST of items)
//------------------------------------------------------------------

#include "itemCollection.h"

using namespace std;

//-------------------------------------------------------------------------
//constructor
ItemCollection::ItemCollection(){
	for(int i = 0; i < MAXSIZE; i++)
	{
	   itemTreeArray[i] = NULL;
	}
	//these are the available types
	itemTreeArray[hash('Y')] = new ItemTree;
	itemTreeArray[hash('P')] = new ItemTree;
	itemTreeArray[hash('F')] = new ItemTree;
}

//-------------------------------------------------------------------------
//destructor
ItemCollection::~ItemCollection()
{
   for(int i = 0; i < MAXSIZE; i++)
   {
      if(itemTreeArray[i] != NULL)
      {
         delete itemTreeArray[i];
      }
   }
}

//--------------------------------------------------------------------------
//insert an item into the hashtable
//parameter is the item to insert
bool ItemCollection::insert(Item* iteminsert)
{
   //use hash to find the correct index
   int index = hash(iteminsert->getItemType());
   if(itemTreeArray[index] == NULL)
   {
      itemTreeArray[index] = new ItemTree;
   } 
   //call hash to get loctation in array based on iteminsert's itemtype
   //call insert() on the itemTree in the correct location and insert iteminsert
   return itemTreeArray[index]->insert(iteminsert);
}

//---------------------------------------------------------------------------
//method for hasing items into itemTreeArray
//this assumes that the char is lowercase a - z
int ItemCollection::hash(char chtype) const
{
   //performs conversion to valid int for array
   int temp = (int) chtype - 65;
   //checks if itemtype is invalid
   if (temp < 0 || temp > 26)
   {
      //print error message if invalid input given
      cout << "Error IC: Invalid item type";
      //this should make the program crash if used to insert into array
      return -1;
   } 
   return temp;
}

//-------------------------------------------------------------------------------------
//display entire itemcollection
void ItemCollection::display() const
{
   //for each element in the itemTreeArray
   for(int i = 0; i < MAXSIZE; i++)
   {
      if(itemTreeArray[i] != NULL)
      {
      //calls the itemTree's dispaly function
         itemTreeArray[i]->display();
      }
   }
}

//---------------------------------------------------------------------------------
//retrieve an item from the hashtable
//first item parameter is for comparison
//second item parameter is for returning the item found
bool ItemCollection::retrieve(const Item& compitem, Item*& retitem) const
{
   int index = hash(compitem.getItemType());
   itemTreeArray[index]->retrieve(compitem, retitem);
}






