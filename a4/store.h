//Andrew Morris
//Section 5
//Due June 26
//store.h

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <cctype>
#include "book.h"

using namespace std; 

class Store
{     
    public:
    // Constructor
    Store();                                                                                      // Blank object constructor for class Store. 
    
    // Setter Functions 
    void addBook(const char *t, const char *a, char g, double p);                                 // Allow for user to add a book to inventory. 
    void makeSale(const char *s);                                                                 // Allow user to input a book title and sell the book.
    void setRegCash(double c);                                                                    // Set the register Cash value with passed double. 
    void growMax();                                                                               // Helper Function to grow the size of the inventory.
                                        
    // Getter functions                                             
    const void showCash();                                                                        // Print the cash to the user 
    const void showInventory();                                                                   // Print entire inventory list.
    const void searchInv(const char *s);                                                          // Allow User to search inventory for specific book based off of a passed search field.
    const void searchByGenre(const char s);                                                       // Search inventory for specific genre and print books in that genre to the user.
    const void showColumnHeaders();                                                               // Show column headers for when book data is returned.
    const double getRegCash();
    
    private:                 
    // Member data for Store
    double registerCash;                                                                          // Double to hold member register cash data. 
    int current;                                                                                  // Comparison integer for max size that will help grow the size of the inventory as we add new books.
    int max;                                                                                      // Growing max value of the array of book objects (inventory).
    Book *inventory;                                                                              // Dynamic array of book objects. 
};
