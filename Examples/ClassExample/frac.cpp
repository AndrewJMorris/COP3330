#include "frac.h"

int numerator;                                              //can be any integer
int denominator;                                            //must always be non-zero

Fraction::Fraction()
//default -- will set up 0/1
{
  numerator = 0;
  denominator = 1;
}

Fraction::Fraction(int n, int d = 1)
//constructor -- sets to n/d
{
  if (SetValue (n,d) == false)
      SetValue(0,1);
}

void Fraction::Input()
// read a fraction from the keybaord (std input) -- data
{
  char divSign;

  do
  {
    cin >> numerator >> divSign >> denominator;

    if (denominator == 0)                                   //this is a bad thing
    cout << "Bad fraction. Try again: ";

  } while(denominator == 0);
}

void Fraction::Show() const
// print fraction to screen (std output)
{
  cout << numerator << '/' << denominator;
}

bool SetValue (int n, int d)
// set the faction to n/def
{
  if (d == 0)                                               // return fail message
    return false;
  else
  {
    numerator = n;
    denominator = d;
    return true;                                            // return success message
  }
}

    // getters
int Fraction::GetNumerator() const                          //scope resolution operator (helps resolve the scope of where something comes from "lastname::firstname")
{
  return numerator;
}

int Fraction::GetDenominator() const
{
  return denominator;
}

double Fraction::Evaluate() const
// return the decimal equivalent (possible round-off)
{
  double n = numerator;
  double d = denominator;
  return n/d ;
}
