//-----------------------------------------------------------------------
//item is an object that represents a generic item that can be checked out
//Includes:
//--records the number of copies of an item and the number checked out
//--Item is the parent class for book objects (and possibly others if added)
//Assumptions:
//--assumes correct and valid input of item data (total copies ect.)
//------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <fstream>
#include <string>

class Item{

public:

	//default constructor
    Item();

	//destructor
	virtual ~Item();

    //retrieve the item type
    char getItemType() const;

    //manually set the itemtype
    void setItemType(char);

    //set the total number of copies of item
    void setTotalCopies(int);

    //retrieve the total copies of item
    int getTotalCopies() const;

    //set the number of copies checked out
    void setCheckedOutCopies(int);

    //retrieve number of copies checked out
    int getCheckedOutCopies() const;

    //overloaded comparison operators
    virtual bool operator<(const Item &) const = 0;
    
     //overloaded comparison operators
    virtual bool operator==(const Item &) const = 0;
   
    //create an item
    virtual Item* create(std::ifstream&) = 0;
    
    //create an item
    virtual Item* createtrans(std::ifstream&) = 0;

	 //get description of an Item, like author, title, date
	 virtual void getDescription() const = 0;
	 
	 //retrieve the title
    virtual std::string getTitle() const = 0;

    //set the title to the string parameter
    virtual void setTitle(std::string) = 0;

protected:

    //designates what the item is (in this case 'i' for item)
    char itemType;

    //totalcopies keeps track of the number of copies of an item there are
    int totalCopies;

    //checkedoutcopies keeps track of how many of the copies are
    //checked out
    int checkedOutCopies;
};

#endif
