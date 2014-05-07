//------------------------------------------------------------------
//Fiction class represents fiction books
//includes:
//--Fiction objects contain all information necessary for identification
//--comparison operators that are necessary for BST
//--Parent class of fiction is nonperiodical
//Assumptions:
//--Assumes correct input for book information
//-----------------------------------------------------------------

#ifndef FICTION_H
#define FICTION_H

#include "nonPeriodical.h"
#include <iostream>
#include <string>

class Fiction : public NonPeriodical{

public:
    //default constructor
	Fiction();
	
    //constructor with parameters for author, title, year
    Fiction(std::string, std::string, int);
	
    //create an item
    virtual Item* create(std::ifstream&);
    
    //create an item
    virtual Item* createtrans(std::ifstream&);
	
	//get description of a fiction book, like author, title, date
	virtual void getDescription() const;
};

#endif
