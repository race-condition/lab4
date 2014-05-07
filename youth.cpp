//---------------------------------------------------------------
//Youth represents a book of the genre youth
//Includes:
//--Youth contains functions and data necessary for keeping track
//--of information related to the book (title author etc.)
//--Youth is a child class of non-periodical
//Assumptions:
//--Assumes correct and valid input from user for datamembers
//---------------------------------------------------------------

#include "youth.h"

using namespace std;

//-------------------------------------------------------------------
//default constructor
Youth::Youth()
{
  title = "notitle";
  year = 0;
  format = 'H';
  itemType = 'Y';
  checkedOutCopies = 0;
  totalCopies = 5;
}

//-------------------------------------------------------------------
//constructor with parameters for author, title, year
Youth::Youth(string inauthor, string intitle, int inyear)
{
   title = intitle;
   author = inauthor;
   year = inyear;
   format = 'H';
   itemType = 'Y';
   checkedOutCopies = 0;
   totalCopies = 5;
}

//-------------------------------------------------------------------
//create an item
Item* Youth::create(ifstream& infile)
{
   string tempauthor;
   string temptitle;
   int tempyear;
   
   Youth* temp = new Youth;
   
   getline(infile, tempauthor, ',');
   temp->setAuthor(tempauthor);
   
   infile.get();
   
   getline(infile, temptitle, ',');
   temp->setTitle(temptitle);
   
   infile >> tempyear;
   temp->setYear(tempyear);
   
   infile.get();
   return temp;
}

//-------------------------------------------------------------------
//create an item
Item* Youth::createtrans(ifstream& infile)
{
   string tempauthor;
   string temptitle;
   Youth* temp = new Youth;
   getline(infile, temptitle, ',');
   temp->setTitle(temptitle);
   infile.get();
   getline(infile, tempauthor, ',');
   temp->setAuthor(tempauthor);
   return temp;
}

//-------------------------------------------------------------------
//return description string
void Youth::getDescription() const
{ 
   int available;
   available = (getTotalCopies() - getCheckedOutCopies());
   cout <<  available << " " << title << ", " << author << ", " << year;
}
