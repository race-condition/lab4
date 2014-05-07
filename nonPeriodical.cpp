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
 
 #include <string>
 #include "nonPeriodical.h"
 
 using namespace std;
 
 //-------------------------------------------------------------------
  //default constructor
  NonPeriodical::NonPeriodical()
  {
   title = "notitle";
   year = 0;
   format = 'H';
   itemType = 'N';
   checkedOutCopies = 0;
   totalCopies = 1;
  }

//-------------------------------------------------------------------
    //constructor with author, title, and year parameters
  NonPeriodical::NonPeriodical(string inauthor, string intitle, int inyear)
 {
   title = intitle;
   author = inauthor;
   year = inyear;
   format = 'H';
   itemType = 'N';
   checkedOutCopies = 0;
   totalCopies = 1;
 }

//-------------------------------------------------------------------
//return the author as a string
string NonPeriodical::getAuthor() const
{
   return author;    
}

//-------------------------------------------------------------------
//set the author of the book
void NonPeriodical::setAuthor(string inauthor)
{
   author = inauthor;
}
