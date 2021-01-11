// Andrew Morris
// Section 5
// Due: July 10th
// myint.cpp

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cmath>

#include "MyInt.h"

using namespace std;

MyInt::MyInt(int n)                              // Default constructor
{
   int temp = n;                                 // Hold value of n.
   int tempNumStorage;
   int counter = 1;
   int i = 0;

   if (n > 0)
   {
      while (temp > 0)
      {
         temp = temp / 10;                       // n = n / 10 to count # of digits in a number, when n = 0 loop breaks counter = # of digits
         currentSize++;
         if (temp == 0)
            break;
      }

      numberStorage = new int[currentSize];
      temp = n;

      while (temp > 0)
      {
         numberStorage[counter] = temp % 10;     // Assigning values
         temp = temp / 10;
         counter++;
      }
   }
   else if (n < 0)                              // If n is negative the array will represent 0.
   {
      currentSize = 1;
      numberStorage = new int[currentSize];

      numberStorage[currentSize] = 0;
   }
}
MyInt::MyInt(char *n)                           // Second Constructor (Seg faults)
{
   bool checkString = false;
   currentSize = 0;
   numberStorage = new int[currentSize];

   if (checkString == false)
   {
      // Reassign values to MyInt array of integers, "numberStorage"
      delete [] numberStorage;
      currentSize = strlen(n);
      numberStorage = new int[currentSize];

      for (int i = 0; i < currentSize; i++)
      {
         int temp = C2I(n[i]);
         if (temp < 0)
         {                                                   // Convert the passed stirng to an integer.
            currentSize = 1;
            numberStorage[currentSize] = 0;                  // Set to 0 if its not within the parameters.
            break;
         }
         else
         {
            numberStorage[i + 1] = C2I(n[i]);
         }
      }
   }
}
MyInt::MyInt(const MyInt& newNum)               // Copy Constructor
{
   currentSize = newNum.currentSize;
   maxSize = newNum.maxSize;

   numberStorage = new int[maxSize];
   for (int i = 0; i < currentSize; i++)
   {
      numberStorage[i] = newNum.numberStorage[i];
   }

}
MyInt::~MyInt()                                 // Destructor for MyInt objects.
{
   delete [] numberStorage;
}
void MyInt::grownumberStorage()
{
   // Grow the size of the input strings by 5 each time the contents = the "maxSize" so it can infinitely grow.
   maxSize = currentSize + 5;
   int* tempStorage = new int[maxSize];
   for (int i = 0; i < currentSize; i++)
      tempStorage[i] = numberStorage[i];
}
int MyInt::C2I(char c)
// converts character into integer (returns -1 for error)
{
   if (c < '0' || c > '9')	return -1;	         // error
   return (c - '0');				                  // success
}
char MyInt::I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
   if (x < 0 || x > 9)		return '\0';	        // error
   return (static_cast<char>(x) + '0'); 	      // success
}

// operator overload and member function definitions
MyInt& MyInt::operator++ ()
{  // Prefix
   int temp;
   int tempSize = currentSize;

   if (numberStorage[currentSize] < 9)
   {
      temp = numberStorage[currentSize] + 1;
      numberStorage[currentSize] = temp;
   }
   else if (numberStorage[currentSize] == 9)
      while (tempSize > 0)
      {
         temp = numberStorage[tempSize] = 0;
         tempSize--;
         numberStorage[tempSize] = numberStorage[tempSize] + 1;
      }

   return *this;
}
MyInt MyInt::operator++ (int)
{  // Postfix
   MyInt tempStorage = *this;
   int temp;
   int tempSize = currentSize;

   if (numberStorage[currentSize] < 9)
   {
      temp = numberStorage[currentSize] + 1;
      numberStorage[currentSize] = temp;
   }
   else if (numberStorage[currentSize] == 9)
      while (tempSize > 0)
      {
         temp = numberStorage[tempSize] = 0;
         tempSize--;
         numberStorage[tempSize] = numberStorage[tempSize] + 1;
      }

   return tempStorage;
}
MyInt& MyInt::operator= (const MyInt& x)
{  // Assignment operator overload, compare this object to &x, delete the original array and reassign.
   if (this != &x)
   {
      delete [] numberStorage;
      currentSize = x.currentSize;
      maxSize = x.maxSize;

      numberStorage = new int[maxSize];
      for (int i = 0; i < currentSize; i++)
      {
         numberStorage[i+1] = x.numberStorage[i+1];
      }
   }
   return *this;
}
MyInt operator+ (const MyInt& x, const MyInt& y)
{  // Allow for the addition of two MyInt objects.
   MyInt newNum;
   int carryVal = 0;                               // hold the value that needs to be carried.
   int carry = 0;

   if (x.currentSize > y.currentSize)
      newNum.currentSize = x.currentSize;
   else if (y.currentSize > x.currentSize)
      newNum.currentSize = y.currentSize;

   for (int i = 0; i < newNum.currentSize; i++)
   {
      newNum.numberStorage[i] = x.numberStorage[i] + y.numberStorage[i] + carryVal;

   }

   return newNum;
}
MyInt operator* (const MyInt& x, const MyInt& y)
{  // Allow for the multiplication of two MyInt objects.
   MyInt multiSum;                                               // Hold multiplicitive sum data.
   int carry = 0;

   return multiSum;
}
bool operator< (const MyInt& x, const MyInt& y)
{  // When x < y return true.
   if (x.currentSize < y.currentSize)
      return true;
   else
      return false;
}
bool operator> (const MyInt& x, const MyInt& y)
{  // When x > y return true/
   if (x.currentSize > y.currentSize)
      return true;
   else
      return false;
}
bool operator>= (const MyInt& x, const MyInt& y)
{  // When x > y or == y return true.
   if (x.currentSize > y.currentSize)
      return true;
   if (x.numberStorage == y.numberStorage)
      return true;
   else
      return false;
}
bool operator<= (const MyInt& x, const MyInt& y)
{  // When x < y or == y return true.
   if (x.currentSize < y.currentSize)
      return true;
   if (x.numberStorage == y.numberStorage)
      return true;
   else
      return false;
}
bool operator== (const MyInt& x, const MyInt& y)
{  // If x does not equal y return false. if it equals, return true.
   if (x.currentSize != y.currentSize)
      return false;
   else if (x.numberStorage == y.numberStorage)
      return true;
   else
      return false;
}
bool operator!= (const MyInt& x, const MyInt& y)
{  // If x == y return false. If it doesnt equal it, then its true.
   if (x == y)
      return false;
   else
      return true;
}
ostream& operator << (ostream& s, const MyInt& x)
{  // Print the contents of the array of integers to the user.
   for (int i = x.currentSize; i > 0; --i)
   {
      cout << x.numberStorage[i];
   }
   return s;
}
istream& operator >> (istream& s, const MyInt& x)
{ // Take in user input and reads until non digit is hit.
  for(int i = 0; i < x.currentSize; i++)
  {
    if(isspace(x.numberStorage[i]))
      continue;
    if(isalpha(x.numberStorage[i]))
      break;

    s >> x.numberStorage[i];
  }
  return s;
}
