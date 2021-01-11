// Created by: Andrew Morris
// Due: May 28, 2020
// diamond.cpp

#include <iostream>
#include <iomanip>
#include <cmath>
#include "diamond.h"

using namespace std;

Diamond::Diamond(int s, char b, char f)                                         // Constructor with arguments passed through for size, border, and fill. The constructor has '#' set as a default for the boder and '*' set as a default for the fill.
{
  if (s < 1)                                                                    // Error checking is statement for size passed through as argument 's'.
  {
    size = 1;                                                                   // Default size to 1 or 39 depending on if the passed value for 's' is < 1 or > 39.
  }
else if (s > 39)
  {
    size = 39;
  }
else
  {
    size = s;
  }

  SetFill(f);                                                                   // Pass argument 'f' (fill) through to SetFill.
  SetBorder(b);                                                                 // Pass argument 'b' (border) through to the SetBorder.
}

double Diamond::Area()                                                          // Return the area as a double.
{
  return (((size * sqrt(3)) / 2) * size);
}

int Diamond::Perimeter()                                                        // Return the perimeter as an integer to the user.
{
  return size * 4;
}

int Diamond::GetSize()                                                          // Return the size as an integer to the user.
{
  return size;
}

void Diamond::Grow()                                                            // Mutator function that error checks the size, if the size is between 1 and 38 it will be increased by 1.
{
  if (size < 39 && size >= 1)
  {
    size++;
  }
}

void Diamond::Shrink()                                                          // Mutator function to shrink the diamond by 1 if the diamond passes the error check determining if size is between 1 and 39.
{
  if (size <= 39 && size > 1)
  {
    --size;
  }
}

void Diamond::SetBorder(char getBorder)                                         // Function that error checks the passed argument and sets the border.
{
  if ((int) getBorder >= 33 && (int) getBorder <= 126)                          // Compare the passed border character to the ASCII index for symbols between 33 and 123.
  {
    border = getBorder;                                                         // Sets border to passed border if it meets the conditions, or resets it to the default if it does not.
  }
  else
  {
    border = '#';
  }
}

void Diamond::SetFill(char getFill)                                             // Performs same function as SetBorder for fill.
{
  if ((int) getFill >= 33 && (int) getFill <= 126)
  {
    fill = getFill;
  }
  else
  {
    fill = '*';
  }
}

void Diamond::Draw()                                                            // Draw uses nested loops to create the shape of the diamond.
{
  // Top half of the diamond.
  int buffer = 1;
  for ( int itr = 0; itr <= size; itr++ )                                       // When itr <= size, and j is >= itr the loop will print spaces until this is no longer true.
  {
    for ( int j = size - 1; j >= itr; j-- )
    {
      cout << " ";
    }

  cout << border;

  if ( itr > 0 )
  {
    for ( int k = 1; k <= buffer - 1; k++)                                      // Iterator that compares to buffer, a variable that will mutate as we progress allowing the default amount of spaces to change.
    {
      cout << " " << fill;                                                      // Nested loop that prints a space and the fill symbol each time the condition is met until it is no longer true.
    }
      buffer += 1;                                                              // When the buffer reaches 1, it will print the border symbol, that is when the conditions for fill are no longer met.
      cout << " " << border;
  }
      cout << endl;
  }

  buffer -= 3;                                                                  // We set the buffer to -3 to flip the triange that was created above.

  // Create the bottom of the diamond
  for (int itr = 0; itr <= size - 1; itr++)                                     // This half is the same as above, simply flipped upside down.
    {
      for (int j = 1; j <= itr + 1; j++)
      {
        cout << " ";
      }

   cout << border;

  // create fill and border for bottom
   for (int k = 1; k <= buffer; k++)
    {
      cout << " " << fill;
    }

   buffer -= 1;

   if (itr != size-1)
    {
      cout << " " << border;
    }
    cout << endl;
  }
}

void Diamond::Summary()                                                         // Prin the data to the screen, call to each get Function.
{
  cout << "Size of diamond's side = " << GetSize() << " units." <<'\n';
  cout << "Perimeter of diamond = " << Perimeter() << " units." << '\n';
  cout << "Area of diamond = " << fixed << setprecision(2) << Area() << " units." << '\n';
  cout << "Diamond looks like:\n";
  Draw();
}
