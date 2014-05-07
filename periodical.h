//----------------------------------------------------------------
//Periodical is the class for creating objects that are periodicals
//Includes:
//--Parent class is book.
//--Keeps track of all relevant information for a periodical
//Assumptions:
//--assumes valid and correct input for data members
//----------------------------------------------------------------

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "book.h"
#include <fstream>
#include <string>

class Periodical : public Book{

public:

    //default constructor
    Periodical();

    //constructor with parameters are the title, month, and year
    Periodical(std::string, int, int);

    //retrieve the month of the book's publishing
    int getMonth() const;

    //set the month of the book's publishing parameter is month
    void setMonth(int);
    
    //create item
    virtual Item* create(std::ifstream&);
    
    //create an item
    virtual Item* createtrans(std::ifstream&);
	
	//get description of a periodical, like title and date
	virtual void getDescription() const;

private:

    //month of publication
    int month;
};

#endif
