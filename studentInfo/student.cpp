// Andrew Morris
// Section 5
// student.cpp
// Due July, 21

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

#include "studentlist.h"

using namespace std;

Biology::Biology(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3, double grade4, double grade5)
{   // Constructor for Biology objects
    firstName = tempfName;
    lastName = templName;
    course = tempCourse;
    labGrade = grade1;
    testAverage = ((grade2*.15)+(grade3*.15)+(grade4*.15));
    bioFinal = grade5;
}
Theatre::Theatre(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3)
{   // Constructor for theatre objects
    lastName = templName;
    firstName = tempfName;
    course = tempCourse;
    participation = grade1;
    midtermGrade = grade2;
    theatreFinal = grade3;
}
ComputerScience::ComputerScience(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3, double grade4, double grade5, double grade6, double grade7, double grade8, double grade9)
{   // Constructor for ComputerScience Objects. 
    lastName = templName;
    firstName = tempfName;
    course = tempCourse;
    programAverage = ((grade1+grade2+grade3+grade4+grade5+grade6)/6);
    testAverage = ((grade7*.2)+(grade8*.2));
    csFinal = grade9;
}
double Student::computeFinalAverage()
{

}
double Biology::computeFinalAverage() 
{   // Compute and return the final grade for the course.
    finalGrade = (labGrade * .3) + (testAverage) + (bioFinal * .3);

    return finalGrade;
}
double Theatre::computeFinalAverage()
{   // Compute and return the final grade for the course.
    finalGrade = (participation * .4) + (midtermGrade * .25) + (theatreFinal * .35);
    
    return finalGrade;
}
double ComputerScience::computeFinalAverage()
{   // Compute and return the final grade for the course.
    finalGrade = (programAverage * .3) + (testAverage) + (csFinal * .3);

    return finalGrade;
}
// Functions to return the student information.
const char* Student::getLastName()
{
    return lastName.c_str();
}
const char* Student::getFirstName()
{
    return firstName.c_str();
}
const char* Student::getCourse()
{   
    return course.c_str();
}
 
const char* Biology::getLastName()
{
    return lastName.c_str();
}
const char* Biology::getFirstName()
{
    return firstName.c_str();
}
const char* Biology::getCourse()
{   
    return course.c_str();
}
 
const char* Theatre::getLastName()
{
    return lastName.c_str();
}
const char* Theatre::getFirstName()
{
    return firstName.c_str();
}
const char* Theatre::getCourse()
{   
    return course.c_str();
}

const char* ComputerScience::getLastName()
{
    return lastName.c_str();
}
const char* ComputerScience::getFirstName()
{
    return firstName.c_str();
}
const char* ComputerScience::getCourse()
{   
    return course.c_str();
}
const double Student::getFinal()
{

}
const double Biology::getFinal()
{
    return bioFinal;
}
const double Theatre::getFinal()
{
    return theatreFinal;
}
const double ComputerScience::getFinal()
{
    return csFinal;
}