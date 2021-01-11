//Andrew Morris, Section 5
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
{
}

void Store::setRegCash(double c)                                // Standard input error checking, verify the input is positive and will loop until it is correct. 
{                                                               // If c is positive it will set register cash for objects of type store. 
    if (c < 0)
    {
        while (c < 0)
        {
            cout << "Invalid Input: Please input a positive value: ";
            cin >> c;
            if (c > 0)
            {
                registerCash = c;                               // Assign value stored in c to RegisterCash if it meets the conditions.
                break;
            }
        }
    }
    else 
    {
        registerCash = c;
    }
}

void Store::getRegCash()                                        // Function to get and set the starting cash value. 
{
    double cash;
    cin >> cash;

    setRegCash(cash);                                           // Call for error checking.
}

const void Store::showCash()
{
    cout << "Nice work! The final cash value for the day is: ";
    cout << fixed << setprecision(2) << "$ " << registerCash << endl;
}

void Store::addBook()
{
    Genre type;
    char title[30];
    char author[20];
    char genre;
    int genreTemp;
    double price;

    for ( int i = -1; i < MAX_INV; i++)
    {   
        i++;
        cout << "Please Enter the Book's Title: ";
        cin >> title;
        cout << "Please Enter the Book's Author: ";
        cin >> author;
        cout << "Please Enter the Book's Genre (F, M, S, C): ";
        cin >> genre;
        while (genre != 'F' || genre != 'M' || genre != 'S' || genre != 'C')
        {
            genre = toupper(genre);
            if ( genre == 'F')
            {
                genreTemp = genre;
                type = static_cast<Genre>( genreTemp );
                break;
            }
            else if ( genre == 'M')
            {   
                genreTemp = genre;
                type = static_cast<Genre>( genreTemp );
                break;
            }
            else if ( genre == 'S')
            {
                genreTemp = genre;
                type = static_cast<Genre>( genreTemp );
                break;
            }
            else if ( genre == 'C' )
            {
                genreTemp = genre;
                type = static_cast<Genre>( genreTemp );
                break;
            }
            else 
            {
                cout << "Error: Invalid Genre Entry, Please Re-Enter: ";
                cin >> genre;
                continue;
            }
        }    
        cout << "Please Enter the Book's Price: ";
        cin >> price; 
        //Error check the userinput price. When price is negative it will prompt for re-entry and loop until proper input is given. 
        while (price < 0)
        {
            if (price < 0)
                cout << "Error: Invalid entry, must input a positive number: ";
                cin >> price;
                continue;
        } 
        inventory[i].Set(title, author, type, price);
        break;
    }
}

void Store::getSearchInfo()
{
    cout << "Book Search\n";
    cout << "Please enter the Title or Author of the Book: ";
    cin >> search;
    searchInv(search);
}

void Store::searchInv(string s)
{   
    for (int i = 0; i < MAX_INV; i++)
    {    
        cout << endl;
        inventory[i].Display();
    }
}