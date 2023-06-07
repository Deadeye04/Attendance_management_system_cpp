#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Person
{
protected:
    string login, password;

public:
    string getlogin();
    string getpassword();
    void encryptPassword()
    {

        for (char &c : password)
        {
            c++;
        }
    }
    string createTextFile(int a)
    {
        string fileName;
        cout << "Enter the file name: ";
        cin >> fileName;
        fileName += ".txt";
        ofstream headFile("createdstudentlist.txt", ios::app);
        ofstream takeFile("takenattendancelist.txt", ios::app);

        switch (a)
        {
        case 1:
            if (headFile.is_open())
            {
                headFile << fileName << endl;
                headFile.close();
            }
            else
            {
                cout << "Unable to open createdstudentlist.txt." << endl;
            }
            break;
        case 2:
            if (takeFile.is_open())
            {
                takeFile << fileName << endl;
                takeFile.close();
            }
            else
            {
                cout << "Unable to open takenattendancelist.txt." << endl;
            }
            break;
        default:
            cout << "Error in createTextFile function." << endl;
            break;
        }

        ofstream outputFile(fileName);
        if (outputFile.is_open())
        {
            cout << "File created successfully: " << fileName << endl;
            outputFile.close();
        }
        else
        {
            cout << "Unable to create the file." << endl;
        }

        return fileName;
    }

    void first();
};
string Person ::getlogin()
{

    cout << "Enter login ID: ";
    cin >> login;
    return login;
}
string Person ::getpassword()
{

    cout << "Enter password: ";
    cout << endl;
    cin >> password;
    cout << endl;
    encryptPassword(); // Encrypt the password before storing

    return password;
}
class Faculty : public Person
{
private:
    int n = 0;

public:
    void facultyCheck(string login, string password)

    {

        for (char &c : password)
        {
            c--;
        }

        if (login == "faculty123" && password == "password123")
        {
            // Password is correct
            cout << "Checked" << endl;
            facultyFrame1();
            cout << "----------Login Successful as Faculty---------" << endl;
        }
        else
        {
            cout << "Incorrect login ID or password" << endl;
            first();
        }
    }
    void facultyFrame1()
    {
        cout << "           1. Add student" << endl;
        cout << "           2. Take attendance" << endl;
        cout << "           3. View attendance" << endl;
        cout << "           4. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            takeAttendance();
            break;
        case 3:
            viewAttendance();
            break;
        case 4:
            cout << "********** Logout Successful *************" << endl;
            first();
            break;
        default:
            cout << "Choose from the above options" << endl;
            facultyFrame1();
            break;
        }
    }

    void addStudent()
    {
        // Open a file where student data will be appended
        cout << "Student added" << endl;
        facultyFrame1();
    }

    void createAttendance()
    {
        cout << "Enter the number of students: ";
        cin >> n;
        vector<vector<string>> arr(n + 1, vector<string>(2));
        arr[0][0] = "Rollno.";
        arr[0][1] = "Name";

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the roll number of student " << i << ": ";
            cin >> arr[i][0];
            cout << "Enter the name of student " << i << ": ";
            cin >> arr[i][1];
        }

        ofstream outFile("attendance.txt");

        if (outFile.is_open())
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    outFile << setw(15) << left << arr[i][j];
                }
                outFile << endl;
            }
            outFile.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
    }

    void takeAttendance()
    {
        ifstream inputFile("LdivfyBtech.txt");
        string filename = createTextFile(2);
        ofstream outputFile(filename, ios::app);

        if (!inputFile || !outputFile)
        {
            cout << "Unable to open the file." << endl;
            exit(1);
        }

        string date;
        cout << "Enter the date (DD/MM/YYYY): ";
        cin >> date;

        // Write the date as the header in the attendance file
        outputFile << "Rollno.     Name         " << date << endl;

        string line;
        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string rollNo, name;
            ss >> rollNo >> name;

            string attendance;
            cout << "Enter attendance (P/A) for " << name << " (Roll No. " << rollNo << "): ";
            cin >> attendance;

            outputFile << setw(12) << left << rollNo << setw(12) << left << name << attendance << endl;
        }

        inputFile.close();
        outputFile.close();

        cout << "Attendance taken and stored in attendance.txt" << endl;

        cout << "attendance taken" << endl;

        facultyFrame1();
    }

    void viewAttendance()
    {
        ifstream inFile("attendance.txt");

        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }

        facultyFrame1();
    }
};

