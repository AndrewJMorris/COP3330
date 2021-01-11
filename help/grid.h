//#ifndef grid_h
//#define grid_h

#include <iostream>

using namespace std;

class Grid
{
    public:
        //public static class constants, for direction indicators
        static const int NORTH = 0;
        static const int WEST = 1;
        static const int SOUTH = 2;
        static const int EAST = 3;

        //public member functions
        Grid();                                     //build 1x1 grid with move in only square, facing east
        Grid(int r, int c);                         //build grid with r rows, c cols, blocks around edge with random exit and random mover position and direction
        Grid(int r, int c, int mr, int mc, int d);  //build empty grid with r rows, c cols, and mover at row mr, col mc, and facing direction d

        bool Move(int s);               //move forward s spaces, if possible
        void TogglePath();              //toggle whether or not moved math is shown
        void TurnLeft();                //turn the move to the left
        void PutDown();                 //put down an item at the mover's position
        bool PutDown(int r, int c);     //put down an item at (r,c), if possible
        bool PickUp();                  //pick up item at current position
        bool PlaceBlock(int r, int c);  //put a bloack at (r,c), if possible
        void Grow(int gr, int gc);      //grow the grid by gr rows, gc columns
        void Display() const;           //display the grid on the screen

        bool FrontIsClear() const;      //check to see if space in front of mover is clear
        bool RightIsClear() const;      //check to see if space to right of mover is clear
        int GetRow() const;             //return two of the mover
        int GetCol() const;             //return column of the mover
        int GetNumRows() const;         //return number of rows in the grid
        int GetNumCols() const;         //return number of columns in the grid

    private:
        char grid[40][40];
        int rows;
        int columns;
        int moverR;
        int moverC;
        int direction;
        char mover;
        bool path;
};

//#endif
