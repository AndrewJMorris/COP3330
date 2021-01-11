// Andrew Morris
// Section 5
// studentlist.cpp
// Due July, 21

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

#include "studentlist.h"

using namespace std;

StudentList::StudentList()                       
{   // Default constructor. Sets empty list. 
    size = 0;                                           // Set the default size of the array.
    list = new Student * [size];                        // Set the array to the max size. 
}
StudentList::~StudentList()                             // Destructor to clean up dynamically managed data being managed inside a Student List pointer.
{
    for (int i = 0; i < size; i++)
        delete list[i];
    delete [] list;
}
bool StudentList::ImportFile(const char* filename)
{   
    ifstream studentFile(filename);                     // Access fstream allow for read.
    Student ** tempList;

    int tempSize;
    double grade1, grade2, grade3, grade4, grade5, grade6, grade7, grade8, grade9;
    string templName;
    string tempfName;
    string temp;
    string garbage;
    char tempCourse;
    
    if (studentFile.is_open())
    {
        if (size == 0)
        {
            studentFile >> tempSize;
            list = new Student * [tempSize];
        }
        else if (size > 0)
        {   
            int temp = size;
            studentFile >> tempSize;
            temp = temp + tempSize;
            tempList = new Student * [temp];

            for (int i = 0; i < size; i++)
            {
                tempList[i] = list[i];
                delete [] list;
                list = tempList;
            }
        }

        for (int i = 0; i < tempSize; i++)
        {   
            studentFile.ignore();
            getline(studentFile,templName,',');
            getline(studentFile,tempfName);
            studentFile >> tempCourse;

            cout << "\nTempSize: " << tempSize << endl;
            cout << "\nThis is size:" << size << endl;

            if (tempCourse == 'B')
            {   // buffer input to get rid of garbage and set relevant information for the specific class.
                studentFile >> garbage >> grade1 >> grade2 >> grade3 >> grade4 >> grade5;
                temp = "Biology";
                list[size++] = new Biology(templName,tempfName,temp,grade1,grade2, grade3, grade4, grade5);
            }
            else if(tempCourse == 'T')
            {   // set the data into the array of pointers.
                studentFile >> garbage >> grade1 >> grade2 >> grade3;
                temp = "Theatre";
                list[size++] = new Theatre(templName,tempfName,temp,grade1,grade2, grade3);
            }
            else if (tempCourse == 'C')
            {   // Buffer the input to get rid of garbage.
                studentFile >> garbage >> garbage >> grade1 >> grade2 >> grade3 >> grade4 >> grade5 >> grade6 >> grade7 >> grade8 >> grade9;
                temp = "Computer Science";      // Set a value to pass for the course name.
                list[size++] = new ComputerScience(templName,tempfName,temp,grade1,grade2, grade3, grade4, grade5, grade6, grade7, grade8, grade9);
            }
        }
        studentFile.close();
    }
    else 
        cout << "Invalid File: Unable to open.\n";
}
bool StudentList::CreateReportFile(const char* filename)
{
    ofstream studentInfo(filename);                     // Given filename and write an output file for it
    // Counters to count each instasnce of each letter grade.
    int aCounter = 0;                                           
    int bCounter = 0; 
    int cCounter = 0; 
    int dCounter = 0;
    int fCounter = 0;
    int tempSize = size;

    if (studentInfo.is_open())
    {   // write out information to output file
        studentInfo << "Student Grade Summary\n";
        studentInfo << "---------------------\n";
        studentInfo << "BIOLOGY CLASS\n";
        studentInfo << "\nStudent                                   Final Final   Letter\n";
        studentInfo << "Name                                      Exam  Avg     Grade\n";
        studentInfo << "----------------------------------------------------------------------\n";       
        for (int i = 0; i < tempSize; i++)
        {   // Within this for loop we will print the relevant information to the output file in the specified format.
            string tempCourse(list[i]->getCourse());
            if (tempCourse == "Biology")
            {   
                studentInfo << list[i]->getFirstName() << ' ';
                studentInfo << list[i]->getLastName();
                for (int j = strlen(list[i]->getLastName()); j < 36; j++)
                    studentInfo << ' ';
                studentInfo << list[i]->getFinal();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                studentInfo << fixed << setprecision(2) << list[i]->computeFinalAverage();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                if (list[i]->computeFinalAverage() > 89)
                {   
                    studentInfo << 'A' << '\n';
                    aCounter++;
                }
                else if (list[i]->computeFinalAverage() < 90 && list[i]->computeFinalAverage() > 80)
                {   
                    studentInfo << 'B' << '\n';
                    bCounter++;
                }
                else if (list[i]->computeFinalAverage() < 80 && list[i]->computeFinalAverage() > 70)
                {   
                    studentInfo << 'C' << '\n';
                    cCounter++;
                }
                else if (list[i]->computeFinalAverage() < 70 && list[i]->computeFinalAverage() > 60)
                {    
                    studentInfo << 'D' << '\n';
                    dCounter++;
                }
                else if (list[i]->computeFinalAverage() < 60)
                {
                    studentInfo << 'F' << '\n';
                    fCounter++;
                }
            }
        }
            studentInfo << "\nTHEATRE CLASS\n";
            studentInfo << "\nStudent                                   Final Final   Letter\n";
            studentInfo << "Name                                      Exam  Avg     Grade\n";
            studentInfo << "----------------------------------------------------------------------\n";   
        for (int i = 0; i < tempSize; i++)
        {
            string tempCourse(list[i]->getCourse());
            if (tempCourse == "Theatre")
            {   
                studentInfo << list[i]->getFirstName() << ' ';
                studentInfo << list[i]->getLastName();
                for (int j = strlen(list[i]->getLastName()); j < 34; j++)
                    studentInfo << ' ';
                studentInfo << list[i]->getFinal();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                studentInfo << fixed << setprecision(2) << list[i]->computeFinalAverage();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                if (list[i]->computeFinalAverage() > 89)
                {   
                    studentInfo << 'A' << '\n';
                    aCounter++;
                }
                else if (list[i]->computeFinalAverage() < 90 && list[i]->computeFinalAverage() > 80)
                {   
                    studentInfo << 'B' << '\n';
                    bCounter++;
                }
                else if (list[i]->computeFinalAverage() < 80 && list[i]->computeFinalAverage() > 70)
                {   
                    studentInfo << 'C' << '\n';
                    cCounter++;
                }
                else if (list[i]->computeFinalAverage() < 70 && list[i]->computeFinalAverage() > 60)
                {    
                    studentInfo << 'D' << '\n';
                    dCounter++;
                }
                else if (list[i]->computeFinalAverage() < 60)
                {
                    studentInfo << 'F' << '\n';
                    fCounter++;
                }
            } 
        }
            studentInfo << "\nCOMPSCI CLASS\n";
            studentInfo << "\nStudent                                   Final Final   Letter\n";
            studentInfo << "Name                                      Exam  Avg     Grade\n";
            studentInfo << "----------------------------------------------------------------------\n";
        for (int i = 0; i < tempSize; i++)
        {
            string tempCourse(list[i]->getCourse());    
            if (tempCourse == "Computer Science")
            {   
                studentInfo << list[i]->getFirstName() << ' ';
                studentInfo << list[i]->getLastName();
                for (int j = strlen(list[i]->getLastName()); j < 34; j++)
                    studentInfo << ' ';
                studentInfo << list[i]->getFinal();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                studentInfo << fixed << setprecision(2) << list[i]->computeFinalAverage();
                for (int j = 5; j < 10; j++)
                    studentInfo << ' ';
                if (list[i]->computeFinalAverage() > 89)
                {   
                    studentInfo << 'A' << '\n';
                    aCounter++;
                }
                else if (list[i]->computeFinalAverage() < 90 && list[i]->computeFinalAverage() > 80)
                {   
                    studentInfo << 'B' << '\n';
                    bCounter++;
                }
                else if (list[i]->computeFinalAverage() < 80 && list[i]->computeFinalAverage() > 70)
                {   
                    studentInfo << 'C' << '\n';
                    cCounter++;
                }
                else if (list[i]->computeFinalAverage() < 70 && list[i]->computeFinalAverage() > 60)
                {    
                    studentInfo << 'D' << '\n';
                    dCounter++;
                }
                else if (list[i]->computeFinalAverage() < 60)
                {
                    studentInfo << 'F' << '\n';
                    fCounter++;
                }
            }
        }  
        studentInfo << '\n' << '\n' << "OVERALL GRADE DISTRIBUTION\n";
        studentInfo << "A:  " << aCounter << '\n';
        studentInfo << "B:  " << bCounter << '\n'; 
        studentInfo << "C:  " << cCounter << '\n';
        studentInfo << "D:  " << dCounter << '\n'; 
        studentInfo << "F:  " << fCounter << '\n'; 

        studentInfo.close();
    }
}

void StudentList::ShowList() const
{   
    cout << "Last";
    for (int i = 4; i < 21; i++)
    {
        cout << ' ';
    }                 
    cout << "First";
    for (int i = 5; i < 25; i++)
    {
        cout << ' ';
    }   
    cout << "Course\n"; 
    for (int i = 0; i < size; i++)
    {   
        cout << i << '\n';
        cout << size << '\n'; 
        cout << list[i]->getLastName();
        for (int j = strlen(list[i]->getLastName()); j < 20; j++)
        {
            cout << ' ';
        }
        cout << list[i]->getFirstName();
        for (int j = strlen(list[i]->getFirstName()); j < 26; j++)
        {
            cout << ' ';
        }
        cout << list[i]->getCourse();
        cout << endl;
    }
}