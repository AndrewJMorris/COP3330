#include "grid.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

//build 1x1 grid with move in only square, facing east
Grid::Grid()
{
    grid[1][1];
    direction = EAST;
    moverR = 0;
    moverC = 0;
    path = true;

    //initialize maximum array elements
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 40; j++)
            grid[i][j] = '.';
    }
}

//build grid with r rows, c cols, blocks around edge with random exit and random mover position and direction
Grid::Grid(int r, int c)
{
    //error checking grid size
    if(r < 3 || c < 3)
    {
        rows = 3;
        columns = 3;
    }
    else if(r > 40 || c > 40)
    {
        rows = 40;
        columns = 40;
    }
    else
    {
        rows = r;
        columns = c;
    }

    //initialize maximum array elements
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 40; j++)
            grid[i][j] = '.';
    }

    //printing blocks and fill
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i == 0 || i == rows - 1)
                grid[i][j] = '#';
            else if(j == 0 || j == columns - 1)
                grid[i][j] = '#';
            else
                grid[i][j] = '.';
        }
    }

    //new variables just to help distinguish in this section
    int maxR = rows;
    int maxC = columns;

    srand(time(0));
    path = true;

   //random exit generations
   int exitR = rand() % (rows - 2);
   int exitC = rand() % (columns - 2);
   int direct = rand() % 4;
   int border = rand() % 4;

   exitR = exitR + 1;
   exitC = exitC + 1;

    //switch statement for border random exit generation
    switch(border)
    {
        case NORTH:
            grid[0][exitC] = ' ';           //rows = 0 ] [columns = exitC
            break;
        case WEST:
            grid[exitR][0] = ' ';           //rows = exitR ] [columns = 0
            break;
        case SOUTH:
            grid[rows - 1][exitC] = ' ';    //rows = rows - 1 ] [columns = exitC
            break;
        case EAST:
            grid[exitR][columns - 1] = ' '; //rows = exitR ] [columns = columns -1
            break;
    }

   //placement of mover
    moverR = exitR;
    moverC = exitC;
    direction = direct;

}

//build empty grid with r rows, c cols, and mover at row mr, col mc, and facing direction d
Grid::Grid(int r, int c, int mr, int mc, int d)
{
    //error checking grid size
    if(r < 0 || c < 0)
    {
        rows = 1;
        columns = 1;
    }
    else if(r > 40 || c > 40)
    {
        rows = 40;
        columns = 40;
    }
    else
    {
        rows = r;
        columns = c;
    }

    //initialize maximum array elements
    for(int i = 0; i < 40; i++)
    {
        for(int j = 0; j < 40; j++)
            grid[i][j] = '.';
    }

    path = true;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            grid[i][j] = '.';
    }

    //error checking row mover
    if(mr > 40)
        mr = 40;
    else if(mr < 0)
        mr = 0;

    //error checking row mover
    if(mc > 40)
        mc = 40;
    else if(mc < 0)
        mc = 0;

    moverR = mr;
    moverC = mc;
    direction = d;
    grid[moverR][moverC];
}

//display grid in its current state
void Grid::Display() const
{
   cout << "The Grid:\n";

   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < columns; j++)
      {
         if(i == moverR && j == moverC)
         {
            if(grid[i][j] == '0')
               cout << '@';
            else
               switch(direction)
               {
                  case NORTH:
                     cout << '^';
                     break;
                  case WEST:
                     cout << '<';
                     break;
                  case SOUTH:
                     cout << 'v';
                     break;
                  case EAST:
                     cout << '>';
                     break;
               }
         }
         else if(grid[i][j] == ' ' && path == false)
               cout << '.';
         else
            cout << grid[i][j];

         cout << " ";
      }
      cout << endl;
   }
}

