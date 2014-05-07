//----------------------------------------------------------
//Non-periodical is a virtual class that represents all books
//that are not periodicals
//Includes:
//--Non-periodical contains identifying information related to individual
//--copies as well as the number of copies of each nonperiodical
//--Non-periodical is a child class of book
//--Non-periodical is a parent class of fiction and youth
//Assumptions:
//--assumes valid and correct input from user for data members
//----------------------------------------------------------

#ifndef NONPERIODICAL_H
#define NONPERIODICAL_H

#include "book.h"
#include <string>

class NonPeriodical : public Book{

public:

    //default constructor
    NonPeriodical();

    //constructor with author, title, and year parameters
    NonPeriodical(std::string, std::string, int);
	
    //return the author as a string
    std::string getAuthor() const;

    //set the author of the book
    void setAuthor(std::string);

    //create an item
    virtual Item* create(std::ifstream&) = 0;
    
    //create an item
    virtual Item* createtrans(std::ifstream&) = 0;
	
	 //get description of a non periodical book, like author, title, date
	 virtual void getDescription() const = 0;

protected:

    //contains author name
    std::string author;
};

#endif
