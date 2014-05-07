//-----------------------------------------------------------------------------
// ItemFactory class: a factory that produces instances of items. Includes the
// following features:
//  -- Creates items of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 item types are present
//-----------------------------------------------------------------------------

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <string>
#include "youth.h"
#include "periodical.h"
#include "fiction.h"
#include "item.h"
#include <fstream>

const int MAX_FACTORY_SIZE = 26;

class ItemFactory {

public:

   // constructor
    ItemFactory( );
    
    // destructor
    ~ItemFactory( );
    
    // creates an item of the desired type
    Item* createtrans(std::ifstream&);
    
    // creates an item of the desired type
    Item* create(std::ifstream&);
  
private:

   // Storage for item creation objects
    Item* itemFactory[MAX_FACTORY_SIZE]; 
    
    //use hash function to get hash index
    int hash(char) const;
};

#endif
