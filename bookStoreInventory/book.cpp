//Andrew Morris, Section 5
//Due June 26
//book.cpp

#include <iostream>
#include <iomanip> 
#include <cstring>
#include <cctype>
#include "store.h"
#include "book.h"

using namespace std; 
 
Book::Book()		                                // default constructor, sets up blank book object
{
}
void Book::Set(const char* t, const char* a, Genre g, double p)
{
   strcpy(title, t); 
   strcpy(author, a);
   price = p;
   type = g;
   switch(g)
   {
      case FICTION  :  type = static_cast<Genre>(char ( g ));
      case MYSTERY  :  type = static_cast<Genre>(char ( g ));
      case SCIFI    :  type = static_cast<Genre>(char ( g ));
      case COMPUTER :  type = static_cast<Genre>(char ( g ));
   }
}
// the Set function should allow incoming data to be received through
//  parameters and loaded into the member data of the object.  (i.e.
//  this function "sets" the state of the object to the data passed in).
//  The parameters t, a, g, and p represent the title, author, genre, 
//  and price of the book, respectively.

const char* Book::GetTitle() const	   	             // returns the title stored in the object
{
   return title;
}
const char* Book::GetAuthor() const                    // returns the author
{
   return author;
}
double Book::GetPrice() const                         // returns the price
{
   return price;
}
Genre Book::GetGenre() const     		               // returns the genre
{  
   return type;
}          
void Book::Display() const  			                  // described below
{
     cout << "Title" << setw(10) << setfill(' ') << "Author" << setw(10) << setfill(' ') << "Genre" << setw(10) << setfill(' ') << "Price\n";
     cout << GetTitle() << setw(10) << setfill(' ') << GetAuthor() << setw(10) << setfill(' ') << GetGenre() << setw(9) << setfill(' ') << fixed << setprecision(2) << "$ " << GetPrice();
}

/* Display() function

The member function Display() should print out a Book object on one line 
as follows, in an organized manner. (Monetary output should be in dollars
and cents notation, to two decimal places):
Title		              Author		  Genre		Price
Examples:
Programming for Dummies       Marvin Dipwart      Computer   $  24.95
Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95

*/ 