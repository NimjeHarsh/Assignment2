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
};

int main()
{
    vector<STUDENT_DATA> students;

    ifstream inputFile("StudentData.txt");

    if (!inputFile.is_open())
    {
        cout << "Error: Could not open StudentData.txt" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        string firstName;
        string lastName;

        stringstream ss(line);

        getline(ss, firstName, ',');
        getline(ss, lastName, ',');

        STUDENT_DATA student;
        student.firstName = firstName;
        student.lastName = lastName;
        students.push_back(student);
    }

    inputFile.close();

    return 0;
}    