class Student : public Person
{
public:
    void studentFrame1()
    {
        cout << "           1. View attendance" << endl;
        cout << "           2. Change password" << endl;
        cout << "           3. Logout" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewAttendance();
            break;
        case 2:
            changePassword();
            break;
        case 3:
            cout << "********** Logout Successful *************" << endl;
            first();
            break;
        default:
            cout << "Choose from the above options" << endl;
            studentFrame1();
            break;
        }
    }
    void studentCheck(string login, string password)
    {
        // Check if login and password are correct
        // Replace this condition with your actual login ID and password check logic
        if (login == "student123" && password == "password456")
        {
            // Password is correct
            cout << "Checked" << endl;
            studentFrame1();
            cout << "----------Login Successful as Student---------" << endl;
        }
        else
        {
            // Password is incorrect
            cout << "Invalid login ID or password. Please try again." << endl;
            first();
        }
    }
    void viewAttendance()
    {
        ifstream inFile("attendance.txt");

        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }

        studentFrame1();
    }

    void changePassword()
    {
        cout << "Enter the new password: ";
        cin >> password;
        encryptPassword(); // Encrypt the new password before storing
        cout << "Password changed successfully." << endl;
        studentFrame1();
    }
};

class Admin : public Person
{
public:
    void creaateattendance()
    {
        int n;
        cout << "Enter the number of students: ";
        cin >> n;
        vector<vector<string>> arr(n + 1, vector<string>(2));
        arr[0][0] = "Rollno.";
        arr[0][1] = "Name";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    cout << "Enter roll number for student " << i << ": ";
                    cin >> arr[i][j];
                }
                else if (j == 1)
                {
                    cout << "Enter name for student " << i << ": ";
                    cin >> arr[i][j];
                }
            }
        }

        string fileName = createTextFile(2); // Create a text file to store attendance
        ofstream outputFile(fileName);
        if (outputFile.is_open())
        {
            // Write the attendance data to the file
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    outputFile << setw(15) << left << arr[i][j];
                }
                outputFile << endl;
            }
            outputFile.close();
            cout << "Attendance file created successfully: " << fileName << endl;
        }
        else
        {
            cout << "Unable to create the attendance file." << endl;
        }

        adminFrame1();
    }
    void admincheck(string login, string password)
    {
        for (char c : password)
        {
            c--;
        }
        if (login == login && password == password)
        {
            adminFrame1();
        }
        else
        {
            cout << "Invalid login ID or password. Please try again." << endl;
            first();
        }
    }
    void adminFrame1()
    {
        cout << "           1. Add student" << endl;
        cout << "           2. Add faculty" << endl;
        cout << "           3. Logout" << endl;
        cout << "            4.create attendance" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            addFaculty();
            break;
        case 3:
            cout << "********** Logout Successful *************" << endl;
            first();
            break;
        case 4:
            creaateattendance();
            break;
        default:
            cout << "Choose from the above options" << endl;
            adminFrame1();
            break;
        }
    }

    void addStudent()
    {
        // Open a file where student data will be appended
        cout << "Student added" << endl;
        adminFrame1();
    }

    void addFaculty()
    {
        // Open a file where faculty data will be appended
        cout << "Faculty added" << endl;
        adminFrame1();
    }
};
void Person ::first()
{
    Faculty f1;
    Student s1;
    Admin a1;
    cout << "Login as" << endl;
    cout << "1. Faculty" << endl;
    cout << "2. Student" << endl;
    cout << "3. Admin" << endl;
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    string temp1, temp2, temp3, temp4, temp5, temp6;
    switch (choice)
    {
    case 1:
        cout << "Faculty login" << endl;
        temp1 = f1.getlogin();
        temp2 = f1.getpassword();
        f1.facultyCheck(temp1, temp2);
        break;
    case 2:
        cout << "Student login" << endl;
        temp3 = s1.getlogin();
        temp4 = s1.getpassword();
        s1.studentCheck(temp3, temp4);
        s1.studentFrame1();
        break;
    case 3:
        cout << "Admin login" << endl;
        temp5 = a1.getlogin();
        temp6 = a1.getpassword();
        a1.admincheck(temp5, temp6);
        a1.adminFrame1();
        break;
    default:
        cout << "Choose from the above options" << endl;
        first();
        break;
    }
}
int main()
{
    Person p;
    p.first();
    return 0;
}
