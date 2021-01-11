//--------------------- FRAC.H ---------------------\\

class Fraction
{
  public:
    Fraction();                       //default -- will set up 0/1
    Fraction(int n, int d = 1);       //constructor -- sets to n/d

    void Input();                     // get data from keyboard
    void Show() const;                // print fraction to screen

    void SetValue(int n, int d);      // set the faction to n/def

    // getters
    int GetNumerator() const;
    int GetDenominator() const;

    double Evaluate() const;          // return the decimal equivalent

  private:
    int numerator;                    //can be any integer
    int denominator;                  //must always be non-zero
};

do
{
 prompt (cout)
 do input (cin)
 if (input bad)
      error msg

} while (input bad);
