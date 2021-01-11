// Created by: Andrew Morris
// Due: May 28, 2020
// diamond.h

class Diamond
{

  public:
    // constructor
    Diamond(int s, char b = '#', char f = '*');                                 // constructor for Diamond with 3 arguments passed through

    // setter functions
    void SetBorder(char getBorder);                                             // Prototype passing getBorder which will hold a given value
    void SetFill(char getFill);                                                 // Prototype for function to allow the passthrough of a border character

    void Draw();                                                                // void function to draw the Diamond

    // mutators
    void Grow();
    void Shrink();

    // getter functions                                                         // prototype functions to return data
    int GetSize();
    int Perimeter();
    double Area();

    void Summary();

  private:
    char fill;                                                                  // member data for functions
    char border;
    int size;
};
