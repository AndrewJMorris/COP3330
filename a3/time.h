// Andrew Morris
// time.h
// Due June 16

#include <iostream>
using namespace std;

class Time
{ 
  // Arithmetic Overloads
  friend Time operator+(const Time& t1, const Time& t2);
  friend Time operator-(const Time& t1, const Time& t2);
  friend Time operator*(const Time& t1, int multiplier);
  
  // Boolean Overloads
  friend bool operator==(const Time& t1, const Time& t2);
  friend bool operator!=(const Time& t1, const Time& t2);
  friend bool operator< (const Time& t1, const Time& t2);
  friend bool operator> (const Time& t1, const Time& t2);
  friend bool operator<=(const Time& t1, const Time& t2);
  friend bool operator>=(const Time& t1, const Time& t2);
  
  // Overloads for extraction and insertion operators.
  friend ostream& operator<<(ostream& t1, const Time& t2);
  friend istream& operator>>(istream& t1, Time& t2);
  
  public:
    // Constructors
    Time();                                                   // Default constructor with no passed arguments.
    Time(int s);                                              // Time constructor with seconds passed a parameter.
    Time(int d, int h, int m, int s);                         // Time constructor with days, hours, minutes, and seconds passed.

    void callcheckTime(int &d, int &h, int &m, int &s);       // call Private error check function

    // Prefix and postfix increment operators for Time.
    Time& operator++();
    Time operator++(int);
    // Prefix and Postfix decrement operators for Time.
    Time& operator--();
    Time operator--(int);

  private:
    // Member data
    int days;
    int hours;
    int minutes;
    int seconds;

    void checkTime(int &d, int &h, int &m, int &s);            // Error check function for friend functions

};
