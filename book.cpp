//----------------------------------------------------
//Book class: a class that defines a book object
//--Parent class of periodical and nonperiodical
//--Child class of item
//Includes:
//--creats book objects will all datamembers that are common to all books
//--comparison operators
//--get and set datamembers
//Assumptions:
//--Assumes that no two different books have the same title
//--Assumes that valid input is given for datamembers
//----------------------------------------------------

#include "book.h"
using namespace std;

//-------------------------------------------------------------------
//default constructor
Book::Book()
{
   title = "notitle";
   year = 0;
   format = 'H';
   itemType = 'B';
   checkedOutCopies = 0;
   totalCopies = 1;
}

//-------------------------------------------------------------------
//constuctor with title and year input
Book::Book(string intitle, int inyear)
{
   title = intitle;
   year = inyear;
   format = 'H';
   itemType = 'B';
   checkedOutCopies = 0;
   totalCopies = 1;
}

//-------------------------------------------------------------------
//gettitle returns the title of the book
string Book::getTitle() const
{
   return title;
}

//-------------------------------------------------------------------
//settitle sets the title of the book
void Book::setTitle(string intitle)
{
   title = intitle;
}

//-------------------------------------------------------------------
//retrieve the publication date of the media
int Book::getYear() const
{
   return year;
}

//-------------------------------------------------------------------
//set the publication date of the media
void Book::setYear(int inyear)
{
   year = inyear;
}

//overloaded comparison operators
//parameter represents right hand side
 bool Book::operator<(const Item& rhs) const
{
   //cast item to book
   const Book& rhsbook = static_cast<const Book&>(rhs);
   //compare book titles and year
   if(getTitle().compare(rhsbook.getTitle()) < 0)
      return true;
   else
      return false;
}

//overloaded comparison operators
//parameter represents right hand side
 bool Book::operator==(const Item& rhs) const
{
   //cast item to book
   const Book& rhsbook = static_cast<const Book&>(rhs);
   //compare book titles and year
   if(getTitle().compare(rhsbook.getTitle()) == 0)
      return true;
   else
      return false;
}

//create an item
Item* Book::create(ifstream& infile)
{
   Item* tempbook = new Book;
   return tempbook;
}

//create an item
Item* Book::createtrans(ifstream& infile)
{
   Item* tempbook = new Book;
   return tempbook;
}

//get description of a book, like author, title, date
void Book::getDescription() const{}







