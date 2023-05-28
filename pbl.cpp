#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Person{
    private:
    string name;
    string  password;
    string login;
public:
void getinfo()
{
    cout<<"enter name: ";
    cin>>name;
    cout<<endl;
    cout<<"enter login id: ";
    cin>>login;
    cout<<endl;
    cout<<"enter password: ";
    cin>>password;
    cout<<endl;
}
void first();

    };
class Faculty:public Person{
    private:
    int n=0;
   
public:
void facultycheck(string login,string password){
    //check if login and password are correct
    cout<<"checked"<<endl;
facutyframe1();
}
void facutyframe1(){
    //display all the options for faculty
    cout<<"----------Login Successful as Faculty---------"<<endl;
    cout<<"           1.Add student"<<endl;
    cout<<"           2.Create attendance"<<endl;
    cout<<"           3.Take attendance"<<endl;
    cout<<"           4.View attendance"<<endl;
    int choice;
    cout<<"enter your choice :  ";
    cin>>choice;
    switch(choice){
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
        cout<<"choose from above options";
        facutyframe1();
        break;
    }
    //adding switch case for all the options
}
void addstudent(){
    //open a file where student data will be appended
    cout<<"student added";
}
void creaateattendance(){
     cout << "Enter the number of students: ";
    cin >> n;
     vector<vector<string>> arr(n + 1, vector<string>(2));
    arr[0][0] = "Rollno.";
    arr[0][1] = "Name";

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            string temp;
            switch (j) {
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

    ofstream MyFile("text.txt");
    if (MyFile.is_open()) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 2; j++) {
                MyFile << setw(12) << left << arr[i][j] << " ";
            }
            MyFile << endl;
        }
        MyFile.close();
        cout << "Data stored in text.txt" << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
    //create new file where new student  data will be stored
    cout<<"attendance created";
}
    void takeattendance(){
        // open file and add column with date append
       ifstream inputFile("text.txt");
       ofstream outputFile("attendance.txt", ios::app);

       if (!inputFile || !outputFile) {
           cout << "Unable to open the file." << endl;
           exit(1);    
       }

       string date;
       cout << "Enter the date (DD/MM/YYYY): ";
       cin >> date;
   
       // Write the date as the header in the attendance file
       outputFile << "Rollno.     Name         " << date << endl;

       string line;
       while (getline(inputFile, line)) {
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

   
        cout<<"attendance taken";
       }
    void veiwattendance(){
        //select which file to read

        // read file whch you are already there
        cout<<"attendance viewed";
    }
    void changepass(){
        //check for old password
        cout<<"password changed";
    }
};
class admin : public Faculty{
    public:
    void adminframe1(){
     cout<<"----------Login Succesful-----------"<<endl;
    cout<<"       1.Add student"<<endl;
    cout<<"       2.Create attendance"<<endl;
    cout<<"       3.Take attendance"<<endl;
    cout<<"       4.View attendance"<<endl;
    cout<<"       5.Add faculty"<<endl;
    cout<<"       6.Edit faculty"<<endl;
    int choice;
    cout<<"enter your choice :  ";
    cin>>choice;
    switch(choice){
        case 1:
        Faculty :: addstudent();
        break;
        case 2:
        Faculty :: creaateattendance();
        break;
        case 3:
        Faculty :: takeattendance();
        break;
        case 4:
        Faculty :: veiwattendance();
        break;
        case 5:
        admin :: addfaculty();
        break;
        case 6:
        admin :: access();
        break;
        default:
        cout<<"choose from above options";
        adminframe1();
        break;
    }
    }

    void addfaculty(){
        // creating all attributes of faculty and and adding to file 
        cout<<"faculty added";
    }
    void deletefaculty(){
        cout<<"faculty deleted";
    }
    void editfaculty(){
        // which one to edit 
        cout<<"faculty edited";
    }
    void access(){
        // select file to access
        cout<<"accessed";

    }
};
class student:public Person{
    public:
    void studentframe1(){
        int choice;
        cout<<"--------------Login Successful as Student--------- "<<endl;
        cout<<"                  1.Veiw Attendence";
        cout<<"                  2.change password";
        cout<<"                  Enter the choice ";
        switch(choice){
            case 1:
            viewattendance();
            break;
            case 2: 
            changepass();
            break;
            default:
            cout<<"choose from above option";
            studentframe1();
            break;
        }
    }
    void checkstudent(string login,string password){
        //check if login and password are correct
        cout<<"checked";
        
    }
    void viewattendance(){
        cout<<"attendance viewed";
    }
    void changepass(){
        cout<<"password changed";
    }
};
void Person:: first()
    {
        Faculty f1;
        student s1;
         admin a1;
     cout<<"Login as"<<endl;
    cout<<"1.Faculty"<<endl;
    cout<<"2.Student"<<endl;
    cout<<"3.Admin"<<endl;
    int choice;
    cout<<"enter your choice :  ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"faculty login";
        
        f1.getinfo();
        f1.facultycheck("iosroew","wnidnin");
        
        break;
        case 2:
        cout<<"student login";
        
        s1.getinfo();
        s1.studentframe1();
        // s1.checkstudent(string login,string password);
        break;
        case 3:
        cout<<"admin login";    
        
        a1.getinfo();
        a1.adminframe1();
        // a1.facultycheck(login,password);
        break;
        default:
        cout<<"choose from above options";
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