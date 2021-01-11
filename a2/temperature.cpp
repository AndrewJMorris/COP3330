// Andrew Morris
// temperature.cpp
// Due: June 5, 2020

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "temperature.h"

using namespace std;

Temperature::Temperature(double getDeg, char setScale) : format('D')            // Constructor with defaults passed through as arguments.
{
  Set(getDeg, setScale);                                                        // Call to boolean Set to error check the passed through degrees and scale.
}

void Temperature::Input()                                                       // Allow user input for temperature cases with no passed arguments.
{
  cout << "Please enter the Temperature (degrees scale): ";
  cin >> degrees >> scale;

  Set(degrees, scale);                                                          // Error check the user-entered degrees and scale.
}

void Temperature::Show()                                                        // Calls to getter functions to return degrees and scale to the user.
{
  if (format == 'D')
  {
    cout << degrees << " " << scale << endl;
  }
  else if (format == 'P')
  {
    ios_base::fmtflags fstate = cout.flags();
    int p = cout.precision();                                                   // Create a default for precision.
    cout << fixed << setprecision(1) << degrees << " " << scale << endl;
    cout.precision(p);
    cout.flags(fstate);                                                         // Reset precision to the default.
  }
  else if (format == 'L')
  {
    string longScale;
    if (scale == 'C')
    {
      longScale = "Celsius";                                                    // Asssign the full scale name to a string depending on char scale, as char cannot hold that many values.
    }
    else if (scale == 'F')
    {
      longScale = "Fahrenheit";
    }
    else if (scale == 'K')
    {
      longScale = "Kelvin";
    }
    cout << degrees << " " << longScale << endl;                                // Return longScale instead of scale to correctly return the 'Long' format.
  }
}

bool Temperature::Set(double deg, char s)
{
  // Error checking for the passed varaibles degrees and scale.
  s = toupper(s);

  if (s == 'C' || s == 'F' || s == 'K')
  {
    if (deg < 0 && s == 'K')                                                    // For each scale we are going to error check to make sure the passed temperatures are above absolute 0.
    {
        degrees = 0;                                                            // When the conditions are not met, degrees and scale will be set to default 0 C
        scale = 'C';                                                            // Set will be false.
        return false;
    }
    else if (deg < -273.15 && s == 'C')                                         // Check for below absolute value of C.
    {
        degrees = 0;
        scale = 'C';
        return false;
    }
    else if (deg < -460 && s == 'F')                                            // Check for below absolute 0 of F.
    {
        degrees = 0;
        scale = 'C';
        return false;
    }
    else
    {
      degrees = deg;
      scale = s;
      return true;
    }
  }
  else
  {
    degrees = 0;
    scale = 'C';
    return false;
  }
}

bool Temperature::SetFormat(char f)
{
  // Assign char to format for Format Conversion.
  if (f == 'D')
    format = 'D';
  else if (f == 'P')
    format = 'P';
  else if (f == 'L')
    format = 'L';
  else
    return false;
  return true;
}


bool Temperature::Convert(char sc)
{
  // sc represents the scale you wish to convert to, for each scale: C, F, K -> Convert accordingly with the proper forumlas
  sc = toupper(sc);                                                             // Default sc to caps for the nice code.

  if (sc == 'C')                                                                // To convert from C to F or K.
  {
    if (scale == 'F')                                                           // Convert F to Celsius.
    {
      int celsConvert;
      celsConvert = ((degrees - 32) * 5/9);
      degrees = celsConvert;
      scale = 'C';
      return true;
    }
    else if (scale == 'K')                                                      // Convert Kelvin to Celsius.
    {
      int celsConvert;
      celsConvert = (degrees - 273.15);
      degrees = celsConvert;
      scale = 'C';
      return true;
    }
    else
    {
      return false;
    }
  }
  if (sc == 'F')                                                                // To convert from C or K to F.
  {
    if (scale == 'C')                                                           // Convert Celsius to F.
    {
      int fConvert;
      fConvert = ((degrees * 5/9) + 32);
      degrees = fConvert;
      scale = 'F';
      return true;
    }
    else if (scale == 'K')                                                      // Kelvin to F.
    {
      int fConvert;
      fConvert = ((degrees - 273.15) * 9/5) + 32;
      degrees = fConvert;
      scale = 'F';
      return true;
    }
    else
    {
      return false;
    }
  }
  if (sc == 'K')                                                                // To convert to K from C or F.
  {
    if (scale == 'C')                                                           // Celsius to Kelvin.
    {
      int kConvert;
      kConvert = (degrees + 273.15);
      degrees = kConvert;
      scale = 'K';
      return true;
    }
    else if (scale == 'F')                                                      // F to Kelvin.
    {
      int fConvert;
      fConvert = (degrees * 5/9) + 273.15;
      degrees = fConvert;
      scale = 'F';
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

double Temperature::GetDegrees() const
{
  // Return degrees to the user.
  return degrees;
}

char Temperature::GetScale() const
{
  // Return the scale to the user.
  return scale;
}

int Temperature::Compare(const Temperature& d)
{
  // Compare the calling object member data to the parameter class member data.
  // To do this, we convert everything to Celsius for a baseline comparison.
  int celsConvert;                                                              // Contains calling object member data after conversion to C.
  int dCelsConvert;                                                             // Contains parameter object member data after conversion to C.

  if(scale == 'C')                                                              // Convert calling member data to Celsius.
  {
    celsConvert = degrees;
  }
  else if(scale == 'F')
  {
    celsConvert = ((degrees - 32) * 5/9);
  }
  else if(scale == 'K')
  {
    celsConvert = (degrees - 273.15);
  }

  if (d.scale == 'C')                                                           // Convert passed member data to Celsius.
  {
    dCelsConvert = d.degrees;
  }
  else if(d.scale == 'F')
  {
    dCelsConvert = ((d.degrees - 32) * 5/9);
  }
  else if(d.scale == 'K')
  {
    dCelsConvert = (d.degrees - 273.15);
  }

  if (celsConvert < dCelsConvert)                                               // Compare the data.
  {
    cout << "-1";
  }
  else if (celsConvert == dCelsConvert)
  {
    cout << "0";
  }
  else if (celsConvert > dCelsConvert)
  {
    cout << "1";
  }
  return 0;
}
