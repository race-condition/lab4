//----------------------------------------------------------------
//Periodical is the class for creating objects that are periodicals
//Includes:
//--Parent class is book.
//--Keeps track of all relevant information for a periodical
//Assumptions:
//--assumes valid and correct input for data members
//----------------------------------------------------------------

#include "periodical.h"
#include <sstream>
#include <iostream>

using namespace std;

//-------------------------------------------------------------------
 //default constructor
 Periodical::Periodical()
{
   title = "notitle";
   month = 0;
   year = 0;
   format = 'H';
   itemType = 'P';
   checkedOutCopies = 0;
   totalCopies = 1;
}

//-------------------------------------------------------------------
//constructor with parameters are the title, month, and year
Periodical::Periodical(string intitle, int inmonth, int inyear)
{
   title = intitle;
   month = inmonth;
   year = inyear;
   format = 'H';
   itemType = 'P';
   checkedOutCopies = 0;
   totalCopies = 1;
}

//-------------------------------------------------------------------
//retrieve the month of the book's publishing
int Periodical::getMonth() const
{
   return month;
}

//-------------------------------------------------------------------
//set the month of the book's publishing
void Periodical::setMonth(int inmonth)
{
   month = inmonth;
}

//-------------------------------------------------------------------
//create and return a pointer to a book
Item* Periodical::create(ifstream& infile)
{
   Periodical* temp = new Periodical;
   int tempyear;
   int tempmonth;
   string temptitle;
   
   getline(infile, temptitle, ',');
   temp->setTitle(temptitle);
   
   infile.get();
   infile >> tempmonth;
   temp->setMonth(tempmonth);
   infile.get();
   
   infile >> tempyear;
   temp->setYear(tempyear);
   infile.get();
   
   return temp;
}

//-------------------------------------------------------------------
//create and return a pointer to a book
Item* Periodical::createtrans(ifstream& infile)
{
   Periodical* temp = new Periodical;
   int tempyear;
   int tempmonth;
   string temptitle;
   infile >> tempyear;
   infile.get();
   infile >> tempmonth;
   infile.get();
   getline(infile, temptitle, ',');
   temp->setTitle(temptitle);
   return temp;
}

//-------------------------------------------------------------------
//return description string
void Periodical::getDescription() const
{ 
   int available;
   available = (getTotalCopies() - getCheckedOutCopies());
   cout << available << " " <<  year << " " << month << " " << title;
}





