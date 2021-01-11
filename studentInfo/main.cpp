// Andrew Morris
// Section 5
// main.cpp (For StudentList Program)
// Due July, 21

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

#include "studentlist.h"

using namespace std;

void displayMenu()
{
    cout << "          *** Student List menu ***\n";
    cout << "I       Import students from a file\n";
    cout << "S       Show student list (brief)\n";
    cout << "E       Export a grade report (to file)\n";
    cout << "M       Show this Menu\n";
    cout << "Q       Quit Program\n";
}
void getUserInput(StudentList &student)
{
    char userInput;
    char temp;
    displayMenu();

    while (userInput != 'Q')
    {
        cin >> userInput;
        userInput = toupper(userInput);

        if (userInput == 'I')
        {
            char filename[30];
            cout << "Enter Filename: ";
            cin >> filename;
            student.ImportFile(filename);
        }
        else if (userInput == 'S')
        {
            student.ShowList();
        }
        else if (userInput == 'E')
        {
            char filename[30];
            cout << "Enter Filename: ";
            cin >> filename;
            student.CreateReportFile(filename);
        }
        else if (userInput == 'M')
        {
            displayMenu();
        }
        else if (userInput == 'Q') 
        {
            cout << "Goodbye!\n";
            break;
        }
    }
}
int main()
{
    StudentList student;

    getUserInput(student);
}