#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

struct details
{
    string studname;
    char studid [20];
};
//function prototype
void startmnu(); // main menu of the program/system
void grade_calculation(); //calculate and determine grade
void stud_data(); // get student's data
void display_report(); // display report card
void display_infile();
string studname;
    char studid [20];

string  grade1; //grade1, grade2, grade3, grade4, grade5, grade6;
float marks[6];
float sum_mark, avg_mark, gpa;
struct details student;
int main()
{
    cout << "                        ###################################################" << endl;
    cout << "                        #            Student Report Card System           #" << endl;
	cout << "                        ###################################################"<< endl;

	cout << "                                                                           "<< endl;
    cout << "Welcome to the student report card system, please Login " << endl;
  // loop for the user to enter login details 3 times if incorrect
    string usrname, password;
    int attempt = 0;
    while (attempt<3) {

        // username and password will be preset, example --> username: admin , passwd : admin
        cout << "Username: ";
        cin >> usrname;
        cout << "Password: ";
        cin >> password;

        if (usrname == "admin" && password == "admin") {
            startmnu();
            break;
        }
        else {
            cout << "  " << endl;
            cout << "Login credentials incorrect, please reenter username or password" << endl;
            attempt+=1;
        }
    }

    return 0;
}

void startmnu() {
    // clear earlier screen and display menu
    system("cls");
    int opt;
    cout<<"***********************************************************************"<<endl;
    cout<<"*                                MENU                                 *"<<endl;
    cout<<"***********************************************************************"<<endl;
    cout<< "   "<<endl;
    cout<< "Please choose an option"<<endl;
    cout<< "1.Create record/report card"<<endl;
    cout<< "2.Display report card " <<endl;
    cout<< "3.Exit" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        system("cls");
        stud_data();

        break;
    case 2:
        system("cls");
        grade_calculation();
        display_report();
        //display_infile();
        break;
    case 3:
        break;
        //exit(0);
    }


}
void stud_data()
{
    int bb;
    cout << "Enter the student's name: ";
    cin >> student.studname;
    cout << "Enter the student's ID: " << endl;
    cin.ignore();
    cin.getline(student.studid,20);
   // cin.ignore();
    cout << "(the marks of subjects entered should be out of 100)"<< endl;
    cout << " "<<endl;
    cout << "Please enter the marks of the following subjects (they must be out of 100)"<<endl;
    cout << " "<<endl;
    cout << "Discrete maths: ";
    cin >> marks[0];
    cout << "System analysis and design: ";
    cin >> marks[1];
    cout << "Basics of operating systems: ";
    cin >> marks[2];
    cout << "Programming techniques: ";
    cin >> marks[3];
    cout << "Database concepts: ";
    cin >> marks[4];
    cout << "Statistics: ";
    cin >> marks[5];

    cout << "..." << endl;
    cout << "Enter the number 0 to go back to main menu (then select display report card)" << endl;
    cin >> bb;
    switch (bb)
    {
    case 0:
        system("cls");
        startmnu();
    }

}
void grade_calculation()
{
    sum_mark = marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5];
    avg_mark = sum_mark/6.0;
    //grade
    if (avg_mark>=90 && avg_mark<=100) {
        grade1 = "A";
    }
    else if (avg_mark>=87 && avg_mark<=90) {
        grade1 = "B+";
    }
    else if (avg_mark>=83 && avg_mark<=87) {
        grade1 = "B";
    }
    else if (avg_mark>=80 && avg_mark<=83) {
        grade1 = "B-";
    }
    else if (avg_mark>=76 && avg_mark<=80) {
        grade1 = "C+";
    }
    else if (avg_mark>=73 && avg_mark<=76) {
        grade1 = "C";
    }
    else if (avg_mark>=70 && avg_mark<=73) {
        grade1 = "C-";
    }
    else if (avg_mark>=67 && avg_mark<=70) {
        grade1 = "D+";
    }
     else if (avg_mark>=60 && avg_mark<=67) {
        grade1 = "D";
    }
    else {
        grade1 = "F";
    }
    // GPA
     if (grade1 == "A")
     {
         gpa = 4.0;
     }
     else if (grade1 == "B+")
     {
         gpa = 3.33;
     }
     else if (grade1 == "B")
     {
         gpa = 3.0;
     }
     else if (grade1 == "B-")
     {
         gpa = 2.67;
     }
     else if (grade1 == "C+") {
        gpa = 2.33;
     }
     else if (grade1 == "C") {
        gpa = 2.0;
     }
     else if (grade1 == "C-") {
        gpa = 1.67;
     }
     else if (grade1 == "D+") {
        gpa = 1.33;
     }
     else if (grade1 == "D") {
        gpa = 1.0;
     }
     else {
        gpa = 0.0;
     }
    /*
    sum_mark = mark1 + mark2 + mark3 + mark4 + mark5 + mark6;
    avg_mark = sum_mark/6; */
}
//minimal display test

void display_report()
{
   // system("clear");
    int bb;
    cout << "----------------------------------------------" <<endl;
    cout << "Student's name: " << student.studname; cout << " || ";
    cout << "Student's ID: " << student.studid << endl;
    cout << "******************RESULTS*********************" <<endl;
    cout << "Discrete maths: " << marks[0] << endl;
    cout << "System analysis and design: " << marks[1] << endl;
    cout << "Basics of operating systems: " << marks[2] << endl;
    cout << "Programming Techniques: " << marks[3] << endl;
    cout << "Database concepts: " << marks[4] << endl;
    cout << "Statistics: "<< marks[5] << endl;
    cout << "Final Grade: "<< grade1 << endl;
    cout << "GPA: "<< gpa << endl;

     cout << "..." << endl;
     display_infile();
    cout << "Enter the number 0 to go back to main menu" << endl;
    cin >> bb;
    switch (bb)
    {
    case 0:
        system("cls");
        startmnu();
    }

}

void display_infile()
{
    ofstream rfile;
    rfile.open("report.txt");

    // testing file creation
    if (rfile.is_open()) {

        cout << "Report card file generated"<< endl;

    } else {

    cout << "Oops there is a problem" << endl;

    }
    rfile << "----------------------------------------------" <<endl;
    rfile << "Student's name: " << student.studname; cout << " || ";
    rfile << "Student's ID: " << student.studid << endl;
    rfile << "******************RESULTS*********************" <<endl;
    rfile << "Discrete maths: " << marks[0] << endl;
    rfile << "System analysis and design: " << marks[1] << endl;
    rfile << "Basics of operating systems: " << marks[2] << endl;
    rfile << "Programming Techniques: " << marks[3] << endl;
    rfile << "Database concepts: " << marks[4] << endl;
    rfile << "Statistics: "<< marks[5] << endl;
    rfile << "Final Grade: "<< grade1 << endl;
    rfile << "GPA: "<< gpa << endl;

    rfile.close();
}
