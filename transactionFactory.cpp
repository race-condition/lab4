//-----------------------------------------------------------------------------
// Transaction Factory class: a factory that produces instances of transactions
// Includes the following features:
//  -- Creates transactions of a specified type
// Assumptions:
//  -- Assumes unique char can be derived from the string passed
//  -- Assumes no more than 26 transactions types are present
//-----------------------------------------------------------------------------

#include "transactionFactory.h"

// constructor
TransactionFactory::TransactionFactory( )
{
	for(int i = 0; i < FACTORY_MAX_SIZE; i++)
	{
	   transactionFactory[i] = NULL;
	}
	//these are the available transaction types
	transactionFactory[hash('C')] = new CheckOutTransaction;
	transactionFactory[hash('D')] = new DisplayTransaction;
	transactionFactory[hash('R')] = new ReturnTransaction;
	transactionFactory[hash('H')] = new HistoryTransaction;
}

// destructor
TransactionFactory::~TransactionFactory( )
{
   for(int i = 0; i < FACTORY_MAX_SIZE; i++)
   {
         if(transactionFactory[i] != NULL)
         {
            delete transactionFactory[i];
         }
  }
}

// creates a Transaction of the desired type
Transaction* TransactionFactory::createIt(ifstream& infile)
{
  char chtemp;
  Transaction* fail = NULL;
  //get the transaction type
  infile >> chtemp;
  if (infile.eof()) return fail;
  //remove next space
  infile.get();
  if (infile.eof()) return fail;
  if(hash(chtemp) < 0 || transactionFactory[hash(chtemp)] == NULL)
  {
   cout << "Error: invalid transaction" << endl;
   string garbage;
   getline(infile,garbage);
   return fail;
  }
  return transactionFactory[hash(chtemp)]->create(infile);
}


//use hash function to get hash index
int TransactionFactory::hash(char chtype) const
{
//performs conversion to valid int for array
   int temp = (int) chtype - 65;
   //checks if itemtype is invalid
   if (temp < 0 || temp > 26)
   {
      //print error message if invalid input given
      cout << "Error: Invalid transaction Hash";
      //this should make the program crash if used to insert into array
      return -1;
   } 
   return temp;
}









