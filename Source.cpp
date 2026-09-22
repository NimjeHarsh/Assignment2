#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
    string email;
};

int main()
{
    vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    ifstream inputFile("StudentData_Emails.txt");
#else
    ifstream inputFile("StudentData.txt");
#endif

    if (!inputFile.is_open())
    {
        cout << "Error: Could not open input file" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        string firstName;
        string lastName;
        string email;

        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');

#ifdef PRE_RELEASE
        getline(ss, email, ',');
#endif

        STUDENT_DATA student;
        student.firstName = firstName;
        student.lastName = lastName;

#ifdef PRE_RELEASE
        student.email = email;
#endif

        students.push_back(student);
    }

    inputFile.close();

#ifdef _DEBUG
    cout << "DEBUG: Student Information" << endl;
    cout << "--------------------------" << endl;

    for (const STUDENT_DATA& student : students)
    {
        cout << "First Name: " << student.firstName << endl;
        cout << "Last Name: " << student.lastName << endl;
        #ifdef PRE_RELEASE
        cout << "Email: " << student.email << endl;
#endif
        cout << endl;
    }
#endif

    return 0;
}    