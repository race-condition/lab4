
//-----------------------------------------------------------------------------
// User class: a class to represent the library patrons. Includes the following
// features:
//  -- Get the patron's unique User ID
//  -- Get the patron's last name
//  -- Get the patron's first name
//  -- Get the transaction history
//  -- Update the patron's last name
//  -- Update the patron's first name
//  -- Compare
//
// Assumptions:
// -- No two users have are assigned the same ID
//  -- Assumes User IDs will not change once assigned
//-----------------------------------------------------------------------------

#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "item.h"
#include "history.h"

using namespace std;

class User {

public:
    //default constructor
    User();
   
    // Constructor
    User( int, std::string, std::string);
    
    // Destructor
    ~User( );
    
    // getId
    // Returns the user ID
    int getID( ) const;
    
    // getLastName
    // Return the last name of the user
    std::string getLastName() const;
    
    // getFirstName
    // Return the first name
    std::string getFirstName() const;
    
    // getHistory
    // Returns user's transaction history
    History* getHistory();
    
    // setHistory
    // sets user's transaction history
    void setHistory(History&);
 
    // setLastName
    // Changes the user's last name
    void setLastName(std::string);
    
    // setFirstName
    // Changes the user's first name
    void setFirstName(std::string);
    
    //adds book to borrowed list
    void borrow(Item*);
    
    //deletes book from borrowed list
    void returnuser(Item*);
    
    //checks if book is in borrowed list returns true if it is
    bool checkuser(Item*);
    
    // operator<
    // Overload < operator
    bool operator<(const User&) const;
    
     // operator==
    // Overload == operator
    bool operator==(const User&) const;
  
private:
    // a unique identifier
    int userId;          
    
    // the patron's last name
    std::string lastName;
    
    // the patron's first name
    std::string firstName;          
    
    // the patron's transaction history
     History history;       
     
     //checked out books
     std::vector<Item*> borrowed;
};

#endif
