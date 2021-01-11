// Andrew Morris
// Section 5
// Due: July 10th
// myint.h

// starter file for MyInt class header

using namespace std;

class MyInt
{
   // Addition and multiplication operator overloads.
   friend MyInt operator+ (const MyInt& x, const MyInt& y);
   friend MyInt operator* (const MyInt& x, const MyInt& y);

   // Comparison operator overloads
   friend bool operator<  (const MyInt& x, const MyInt& y);
   friend bool operator>  (const MyInt& x, const MyInt& y);
   friend bool operator>= (const MyInt& x, const MyInt& y);
   friend bool operator<= (const MyInt& x, const MyInt& y);
   friend bool operator== (const MyInt& x, const MyInt& y);
   friend bool operator!= (const MyInt& x, const MyInt& y);
   
   // Overloads for input and output
   friend ostream& operator << (ostream& s, const MyInt& x);
   friend istream& operator >> (istream& s, const MyInt& x);

public:
   MyInt(int n = 0);		                     // first constructor expects integer, default is 0.
   MyInt(char *n);                           // Second Constructor expects c-style string.
   MyInt(const MyInt& n);                    // Copy Constructor

   ~MyInt();                                 // Destructor

   // Assignment and increments operators
   MyInt& operator= (const MyInt& x);  
   MyInt& operator++ ();                     // Prefix operator
   MyInt  operator++ (int);                  // Postfix 
   
private: 

   int maxSize;
   int currentSize;
   int *numberStorage; 

   void grownumberStorage();                 // Grow the size of the number storage array.
   
   int C2I(char c);                           // Converts c into an integer. 
   char I2C(int x);                           // Converts x into an character.

   // member data (suggested:  use a dynamic array to store the digits)

};