//move forward s spaces, if possible
bool Grid::Move(int s)
{
    int temp;
    bool cell;

    switch(direction)
    {
        case NORTH:
            if(s > 0)
            {
                if(moverR - s >= 0)
                {
                    temp = moverR;
                    for(int i = 0; i < s; i++)
                    {
                        if(FrontIsClear())                      //check if possible to move forward
                        {
                            cell = true;
                            if(grid[moverR][moverC] != '0')
                                grid[moverR][moverC] = ' ';
                            moverR--;
                        }
                        else
                            cell = false;
                    }
                    if(cell == false)
                        moverR = temp;
                    else
                        return true;
                }
            }
            return false;
            break;
        case WEST:
            if(s > 0)
            {
                if(moverC - s >= 0)
                {
                    temp = moverC;
                    for(int i = 0; i < s; i++)
                    {
                        if(FrontIsClear())                      //check if possible to move forward
                        {
                            cell = true;
                            if(grid[moverR][moverC] != '0')
                                grid[moverR][moverC] = ' ';
                            moverC--;
                        }
                        else
                            cell = false;
                    }
                    if(cell == false)
                        moverC = temp;
                    else
                        return true;
                }
            }
            return false;
            break;
        case SOUTH:
            if(s > 0)
            {
                if(moverR + s <= rows)
                {
                    temp = moverR;
                    for(int i = 0; i < s; i++)
                    {
                        if(FrontIsClear())                      //check if possible to move forward
                        {
                            cell = true;
                            if(grid[moverR][moverC] != '0')
                                grid[moverR][moverC] = ' ';
                            moverR++;
                        }
                        else
                            cell = false;
                    }
                    if(cell == false)
                        moverR = temp;
                    else
                        return true;
                }
            }
            return false;
            break;
        case EAST:
            if(s > 0)
            {
                if(moverC + s <= columns)
                {
                    temp = moverC;
                    for(int i = 0; i < s; i++)
                    {
                        if(FrontIsClear())                      //check if possible to move forward
                        {
                            cell = true;
                            if(grid[moverR][moverC] != '0')
                                grid[moverR][moverC] = ' ';
                            moverC++;
                        }
                        else
                            cell = false;
                    }
                    if(cell == false)
                        moverC = temp;
                    else
                        return true;
                }
            }
            return false;
            break;
    }
}

//toggle whether or not moved math is shown
void Grid::TogglePath()
{
    path = !path;
}

//turn the move to the left
void Grid::TurnLeft()
{
    switch(direction)
    {
        case NORTH:
            //turn left from facing North
            direction = WEST;
            break;
        case WEST:
            //turn left from facing West
            direction = SOUTH;
            break;
        case SOUTH:
            //turn left from facing South
            direction = EAST;
            break;
        case EAST:
            //turn left from facing East
            direction = NORTH;
            break;
    }
}

//put down an item at the mover's position
void Grid::PutDown()
{
    grid[moverR][moverC] = '0';
}

//put down an item at (r,c), if possible
bool Grid::PutDown(int r, int c)
{
    if(r < rows && c < columns && grid[r][c] != '#')
    {
        grid[r][c] = '0';
        return true;
    }
    return false;
}

//pick up item at current position
bool Grid::PickUp()
{
    if(grid[moverR][moverC] == '0')
    {
        grid[moverR][moverC] == '0';
        return true;
    }
    else
        return false;
}

//put a block at (r,c), if possible
bool Grid::PlaceBlock(int r, int c)
{
    //creating block
    if(r < rows && c < columns && grid[r][c] != '#')
    {
        grid[r][c] = '#';
        return true;
    }
    return false;
}

//grow the grid by gr rows, gc columns, if possible
void Grid::Grow(int gr, int gc)
{
    if(rows + gr <= 40)         //if growth in rows would result in less than maximum
        rows = gr + rows;
    else
        rows = 40;

    if(columns + gr <= 40)      //if growth in columns would result in less than maximum
        columns = gc + columns;
    else
        columns = 40;
}

//check to see if space in front of mover is clear
bool Grid::FrontIsClear() const
{
    switch(direction)
    {
        case NORTH:
        //if facing north, check to see if front char is block
            if(grid[moverR - 1][moverC] != '#')
                return true;
            else
                return false;
            break;
        case WEST:
        //if facing west, check to see if front char is block
            if(grid[moverR][moverC - 1] != '#')
                return true;
            else
                return false;
            break;
        case SOUTH:
        //if facing south, check to see if front char is block
            if(grid[moverR + 1][moverC] != '#')
                return true;
            else
                return false;
            break;
        case EAST:
        //if facing east, check to see if front char is block
            if(grid[moverR][moverC + 1] != '#')
                return true;
            else
                return false;
    }
}

//check to see if space to right of mover is clear
bool Grid::RightIsClear() const
{
    switch(direction)
    {
        case NORTH:
            //if facing north, check to see if right char is block
            if(grid[moverR][moverC + 1] != '#')
                return true;
            else
                return false;
            break;
        case WEST:
        //if facing west, check to see if right char is block
            if(grid[moverR - 1][moverC] != '#')
                return true;
            else
                return false;
            break;
        case SOUTH:
        //if facing south, check to see if right char is block
            if(grid[moverR][moverC - 1] != '#')
                return true;
            else
                return false;
            break;
        case EAST:
        //if facing east, check to see if right char is block
            if(grid[moverR + 1][moverC] != '#')
                return true;
            else
                return false;
            break;
    }
}

int Grid::GetRow() const
{
    return moverR;          //return row of the mover
}

int Grid::GetCol() const
{
    return moverC;          //return column of the mover
}

int Grid::GetNumRows() const
{
    return rows;            //return number of rows in the grid
}

int Grid::GetNumCols() const
{
    return columns;         //return number of columns in the grid
}
