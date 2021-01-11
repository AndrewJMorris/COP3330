//Andrew Morris, Section 5
//Due June 26
//store.h

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <cctype>
#include "book.h"

using namespace std; 
const static int MAX_INV = 999999999;
class Store
{     
    public:
    // Constructor
    Store();                                        //Blank object contrsutor for class stores. 
    
    // Getter Functions 
    void getRegCash();                              //Prompt and Allow for user input of register cash
    void addBook();                                 //Allow for user to add a book to inventory. 
    void getSearchInfo();
    void searchInv(string s);

    // Setter Functions
    void setRegCash(double c);                      //Error check user input for getRegCash and set the value to registerCash
    
    // Show functions
    const void showCash();                          //Print the cash to the user 

    private:
    double registerCash;                            //Double to hold member register cash data. 
    string search;                                  //String to hold user-input inventory search.
    int invTotal;                                   //The amount of books stored in inventory.
    
    Book inventory[MAX_INV];                        //Hold the book inventory 
};
