// Andrew Morris Section: 5
// temperature.h
// due: June 5, 2020

class Temperature
{

  public:
    Temperature(double getDeg = 0, char setScale = 'C');                        // Constructor for temperature with default degrees set to 0 and default scale set to 'C'.

    // Allow user to input the member data for an object and print it to screen.
    void Input();
    void Show();

    // Data checking and setting.
    bool Set(double deg, char s);                                               // Error check and set the degrees and scale.
    bool SetFormat(char f);
    bool Convert(char sc);

    // Accessors
    double GetDegrees() const;
    char GetScale() const;

    // Compare the member data from two class objects.
    int Compare(const Temperature& d);

  private:
    char scale;
    double degrees;
    char format;
};
