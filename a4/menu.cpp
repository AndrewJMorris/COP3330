//Andrew Morris 
//Section 5
//Due June 26
//menu.cpp

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

#include "store.h"
#include "book.h"

using namespace std; 

void getCash(Store &defaultStore)
{   // Take user input for register starting cash value and error check it.
    double tempCash;
                                                                     // Hold Temporary cash value. 
    cout << "Hello, Please enter the starting amount of cash in the register: ";
    cin >> tempCash;
    while (tempCash < 0)
    {   
        cout << "Error: Please Input a Positive Number: ";
        cin >> tempCash;
        continue;
    }
    if (tempCash > 0)
        defaultStore.setRegCash(tempCash);
}   
void errorCheckGenre(char g)
{
    while (g != 'F' && g != 'M' && g != 'S' && g != 'C')
    {
        cout << "Error: Invalid Genre Entry, Please Re-Enter: ";
        cin >> g;
        g = toupper(g);
    }
}
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

void getMenuInput(Store &defaultStore)
{   
    // This function will get the user input, and error check it based off of the menu. 
    // Declare variables that will be used in this scope.
    char userInput;
    char title[30];
    char author[20];
    char genre;
    double price;
     

    cout << "Please Choose the Desired Menu Function:\n";
    menu();
    while (userInput != 'X') 
    {
        cin >> userInput;
        userInput = toupper(userInput);

        if (userInput == 'A')
        {   
            cout << "Enter the Boook's Information: " << endl;
            cin.getline(title,30);
            cout << "Book's Title: ";
            cin.getline(title,30);
            cout << "Book's Author: ";
            cin.getline(author,20);
            cout << "Book's Genre (F, M, S, C): ";
            cin >> genre;
            genre = toupper(genre);
            errorCheckGenre(genre);                                  // Call to function to error check the user input for the genre.
            cout << "Book's Price: ";
            cin >> price; 
            while (price < 0)                                        // Error check user input price
            { 
                if (price < 0)
                    cout << "Error: Invalid entry, must input a positive number: ";
                    cin >> price;
                    continue;
            } 
            defaultStore.addBook(title, author, genre, price);
        }  
        else if (userInput == 'F')                                   
        {   // Prompt user to search for a book in the inventory by title or author and search.
            char search[30];

            cout << "\nBook Search\n";
            cin.getline(search,30);
            cout << "Please enter the Title or Author of the Book: ";
            cin.getline(search,30);
            defaultStore.searchInv(search);
        }  
        else if (userInput == 'S')
        {
            char search[30];

            cout << "\nBook Sale\n";
            cin.getline(search,30);
            cout << "Please Enter the Title: ";
            cin.getline(search,30);
            defaultStore.makeSale(search);
        }  
        else if (userInput == 'D')
        {   // Call to display the entire inventory, the number of items in the inventory and the total cash.
            defaultStore.showInventory();
        }  
        else if (userInput == 'G')
        {   // Call to function to search for books in inventory by genre.
            char sGenre;
            cout << "\nGenre Search\n";
            cout << "Please Enter a Genre (F, M, S, C): ";
            cin >> sGenre;
            sGenre = toupper(sGenre);                                // Make it uppcase so we "allow" lower and uppercase input.
            while (sGenre != 'F' && sGenre != 'M' && sGenre != 'S' && sGenre != 'C')     // Error check the user input genre to search for.
            {
                cout << "Error: Invalid Genre Entry, Please Re-Enter: ";
                cin >> sGenre;
                sGenre = toupper(sGenre);
            }                                 
            defaultStore.searchByGenre(sGenre);
        }  
        else if (userInput == 'M')
        {
            menu();
        }
        else if (userInput == 'X')
        {   
            cout << "Nice work! The final cash value for the day is: ";
            defaultStore.showCash();                                 // Print the final register price to the user. 
            break;  
        }
    }

}

int main()
{
    Store defaultStore;                                              // Create the store object for our data.
    getCash(defaultStore);                                           // Get the starting register cash.
    getMenuInput(defaultStore);                                      // Call to interact with menu. 

    return 0;
}