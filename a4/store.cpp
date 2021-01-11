//Andrew Morris
//Section 5
//Due June 26
//store.cpp

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <cctype>

#include "store.h"
#include "book.h"

using namespace std; 

Store::Store()
{   // Set the defauly size and default maximum for the array of Book objects 'inventory' this will change with the grow function.
    current = 0;
    max = 5;
    inventory = new Book[max];
}

void Store::setRegCash(double c)                                 // Function to get and set the starting cash value. 
{
    registerCash = c;
}
const double Store::getRegCash()
{
    return registerCash;
}
void Store::addBook(const char *t, const char *a, char g, double p)
{       // Function to allow the user to add a book to the inventory array of book objects.
        Genre getGenre;

        if (current == max)                                     // Error check to make sure the array grows according to how many books we have entered into inventory.
            growMax();
            // Error check the enum value input and assign it to a Genre object so it can be passed and set accordingly. 
            if ( g == 'F')
            {
                getGenre = FICTION;
            }
            else if ( g == 'M')
            {   
                getGenre = MYSTERY;
            }
            else if ( g == 'S')
            {
                getGenre = SCIFI;
            }
            else if ( g == 'C' )
            {
                getGenre = COMPUTER;
            }
        inventory[current++].Set(t, a, getGenre, p);            // Pass all the new user input data for inventory at each current increment so it can be set. 
}
void Store::makeSale(const char *s)
{   // Function that finds a book in inventory based off of user input and removes it/adds its value to the total cash.
    for (int i = 0; i < current; i++)                                   
    {
        if (strcmp(s,inventory[i].GetTitle()) == 0)             // Compare user input title to inventory, when a title match is found it'll be removed from the list.
        {                                 
            registerCash = registerCash + inventory[i].GetPrice();
            current--;                                          // We adjust the size of the of array by -1 and move all remaining objects in the array forward by 1. 
            for (int j = i; j < current; j++)
            {
                inventory[j] = inventory[j + 1];
            }
        }
        else                                                    // If the title does not match anything in inventory the user will be given an error message and be returned to the menu.
        {
            cout << "Error: No Book Match Found in Inventory." << endl;
            break;
        }
    }
}
void Store::growMax() 
{ // Change the maxmimum size of the array of book objects 'inventory' and allow for us to assign data to ta new slot each time we call addBook().
  max = current + 5;                                            // The max will always be 5 more than the current and wont grow until current = max.
  Book* temp = new Book[max];  
  for(int i = 0; i < current; i++)
    temp[i] = inventory[i];                                     // For each increment of current a new object of Book (Stored within inventory) will be made. 

  delete [] inventory;
  inventory = temp;
}

const void Store::showCash()
{
    cout << fixed << setprecision(2) << "$ " << registerCash << endl;
}
const void Store::showInventory()
{   // Print formatted caloumn headers to the user and display all of the stored books in the inventory.
    showColumnHeaders();
    for (int i =  0; i < current; i++)                          // Print all the "current" filled slots in the inventory array.
    {
        inventory[i].Display();
    }
    cout << "\nTotal Books in Inventory: " << current << endl;  // Print the 
    cout << "Total Register Cash: " << setprecision(2) << fixed << "$ " << getRegCash() << endl;
}
const void Store::searchInv(const char *s)
{   // Function to search the inventory to find user specified book(s) by either the title or the author.
    showColumnHeaders();                                // Print Column Headers.
    for (int i = 0; i < current; i++)
    {   
        if (strcmp(s,inventory[i].GetTitle()) == 0)             // Use strcmp to compare the user input string to the title or author of the books in the inventory
        {                                                       // When there is a match it will display the data in inventory at i for each match.
            
            inventory[i].Display();                             // Return the book based on title
            break;
        }
        else if (strcmp(s,inventory[i].GetAuthor()) == 0)
        {
            inventory[i].Display();                             // Return the Book(s) based off of the input author.
        }  
    }
}
const void Store::searchByGenre(const char s)
{   
    Genre tempGenre;
    int genreCounter = 0;
    double genreTotalPrice;
    // Convert the user input s to a Genre enum value, then compare that value with the values in inventory and return the Book objects that match. 
    if ( s == 'F')
    {
        tempGenre = FICTION;
    }
    else if ( s == 'M')
    {   
        tempGenre = MYSTERY;
    }
    else if ( s == 'S')
    {
        tempGenre = SCIFI;
    }
    else if ( s == 'C' )
    {
        tempGenre = COMPUTER;
    }
    showColumnHeaders();                                       // Print the Column headers for the data.
    for (int i = 0; i < current; i++)
    {
        if (tempGenre == inventory[i].GetGenre())
        {
            inventory[i].Display();
            genreCounter++;                                    // Create a counter for objects that meet the conditions.
            genreTotalPrice += inventory[i].GetPrice();        // Calculate the sum of the prices of the objects in inventory that meet the Genre parameters. 
        }
    }
            cout << "\nThe Total Books in the Genre: " << genreCounter << endl;
            cout << "Total Accumulative Price of Genre: " << "$ " << genreTotalPrice << endl;
}
const void Store::showColumnHeaders()
{
    cout << "\nTitle";
    for (int i = 5; i < 31; i++)                                // Print spaces compared to the length of the headers (by letter) to make neat formatting.
    {
        cout << ' ';
    }
    cout << "Author";
    for (int i = 6; i < 21; i++)
    {
        cout << ' ';
    }
    cout << "Genre";
    for (int i = 5; i < 14; i++)
    {
        cout << ' ';
    }
    cout << "Price" << endl;
}