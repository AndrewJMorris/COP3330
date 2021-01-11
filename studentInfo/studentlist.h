// Andrew Morris
// Section 5
// studentlist.h
// Due July, 21

#include "student.h"

using namespace std;

class StudentList
{   // Student list 
    public:
    // Constructor
    StudentList();                     // Default constructor. Sets empty list. 
    ~StudentList();                    // Destrucstor to clean up dynamically managed data being managed inside a SutdentList object.

    bool ImportFile(const char* filename);
    bool CreateReportFile(const char* filename);
    
    void ShowList() const;             // Print basic list data.

    private: 
    int size;                          // Hold the size of the array.
    Student ** list;                   // Array of pointers containing student data.
};
