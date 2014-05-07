//------------------------------------------------------------------
//Fiction class represents fiction books
//includes:
//--Fiction objects contain all information necessary for identification
//--comparison operators that are necessary for BST
//--Parent class of fiction is nonperiodical
//Assumptions:
//--Assumes correct input for book information
//-----------------------------------------------------------------

#include "fiction.h"

using namespace std;

//-------------------------------------------------------------------
//default constructor
Fiction::Fiction()
{
  title = "notitle";
  year = 0;
  format = 'H';
  itemType = 'F';
  checkedOutCopies = 0;
  totalCopies = 5;
}

//-------------------------------------------------------------------
//constructor with parameters for author, title, year
Fiction::Fiction(string inauthor, string intitle, int inyear)
{
   title = intitle;
   author = inauthor;
   year = inyear;
   format = 'H';
   itemType = 'F';
   checkedOutCopies = 0;
   totalCopies = 5;
}

//-------------------------------------------------------------------
//create an item
Item* Fiction::create(ifstream& infile)
{
   string tempauthor;
   string temptitle;
   int tempyear;
   
   Fiction* temp = new Fiction;
   
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
Item* Fiction::createtrans(ifstream& infile)
{
   string tempauthor;
   string temptitle;
   Fiction* temp = new Fiction;
   getline(infile, tempauthor, ',');
   temp->setAuthor(tempauthor);
   infile.get();
   getline(infile, temptitle, ',');
   temp->setTitle(temptitle);
   return temp;
}

//-------------------------------------------------------------------
//return description string
void Fiction::getDescription() const
{
   int available;
   available = (getTotalCopies() - getCheckedOutCopies());
   cout <<  available << " " << author << ", " << title << ", " << year;
}



