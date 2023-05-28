#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Person
{
private:
    string name;
    string password;
    string login;

public:
    void getinfo()
    {
        cout << "enter name: ";
        cin >> name;
        cout << endl;
        cout << "enter login id: ";
        cin >> login;
        cout << endl;
        cout << "enter password: ";
        cin >> password;
        cout << endl;
    }
    string createTextFile(int a)
    {
        string fileName;
        cout << "Enter the file name: ";
        cin >> fileName;
        fileName += ".txt";
        ofstream headFile("createdstudentlist.txt");
        ofstream takeFile("takenattendancelist.txt");

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
                cout << "Unable to open head.txt." << endl;
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
                cout << "Unable to open head.txt." << endl;
            }

            break;
        default:
            cout << "error in createTextFile";
            break;
        }
        // Append ".txt" extension to the file name
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
class Faculty : public Person
{
private:
    int n = 0;

public:
    void facultycheck(string login, string password)
    {
        // check if login and password are correct
        cout << "checked" << endl;
        facutyframe1();
        cout << "----------Login Successful as Faculty---------" << endl;
    }
    void facutyframe1()
    {
        // display all the options for faculty
        cout << "           1.Add student" << endl;
        cout << "           2.Take attendance" << endl;
        cout << "           3.View attendance" << endl;
        cout<< "            4.Logout"<<endl;
        int choice;
        cout << "enter your choice :  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            takeattendance();
            break;
        case 3:
            veiwattendance();
            break;
        case 4:
            cout << "********** Logout Successful*************";
            first();
            break;
        default:
            cout << "choose from above options";
            facutyframe1();
            break;
        }
        // adding switch case for all the options
    }
    void addstudent()
    {
        // open a file where student data will be appended
        cout << "student added";
         facutyframe1();
    }
    void creaateattendance()
    {
        cout << "Enter the number of students: ";
        cin >> n;
        vector<vector<string>> arr(n + 1, vector<string>(2));
        arr[0][0] = "Rollno.";
        arr[0][1] = "Name";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                string temp;
                switch (j)
                {
                case 0:
                    cout << "Enter roll number: ";
                    cin >> temp;
                    arr[i][j] = temp;
                    break;
                case 1:
                    cout << "Enter name: ";
                    cin >> temp;
                    arr[i][j] = temp;
                    break;
                }
            }
            cout << endl;
        }
        string filename = createTextFile(1);

        ofstream MyFile(filename);

        if (MyFile.is_open())
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    MyFile << setw(12) << left << arr[i][j] << " ";
                }
                MyFile << endl;
            }
            MyFile.close();
            cout << "Data stored in " << filename << endl;
        }
        else
        {
            cout << "Unable to open the file." << endl;
        }
        // create new file where new student  data will be stored
        cout << "attendance created";
    }
    void takeattendance()
    {
        // open file and add column with date append

        ifstream inputFile("text.txt");
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

        cout << "attendance taken"<<endl;
         facutyframe1();
    }
    void veiwattendance()
    {
        // select which file to read
        cout << "1. student list files" << endl;
        cout << "2. Attendance files" << endl;
        int choice;
        cout << "enter your choice : " << endl;
        cin >> choice;
        ifstream headFile("createdstudentlist.txt");
        ifstream listFile("takenattendancelist.txt");
        switch (choice)
        {
        case 1:

            if (headFile.is_open())
            {
                string fileName;
                cout << "Available attendance files:" << endl;
                while (getline(headFile, fileName))
                {
                    cout << fileName << endl;
                }
                headFile.close();
            }
            else
            {
                cout << "Unable to open head.txt." << endl;
                return;
            }
            break;
        case 2:
            if (listFile.is_open())
            {
                string fileName;
                cout << "Available attendance files:" << endl;
                while (getline(listFile, fileName))
                {
                    cout << fileName << endl;
                }
                listFile.close();
            }
            else
            {
                cout << "Unable to open head.txt." << endl;
                return;
            }
            break;
        }
        // Select which file to open
        string selectedFile;
        cout << "Enter the name of the file you want to open: ";
        cin >> selectedFile;
        selectedFile += ".txt";

        // Open and display the selected file
        ifstream attendanceFile(selectedFile);
        if (attendanceFile.is_open())
        {
            string line;
            while (getline(attendanceFile, line))
            {
                cout << line << endl;
            }
            attendanceFile.close();
        }
        else
        {
            cout << "Unable to open the selected file." << endl;
        }
        // read file whch you are already there
        cout << "attendance viewed";
         facutyframe1();
    }
    void changepass()
    {
        // check for old password
        cout << "password changed";
    }
};
class admin : public Faculty
{
public:
 void admincheck(string login, string password)
    {
        // check if login and password are correct
        cout << "checked" << endl;
        adminframe1();
        cout << "----------Login Successful as Faculty---------" << endl;
    }
    void adminframe1()
    {
        
        cout << "       1.Add student" << endl;
        cout << "       2.Create attendance" << endl;
        cout << "       3.Take attendance" << endl;
        cout << "       4.View attendance" << endl;
        cout << "       5.Add faculty" << endl;
        cout << "       6.Access Files" << endl;
        cout << "       7.Logout" << endl;
        int choice;
        cout << "enter your choice :  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Faculty ::addstudent();
            break;
        case 2:
            Faculty ::creaateattendance();
            break;
        case 3:
            Faculty ::takeattendance();
            break;
        case 4:
            Faculty ::veiwattendance();
            break;
        case 5:
            admin ::addfaculty();
            break;
        case 6:
            admin ::access();
            break;
        case 7:
            cout<<"**********logout***********"<<endl;
            Person::first();

        default:
            cout << "choose from above options";
            adminframe1();
            break;
        }
    }

    void addfaculty()
    {
        // creating all attributes of faculty and and adding to file
        cout << "faculty added";
    }
    void deletefaculty()
    {
        cout << "faculty deleted";
    }
    void editfaculty()
    {
        // which one to edit
        cout << "faculty edited";
    }
    void access()

    {
        cout<<"1.Faculty Files"<<endl;
        cout<<"2.student Files"<<endl;
        int choice;
        cout<<"enter your choice : "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            veiwattendance();
            break;
            case 2:
            // open student file
            break;
            default:
            cout<<"choose from above options";
            access();
            break;
        }
        cout << "accessed";
    }
};
class student : public Person
{
public:
    void studentframe1()
    {
        int choice;
        cout << "--------------Login Successful as Student--------- " << endl;
        cout << "                  1.Veiw Attendence";
        cout << "                  2.change password";
        cout << "                  Enter the choice ";
        switch (choice)
        {
        case 1:
            viewattendance();
            break;
        case 2:
            changepass();
            break;
        default:
            cout << "choose from above option";
            studentframe1();
            break;
        }
    }
    
    void checkstudent(string login, string password)
    {
        // check if login and password are correct
        cout << "checked";
    }
    void viewattendance()
    {
        cout << "attendance viewed";
    }
    void changepass()
    {
        cout << "password changed";
    }
};
void Person::first()
{
    Faculty f1;
    student s1;
    admin a1;
    cout << "Login as" << endl;
    cout << "1.Faculty" << endl;
    cout << "2.Student" << endl;
    cout << "3.Admin" << endl;
    int choice;
    cout << "enter your choice :  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "faculty login";

        f1.getinfo();
        f1.facultycheck("iosroew", "wnidnin");

        break;
    case 2:
        cout << "student login";

        s1.getinfo();
        s1.studentframe1();
        // s1.checkstudent(string login,string password);
        break;
    case 3:
        cout << "admin login";

        a1.getinfo();
        a1.adminframe1();
        // a1.facultycheck(login,password);
        break;
    default:
        cout << "choose from above options";
        first();
        break;
    }
}
int main()
{
    Person p1;
    p1.first();
    return 0;
}