/* Willow Darlington
COP3330 - Section 10
Programming Assignment 4

File Contents: trap.cpp takes the users number of rows and
columns and the task at hand is to escape the "prison cell"
with an algorithm that instructs the mover to find its way
to the exit.

All work below was performed by Willow Darlington */

#include <iostream>
using namespace std;

#include "grid.cpp"

int main()
{
    int r, c;
    bool escape = false;

    cout << "Input the number of rows: ";
    cin >> r;
    cout << "Input the number of columns: ";
    cin >> c;

    Grid t(r, c);
    t.TogglePath();
    t.Display();

    while(t.FrontIsClear())
    {
        t.Move();
    }
    t.TurnLeft();

    while(exit == false)
    {
        if(t.RightIsClear())
        {
            t.TurnLeft();
            t.TurnLeft();
            t.TurnLeft();
            t.Move(1);
            exit = true;
        }
        if(!t.FrontIsClear())
            t.TurnLeft();
        else
            t.Move(1);
    }
    t.Move(1);
    cout << endl;
    t.Display();
    cout << "\nWe escaped the prison!\n";

    return 0;
}
