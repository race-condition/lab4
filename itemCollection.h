//-----------------------------------------------------------------
// This is a collection of of the items contained in the library.
//Includes:
//--All of the items are stored in a BST in the form of a list.
//--Contains methods for inserting, retrieving and displaying items
//contained in the itemcollection.
//Assumptions:
//--itemcollection assumes access to itemTree class (BST of items)
//------------------------------------------------------------------

#ifndef ITEMCOLLECTION_H
#define ITEMCOLLECTION_H

#include "item.h"
#include <string>
#include "itemTree.h"
#include <iostream>

const int MAXSIZE = 26;

class ItemCollection {

public:

	//constructor
	ItemCollection();
	
	//destructor
	~ItemCollection();
	
	//insert an item into the hashtable
	bool insert(Item*);

	//retrieve an item from the hashtable
	//first item parameter is for comparison
   //second item parameter is for returning the item found
	bool retrieve(const Item&, Item*&) const;

	//display entire itemcollection
	void display() const;

private:

	//binary search tree contains items sorted by itemtype
	ItemTree* itemTreeArray[MAXSIZE];

	//method for hasing items into itemTreeArray
	int hash(char) const;
	
	//helper method to retrieve an item from the hashtable using a string
	//which contains searching criteria of an Item
	bool retrieve(std::string, Item*&) const;

};

#endif
