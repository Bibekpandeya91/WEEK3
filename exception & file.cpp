#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

class Student {
    int roll;
    float marks, marks1;
    string fname, lname;

public:
    void input() {
        cout << "Please enter roll no: ";
        while (!(cin >> roll)) { 
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid roll number: ";
        }
        
        cout << "Enter your first name: ";
        cin>>fname;
        cout << "Enter your last name: ";
        cin>>lname;
    }

    void m1() {
        while (true) {
            try {
                cout << "Enter marks for C++: ";
                while (!(cin >> marks) || marks < 0 || marks > 100) { 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw string("C++ marks must be between 0 and 100.");
                }
                break;
            }
            catch (string e) {
                cout << "Error: " << e << " Please re-enter." << endl;
            }
        }
    }

    void m2() {
        while (true) {
            try {
                cout << "Enter marks for Database: ";
                while (!(cin >> marks1) || marks1 < 0 || marks1 > 100) { 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw string("Database marks must be between 0 and 100.");
                }
                break;
            }
            catch (string e) {
                cout << "Error: " << e << " Please re-enter." << endl;
            }
        }
    }

    void display() {
        cout << endl;
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << fname << " " << lname << endl;
        cout << "Marks:" << endl;
        cout << "C++: " << marks << endl;
        cout << "Database: " << marks1 << endl;
    }

    void saveToFile() {
        ofstream file("students.txt", ios::app);
        if (!file) { 
            cout << "Error opening file for saving data!" << endl;
            return;
        }
        file << roll << " " << fname << " " << lname << " " << marks << " " << marks1 << endl;
        file.close();
        cout << "Record saved successfully!" << endl;
    }
    void readFromFile() {
    ifstream file("students.txt");
    if (!file) { 
        cout << "Error opening file for reading data!" << endl;
        return;
    }
    
    cout << "Student Records:" << endl;
    while (file >> roll >> fname >> lname >> marks >> marks1) {  
        if (marks < 0 || marks > 100 || marks1 < 0 || marks1 > 100) {
            cout << "Error in data for roll no " << roll << ": Invalid marks." << endl;
            continue;
        }
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << fname << " " << lname << endl;
        cout << "C++ Marks: " << marks << endl;
        cout << "Database Marks: " << marks1 << endl;
        cout << "----------------------" << endl;
    }
    file.close();
}



    void menu() {
        int choice;
        do {
            cout << "1. Add New Student Record" << endl;
            cout << "2. View Student Records" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 3) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter a valid choice (1-3): ";
            }

            if (choice == 1) {
                input();
                m1();
                m2();
                display();
                saveToFile();
            }
            else if (choice == 2) {
                readFromFile();
            }
        } while (choice != 3);
    }
};

int main() {
    Student e; 
    e.menu();
    return 0;
}

