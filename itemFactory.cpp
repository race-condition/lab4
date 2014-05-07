//-----------------------------------------------------------------------------
// ItemFactory class: a factory that produces instances of items. Includes the
// following features:
//  -- Creates items of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 item types are present
//-----------------------------------------------------------------------------

#include "itemFactory.h"

using namespace std;

// constructor
ItemFactory::ItemFactory( )
{
 
   for(int i = 0; i < MAX_FACTORY_SIZE; i++)
	{
	   itemFactory[i] = NULL;
	}
	//these are the available transaction types
	itemFactory[hash('Y')] = new Youth;
	itemFactory[hash('P')] = new Periodical;
	itemFactory[hash('F')] = new Fiction;
}

// destructor
ItemFactory::~ItemFactory( )
{
 for(int i = 0; i < MAX_FACTORY_SIZE; i++)
   {
         if(itemFactory[i] != NULL)
         {
            delete itemFactory[i];
         }
  }
}
    
// creates an item of the desired type
Item* ItemFactory::create(ifstream& infile)
{
  Item* fail = NULL;
  char typetemp;
  //get the item type
  infile >> typetemp;
  if (infile.eof()) return fail;
  //checks if the itemtype is invalid
  if(hash(typetemp) < 0 || itemFactory[hash(typetemp)] == NULL)
  {
   cout << "Error IF: invalid item" << endl;
   string garbage;
   getline(infile,garbage);
   return fail;
  }
  return itemFactory[hash(typetemp)]->create(infile);
}

// creates an item of the desired type
Item* ItemFactory::createtrans(ifstream& infile)
{
  Item* fail = NULL;
  char typetemp;
  //get the item type
  infile >> typetemp;
  if (infile.eof()) return fail;
  //checks if the itemtype is invalid
  if(hash(typetemp) < 0 || itemFactory[hash(typetemp)] == NULL)
  {
   cout << "Error IF: invalid item trans" << endl;
   string garbage;
   getline(infile,garbage);
   return fail;
  }
  //remove next space
  infile.get();
  if (infile.eof()) return fail;
  infile.get();
  if (infile.eof()) return fail;
  infile.get();
  if (infile.eof()) return fail;
  return itemFactory[hash(typetemp)]->createtrans(infile);
}

//hash function
int ItemFactory::hash(char chtype) const
{
   //performs conversion to valid int
   int temp = (int) chtype - 65;
   //checks if itemtype is invalid
   if (temp < 0 || temp > 26)
   {
      //print error message if invalid input given
      cout << "Error IF: Invalid item type";
      //this should make the program crash if used to insert into array
      return -1;
   } 
   return temp;
}
