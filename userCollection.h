//-----------------------------------------------------------------------------
// User Collection class: a collection that stores library patrons. Includes 
// the following features:
//  -- Add users to the library
//  -- Display a list of library patrons
//  -- Retrieve a specific user
// -- Stores users in a Binary search tree
//
// Assumptions:
//  -- Assumes there is not a need to remove a user from the list
//-----------------------------------------------------------------------------

#ifndef USERCOLLECTION_H
#define USERCOLLECTION_H
#include "user.h"
#include <iostream>

class UserCollection {

struct Node {
      User* user;        // pointer to user object
      Node* left;        // left subtree pointer
      Node* right;       // right subtree pointer
      
      Node (User *u, Node *l = NULL, Node *r = NULL) 
      {
         user = u;
         left = l;
         right = r;
      }
    };
 
public:

    // Constructor
    UserCollection();

    // Destructor
    ~UserCollection();
    
    //emptys the tree
    void makeEmpty();
    
    //helper for makeEmpty()
    void emptyhelper(Node* current);

    // insert
    // Inserts a user
    bool insert(User*);

    // display
    // Display the list of user
    void display( ) const;
    
    // retrive
    // Retrives user's object
    bool retrieve(int, User*&) const;
    
private:
    
    Node* root;          // root of the tree
    
    void sideways(Node* current, int level) const;
};

#endif
