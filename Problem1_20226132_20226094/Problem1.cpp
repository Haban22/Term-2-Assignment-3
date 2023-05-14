#include <iostream>
#include <string>


using namespace std;


struct Date
{
    int year;
    int month;
    int day;
};

struct Student
{
    int ID;
    string name;
    Date birthDate;
    bool gender;
    double GPA;
};

//Function checks year first then if same year it goes to check Month and then Day
bool isOlder(Student* s1, Student* s2)
{
    if (s1->birthDate.year < s2->birthDate.year)
    {
        return true;
    }
    else if (s1->birthDate.year == s2->birthDate.year)
    {
        if (s1->birthDate.month < s2->birthDate.month)
        {
            return true;
        }
        else if (s1->birthDate.month == s2->birthDate.month)
        {
            if (s1->birthDate.day < s2->birthDate.day)
            {
                return true;
            }
        }
    }
    return false;
}

//Inputs all Students in a for loop
void inputAllStudents(Student* studentsArray, int numberOfStudents)
{

    for(int i = 0; i < numberOfStudents; i++)
    {
        cout << "Input ID of Student " << i+1 << ": ";
        cin >> studentsArray[i].ID;
        cout << "Input Name of Student " << i+1 << ": ";
        cin >> studentsArray[i].name;
        cout << "Input Gender of Student " << i+1 << "(0 M / 1 F): ";
        cin >> studentsArray[i].gender;
        cout << "Input BirthDate of Student " << i+1 << "(MM/DD/YY): ";
        cin >> studentsArray[i].birthDate.month >> studentsArray[i].birthDate.day >> studentsArray[i].birthDate.year;
        cout << "Input GPA of Student " << i+1 << ": ";
        cin >> studentsArray[i].GPA;
    }
}

//Output all Students in the format: ID Name Gender MM/DD/YY GPA 
void outputAllStudents(Student* studentsArray, int numberOfStudents)
{
    for(int i = 0; i < numberOfStudents; i++)
    {
        string genderSTR = "Male";
        if (studentsArray[i].gender == 1)
        {
            genderSTR = "Female";
        }

        cout << studentsArray[i].ID << " " << studentsArray[i].name << " " << genderSTR << " " << studentsArray[i].birthDate.month << "/" << studentsArray[i].birthDate.day << "/" << studentsArray[i].birthDate.year << " " << studentsArray[i].GPA << endl;
    }
}

//Sorts Students by Birthdate using the isOlder function and Swap C++ function
void sortStudentsByBirthDate(Student* s, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(isOlder(&s[j], &s[j+1]))
            {
                swap(s[j],s[j+1]);
            }
        }
    }
}

//Sorts Students by GPA using the swap C++ function
void sortStudentsByGPA(Student* s, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(s[j].GPA > s[j+1].GPA)
            {
                swap(s[j],s[j+1]);
            }
        }
    }
}

//Students
Student* searchStudentsByID(Student* s, int n, int ID)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].ID == ID)
        {
            return &s[i];
        }
    }
    return nullptr;
}

int main()
{
    int numberOfStudents = 0;
    cout << "Input number of students: ";
    cin >> numberOfStudents;    
    
    Student* studentsArray = new Student[numberOfStudents];


    inputAllStudents(studentsArray, numberOfStudents);

    int choice = 0;

    do
    {
        cout << "-------------------------------\n";
        cout << "1- Output all student's data\n";
        cout << "2- Sort students by Birthdate\n";
        cout << "3- Sort students by GPA\n";
        cout << "4- Search student by ID\n";
        cout << "5- Exit program\n";

        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "\nAll Student Data:\n";
                outputAllStudents(studentsArray, numberOfStudents);
                break;
            case 2:
                cout << "Students sorted by Birthdate";
                sortStudentsByBirthDate(studentsArray, numberOfStudents);
                break;
            case 3:
                cout << "Students sorted by GPA";
                sortStudentsByGPA(studentsArray, numberOfStudents);
                break;
            case 4:
            {
                int SearchID;
                cout << "\nEnter ID to search for: ";
                cin >> SearchID;
                
                Student* student = searchStudentsByID(studentsArray, numberOfStudents, SearchID);
                if(student == nullptr)
                {
                    cout << "Student not found" << endl;
                }
                else
                {
                    cout << "Student found: " << student->name <<endl;
                }
                break;
            }
            case 5:
                cout << "\nExiting...";
                break;
            default:
                cout << "Try again" << endl;
        } 
    } while(choice != 5);

    delete[] studentsArray;

    return 0;
}
