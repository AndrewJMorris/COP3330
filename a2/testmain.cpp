#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "temperature.h"

using namespace std;

int main()
{
  Temperature t1;             // initializes to 0 Celsius
  Temperature t2(23.5, 'f');  // initializes to 23.5 Fahrenheit
  Temperature t3(12.6, 'Z');  // invalid scale, initializes to 0 Celsius
  Temperature t4(-300, 'c');  // this is below 0 Kelvin, inits to 0 Celsius
  Temperature t5(15, 'k');    // initializes to 15 Kelvin


    t1.Input();

    cout << "Default Entries:\n";
    t1.Show();
    t2.Show();
    t3.Show();
    t4.Show();
    t5.Show();

    cout << "New Format Entries (t1 = 'P',t2 = 'D',t5 = 'L'):\n";
    t1.SetFormat('D');
    t2.SetFormat('D');
    t5.SetFormat('P');

    t1.Show();
    t2.Show();
    t5.Show();

    cout << "Converted values:\n";
    t1.Convert('F');
    t1.Show();
    t1.Convert('C');
    t1.Show();
    t1.Convert('K');
    t1.Show();

    t2.GetDegrees();
    t2.GetScale();

    t1.Compare(t2);		// returns 1  (since t2 comes first)
    cout << endl;
    t2.Compare(t1);		// returns -1 (calling object is t2, comes first)

   return 0;
}
