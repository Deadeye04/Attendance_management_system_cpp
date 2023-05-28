#include<iostream>
#include<vector>
#include<string>
#include<sstream> // Added header for string stream
using namespace std;

class Person {
private:
    string name;
    string password;
    string login;

public:
    void getinfo() {
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
};

class Faculty : public Person {
public:
    void facultycheck(string login, string password) {
        cout << "checked";
        facutyframe1();
    }

    void facutyframe1() {
        cout << "displayed";
        cout << "1. Add student" << endl;
        cout << "2. Create attendance" << endl;
        cout << "3. Take attendance" << endl;
        cout << "4. View attendance" << endl;
        int choice;
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
                creaateattendance();
                break;
            case 3:
                takeattendance();
                break;
            case 4:
                veiwattendance();
                break;
            default:
                cout << "choose from above options";
                facutyframe1();
                break;
        }
    }

    void addstudent() {
        vector<vector<string>> students; // Vector to store student data
        int rollno;
        string name;

        // Get input in the desired format: roll number, name
        cout << "Enter roll number and name (e.g., 1 John): ";
        cin >> rollno >> name;

        // Store the student data in a vector
        students.push_back({to_string(rollno), name});

        cout << "Student added";
    }

    void creaateattendance() {
        cout << "attendance created";
    }

    void takeattendance() {
        cout << "attendance taken";
    }

    void veiwattendance() {
        cout << "attendance viewed";
    }

    void changepass() {
        cout << "password changed";
    }
};

class admin : public Faculty {
public:
    void addfaculty() {
        cout << "faculty added";
    }

    void deletefaculty() {
        cout << "faculty deleted";
    }

    void editfaculty() {
        cout << "faculty edited";
    }

    void access() {
        cout << "accessed";
    }
};

class student : public Person {
public:
    void checkstudent(string login, string password) {
        cout << "checked";
    }

    void viewattendance() {
        cout << "attendance viewed";
    }

    void changepass() {
        cout << "password changed";
    }
};

void first() {
    cout << "Login as" << endl;
    cout << "1. Faculty" << endl;
    cout << "2. Student" << endl;
    cout << "3. Admin" << endl;
    int choice;
    cout << "enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: {
            cout << "faculty login";
            Faculty f1;
            f1.getinfo();
            f1.facultycheck(login, password);
            break;
        }
        case 2: {
            cout << "student login";
            student s1;
            s1.getinfo();
            s1.checkstudent(login, password);
            break;
        }
        case 3: {
            cout << "admin login";
            admin a1;
            a1.getinfo();
            a1.facultycheck(login, password);
            break;
        }
        default: {
            cout << "choose from above options";
            first();
            break;
        }
    }
}

int main() {
    first();
    return 0;
}
