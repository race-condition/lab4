//-----------------------------------------------------------------------
//item is an object that represents a generic item that can be checked out
//Includes:
//--records the number of copies of an item and the number checked out
//--Item is the parent class for book objects (and possibly others if added)
//Assumptions:
//--assumes correct and valid input of item data (total copies ect.)
//------------------------------------------------------------------------

#include "item.h"

using namespace std;

//-------------------------------------------------------------------
//default constructor
Item::Item()
{
   itemType = 'I';
   totalCopies = 0;
   checkedOutCopies = 0;
}

//-------------------------------------------------------------------
//destructor
Item::~Item(){};

//-------------------------------------------------------------------
//function for getting number of checked out copies of an item
//returns number of checked out copies of item
int Item::getCheckedOutCopies() const
{
   return checkedOutCopies;
}

//-------------------------------------------------------------------
//function for getting item type of an item
//returns item type of item
char Item::getItemType() const
{
   return itemType;
}

//-------------------------------------------------------------------
//function for getting number of total copies of an item
//returns total copies of item
int Item::getTotalCopies() const
{
   return totalCopies;
}

//-------------------------------------------------------------------
//function for setting number of checked out copies of an item
//parameter is the number of copies
void Item::setCheckedOutCopies(int copies)
{
   checkedOutCopies = copies;
}

//-------------------------------------------------------------------
//function for setting item type of an item
//parameter is the item type
void Item::setItemType(char type)
{
   itemType = type;
}

//-------------------------------------------------------------------
//function for setting number total copies of an item
//parameter is the number of copies total
void Item::setTotalCopies(int total)
{
   totalCopies = total;
}



