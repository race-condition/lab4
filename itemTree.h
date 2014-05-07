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
//-----------------------------------------------------------------------------

#ifndef ITEMTREE_H
#define ITEMTREE_H

#include "item.h"
#include <string>
#include <iostream>
using namespace std;

class ItemTree {

struct Node
{
   Item* item;        // pointer to item object
   Node* left;        // left subtree pointer
   Node* right;       // right subtree pointer
      
   Node (Item *u, Node *l = NULL, Node *r = NULL) 
   {
      item = u;
      left = l;
      right = r;
   }
};

public:

    // Constructor
    ItemTree();

    // Destructor
    ~ItemTree();
    
    //emptys the tree
    void makeEmpty();
    
    //helper for makeEmpty()
    void emptyhelper(Node* current);

    // Insert
    // Insert item into the tree
    bool insert(Item*);

    // Retrieve
    // Retrive item from tree
    bool retrieve(const Item&, Item*&) const;

    //display the entire tree
    void display() const;
     
private:

	Node* root;        // root of the tree
	
	//helper method for displaying itemtree
	void sideways(Node* current, int level) const;
};

#endif
