// Andrew Morris
// Section 5
// student.h
// Due July, 21

using namespace std;

class Student
{   // Base class for the student data.
    public:
    virtual double computeFinalAverage() = 0;   // virtuasl function to computeFinal so we can do so for each derived class as needed. 
    virtual const char* getLastName() = 0;
    virtual const char* getFirstName() = 0;
    virtual const char* getCourse() = 0;
    virtual const double  getFinal() = 0;

    protected:                                  // Protected to allow derived classses access to the data. 
    // Protected member data
    string lastName;
    string firstName;
    string course;
};

class Biology : public Student
{   // Derived of class Student for Biology data.
    public: 
    // Constructor to set student information.
    Biology(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3, double grade4, double grade5);
    
    double computeFinalAverage();      // Calculate, set, and return the final grade. 
    
    const char* getLastName();
    const char* getFirstName();
    const char* getCourse();
    const double  getFinal();

    private:
    // Private member data.
    double labGrade;                   // 30% of final
    double testAverage;                // 15% of final (each) 45% total of final average
    double bioFinal;                   // 25% of final average.
    double finalGrade;                 // Hold the final average (Lab Average * .3 + total test average * .45 + final exam grade * .25)

};

class Theatre : public Student
{   // Derived of class Student for Theatre data.
    public:
    Theatre(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3);
    
    double computeFinalAverage();      // Claculate and return the final grade.
    
    const char* getLastName();
    const char* getFirstName();
    const char* getCourse();
    const double  getFinal();

    private:
    // Private member data.
    double participation;              // 40% of total grade
    double midtermGrade;               // 25% of final
    double theatreFinal;               // 35% of final
    double finalGrade;                 
};

class ComputerScience : public Student
{   // Derived of class Student for ComputerScience Data.
    public:
    ComputerScience(string templName, string tempfName, string tempCourse, double grade1, double grade2, double grade3, double grade4, double grade5, double grade6, double grade7, double grade8, double grade9);
    
    double computeFinalAverage();       // Claculate the return the final average for Computer Science.

    const char* getLastName();
    const char* getFirstName();
    const char* getCourse();
    const double  getFinal();

    private:
    // Private member data.
    double programAverage;             // Store the calculated average of the 6 programs.
    double testAverage;                // Compute and store the average of the two tests.
    double csFinal;                    // Hold the final exam score. 
    double finalGrade;
};
