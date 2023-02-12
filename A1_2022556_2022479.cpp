#include <iostream>
#include <limits>
using namespace std;

struct Course
{
    int ID;
    string CourseName;
    string teacher;
    int fee;
    int creditHours;

    int printAll()
    {
        cout << "ID: "<< ID <<
                "Course Name: "
             << CourseName << endl
             << "Teacher: "
             << teacher << "Fee: "
             << fee << endl
             << "Credit Hours: "
             << creditHours << endl;
        return 0;
    }
};

struct CourseList
{
    Course course[5];
    int size;
    CourseList()
    {
        size = 0;
    }

    // void printAll()
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << "Course " << i + 1 << endl;
    //         cout << "\n Course ID: " << course[i].CourseName;
    //     }
    // }
    void printAll()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Student " << i + 1 << endl;
            cout << "-------" << endl;
            course[i].printAll();
        }
    }

    void addCourse(Course c, int index)
    {
        if (index >= 0 && index <= size && size < 5)
        {
            for (int i = size - 1; i >= index; i--)
            {
                course[i + 1] = course[i];
            }
            course[index] = c;
            size++;
        }
    }

    void sort(bool ascending)
    {
        int n = size;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (ascending ? course[j].ID > course[j + 1].ID : course[j].ID < course[j + 1].ID)
                {
                    Course temp = course[j];
                    course[j] = course[j + 1];
                    course[j + 1] = temp;
                }
            }
        }
    }
    void Delteall()
    {
        size = 0;
    }
};

struct Student
{
    int ID;
    string StdName;
    int RollNo;
    int printAll()
    {
        cout << "ID: "
             << ID << endl
             << "Student Name: "
             << StdName << endl
             << "Roll Number: "
             << RollNo << endl;
        return 0;
    }
};

struct StudentList
{
    Student student[5];
    int size;
    StudentList()
    {
        size = 0;
    }

    void printAll()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Student " << i + 1 << endl;
            cout << "-------" << endl;
            student[i].printAll();
        }
    }

    void addStudent(Student c, int index)
    {
        if (index >= 0 && index <= size && size < 5)
        {
            for (int i = size - 1; i >= index; i--)
            {
                student[i + 1] = student[i];
            }
            student[index] = c;
            size++;
        }
    }

    void delStudent(Student c, int index) // Made the delStudent function -- previously it was called addStudent
    {                                     // wasn't making anysense since addstudnet already existed and had diff functions here
        if (index >= 0 && index <= size && size < 5)
        {
            for (int i = size - 1; i >= index; i--)
            {
                student[i - 2] = student[i];
            }
            student[index] = c;
            size--;
        }
    }
};

int main()
{

    int k = 0;
    int option = 0;
    StudentList sList;
    CourseList cList;
    while (option != 10)
    {
        cout << endl
             << "_________________________________________________________________________________________________";
        cout << endl
             << endl
             << "Main Menu";
        cout << endl
             << endl
             << "1. Add New Student\t\t6. Show Particular Courses" << endl
             << "2. Delete Exisiting Student\t7. Show all Courses" << endl
             << "3. Show All Students\t\t8. Sort Courses in Ascending order" << endl
             << "4. Add New Courses\t\t9. Sort Courses in Descending order." << endl
             << "5. Show Particular Courses\t10. Exit";
        cout << endl
             << "__________________________________________________________________________________________________";
        cout << endl
             << "Enter the option: " << endl;
        cin >> option;
        if (option == 1)
        {
            Student s;
            cout << "Enter Student ID: ";
            cin >> s.ID;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the value again." << endl;
                cin >> s.ID;
            }
            cout << "Enter Student Name: ";
            cin >> s.StdName;
            cout << "Enter Student Roll Number: ";
            cin >> s.RollNo;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the value again." << endl;
                cin >> s.RollNo;
            }
            sList.addStudent(s, sList.size); // This will add a new student to the list, hope it works
        }
        else if (option == 2)
        {
            int index;
            cout << "Enter the index of the student to delete: ";
            cin >> index;
            sList.delStudent(sList.student[index - 1], index - 1);
        }
        else if (option == 3)
        {
            sList.printAll(); // Print all students in the student list, the program comes out of the menu, have to fix that
        }                     // want it to stay in the menu and remeber what it was fed so we may print the lists.
        else if (option == 4)
        {
            int a;
            Course c;
            cout << "Enter the ID: " << endl;
            cin >> c.ID;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the value again." << endl;
                cin >> c.ID;
            }
            cout << "Enter Course Name: " << endl;
            cin >> c.CourseName;
            cout << "Enter Teacher Name: ";
            cin >> c.teacher;
            cout << "Enter Course Fee: ";
            cin >> c.fee;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the value again." << endl;
                cin >> c.fee;
            }
            cout << "Enter Credit Hours: ";
            cin >> c.creditHours;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter the value again." << endl;
                cin >> c.creditHours;
            }
            // cList.addCourse(c, cList.size); // CG helped but dont know what's happening
        }
        else if (option == 5)
        {
            int index;
            cout << "Enter the course idex to check it out: ";
            cin >> index;
            cList.course[index - 1].printAll(); // Prints the course details at the specified index
        }
        else if (option == 6)
        {
            string courseName;
            cout << "Enter Course Name: ";
            cin >> courseName; // takes in course names and then prints them out
            for (int i = 0; i < cList.size; i++)
            {
                if (cList.course[i].CourseName == courseName)
                {
                    cList.course[i].printAll(); // Print the details of the course with the specified name
                }
            }
        }
        else if (option == 7)
        {
            cList.printAll(); // Print all courses in the course list
        }
        else if (option == 8)
        {
            cList.sort(true);
            cList.printAll();
        }
        else if (option == 9)
        {
            cList.sort(false);
            cList.printAll();
        }
        // else
        // {
        //     cout<<"Invalid data is entered please enter a valid data"<<endl;
        //     cin.clear();
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // }
        // cout << "\n Enter the optionm again:";
        // cin >> option;
    }
}
