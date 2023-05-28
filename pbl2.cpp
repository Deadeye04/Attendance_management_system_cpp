#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    string password;
    string loginID;

public:
    Person(const string& name, const string& password, const string& loginID)
        : name(name), password(password), loginID(loginID) {}

    virtual ~Person() {}

    const string& getName() const {
        return name;
    }

    const string& getPassword() const {
        return password;
    }

    const string& getLoginID() const {
        return loginID;
    }
};

// Derived class: Faculty
class Faculty : public Person {
public:
    Faculty(const string& name, const string& password, const string& loginID)
        : Person(name, password, loginID) {}

    void editName(const string& newName) {
        name = newName;
    }

    void addLectureAttendance() {
        // Add implementation for adding lecture attendance sheet
        cout << "Lecture attendance sheet added." << endl;
    }

    void deleteLectureAttendance() {
        // Add implementation for deleting lecture attendance sheet
        cout << "Lecture attendance sheet deleted." << endl;
    }

    void accessStudentAttendance() {
        // Add implementation for accessing student attendance
        cout << "Accessing student attendance." << endl;
    }

    void createAttendanceSheet() {
        // Add implementation for creating a new attendance sheet
        cout << "New attendance sheet created." << endl;
    }
};

// Derived class: Student
class Student : public Person {
public:
    Student(const string& name, const string& password, const string& loginID)
        : Person(name, password, loginID) {}

    void giveAttendance(const string& dateTime) {
        // Add implementation for giving attendance with date and time
        cout << "Attendance given on " << dateTime << endl;
    }
};

// Derived class: Admin
class Admin : public Faculty {
public:
    Admin(const string& name, const string& password, const string& loginID)
        : Faculty(name, password, loginID) {}

    void addFaculty() {
        // Add implementation for adding a new faculty
        cout << "New faculty added." << endl;
    }
};

// Function to simulate login
Person* login(const vector<Person*>& persons, const string& loginID, const string& password) {
    for (Person* person : persons) {
        if (person->getLoginID() == loginID && person->getPassword() == password) {
            return person;
        }
    }
    return nullptr;
}

int main() {
    vector<Person*> persons;

    // Creating sample persons
    Faculty faculty("John Doe", "faculty123", "faculty001");
    Student student("Jane Smith", "student123", "student001");
    Admin admin("Admin User", "admin123", "admin001");

    // Adding persons to the vector
    persons.push_back(&faculty);
    persons.push_back(&student);
    persons.push_back(&admin);

    cout << "Welcome to the Attendance Management System!" << endl;

    string loginID, password;
    cout << "Login ID: ";
    cin >> loginID;
    cout << "Password: ";
    cin >> password;

    Person* loggedInPerson = login(persons, loginID, password);
    if (loggedInPerson == nullptr) {
        cout << "Invalid login credentials. Exiting..." << endl;
        return 0;
    }

    cout << "login successful!" << endl;
    // Check the type of logged-in person and provide appropriate options
if (dynamic_cast<Admin*>(loggedInPerson)) {
    Admin* admin = dynamic_cast<Admin*>(loggedInPerson);
    cout << "Logged in as Admin." << endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Add Lecture Attendance" << endl;
    cout << "3. Delete Lecture Attendance" << endl;
    cout << "4. Access Student Attendance" << endl;
    cout << "5. Create Attendance Sheet" << endl;
    cout << "6. Add Faculty" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            admin->editName(newName);
            cout << "Name updated successfully!" << endl;
            break;
        }
        case 2:
            admin->addLectureAttendance();
            break;
        case 3:
            admin->deleteLectureAttendance();
            break;
        case 4:
            admin->accessStudentAttendance();
            break;
        case 5:
            admin->createAttendanceSheet();
            break;
        case 6:
            admin->addFaculty();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
} else if (dynamic_cast<Faculty*>(loggedInPerson)) {
    Faculty* faculty = dynamic_cast<Faculty*>(loggedInPerson);
    cout << "Logged in as Faculty." << endl;
    cout << "1. Edit Name" << endl;
    cout << "2. Add Lecture Attendance" << endl;
    cout << "3. Delete Lecture Attendance" << endl;
    cout << "4. Access Student Attendance" << endl;
    cout << "5. Create Attendance Sheet" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            faculty->editName(newName);
            cout << "Name updated successfully!" << endl;
            break;
        }
        case 2:
            faculty->addLectureAttendance();
            break;
        case 3:
            faculty->deleteLectureAttendance();
            break;
        case 4:
            faculty->accessStudentAttendance();
            break;
        case 5:
            faculty->createAttendanceSheet();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
} else if (dynamic_cast<Student*>(loggedInPerson)) {
    Student* student = dynamic_cast<Student*>(loggedInPerson);
    cout << "Logged in as Student." << endl;
    cout << "1. Give Attendance" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            // Get current date and time
            time_t currentTime = time(nullptr);
            string dateTime = ctime(&currentTime);
            student->giveAttendance(dateTime);
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
}

cout << "Thank you for using the Attendance Management System. Goodbye!" << endl;

// Clean up allocated memory
for (Person* person : persons) {
    delete person;
}

return 0;
}
