//Andrew Morris, Section 5
//Due June 26
//menu.cpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

#include "store.h"
#include "book.h"

using namespace std; 

void menu()
{   // Function that presents the menu choices to the user. 
    cout << "\nA:   Add a book to inventory\n"; 
    cout << "F:   Find a book from inventory\n"; 
    cout << "S:   Sell a book\n";
    cout << "D:   Display the inventory list \n"; 
    cout << "G:   Genre summary\n"; 
    cout << "M:   Show this Menu\n"; 
    cout << "X:   Exit the program \n";
}

void getMenuInput(Store &s1)
{
    // This function will get the user input, and error check it based off of the menu. 
    char userInput;
    cout << "Please Choose the Desired Menu Function:\n";

    while (userInput != 'X') 
    {
        menu();
        cin >> userInput;
        userInput = toupper(userInput);

        if (userInput == 'A')
        {
            s1.addBook();
        }  
        else if (userInput == 'F')
        {
            s1.getSearchInfo();
        }  
        else if (userInput == 'S')
        {

        }  
        else if (userInput == 'D')
        {

        }  
        else if (userInput == 'G')
        {

        }  
        else if (userInput == 'M')
        {
            menu();
            continue;
        }
        else if (userInput == 'X')
        {
            s1.showCash();                                       // Print the final register price to the user. 
            break;  
        }
    }

}

int main()
{
    Store s1;
    
    cout << "Hello, Please enter the starting amount of cash in the register: ";
    s1.getRegCash();                                             // Get the starting register cash value.
    getMenuInput(s1);

    return 0;
}