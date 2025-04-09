#include<iostream>
#include<fstream>
using namespace std;

class Vehicle {
protected:
    int reg;
public:
    string col;

    int input() {
        cout << "Enter Registration Number Of Your Vehicle: " << endl;
        cin >> reg;
        cout << "Enter Colour Of Your Vehicle: " << endl;
        cin >> col;
        return reg;
    }

    virtual void writeToFile() = 0;
    virtual void display() = 0;
};

class Car : public Vehicle {
protected:
    int seats;
public:
    int addSeats() {
        cout << "Enter No. of seats of your vehicle: " << endl;
        cin >> seats;
        return seats;
    }

    void display() override {
        cout << "Vehicle Type: Car\n";
        cout << "Registration number: " << reg << endl;
        cout << "Colour: " << col << endl;
        cout << "Seats: " << seats << endl;
    }

    void writeToFile() override {
        ofstream outFile;
        outFile.open("vehicle_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Vehicle Type: Car\n";
            outFile << "Registration number: " << reg << endl;
            outFile << "Colour: " << col << endl;
            outFile << "Seats: " << seats << endl;
            outFile << "-----------------------------------\n";
            outFile.close();
        } else {
            cout << "Error opening file." << endl;
        }
    }
};

class Bike : public Vehicle {
private:
    int eng;
public:
    int addEngine() {
        cout << "Enter the engine capacity of your vehicle: " << endl;
        cin >> eng;
        return eng;
    }

    void display() override {
        cout << "Vehicle Type: Bike\n";
        cout << "Registration number: " << reg << endl;
        cout << "Colour: " << col << endl;
        cout << "Engine Capacity: " << eng << "cc" << endl;
    }

    void writeToFile() override {
        ofstream outFile;
        outFile.open("vehicle_details.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Vehicle Type: Bike\n";
            outFile << "Registration number: " << reg << endl;
            outFile << "Colour: " << col << endl;
            outFile << "Engine Capacity: " << eng << "cc" << endl;
            outFile << "-----------------------------------\n";
            outFile.close();
        } else {
            cout << "Error opening file." << endl;
        }
    }
};

void displaySavedDetails() {
    ifstream inFile("vehicle_details.txt");
    string line;
    if (inFile.is_open()) {
        cout << "Saved Vehicle Details:\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}

void menu() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter and Save Vehicle Details (Car or Bike)\n";
        cout << "2. Display Saved Vehicle Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int vehicleType;
            cout << "Choose Vehicle Type:\n";
            cout << "1. Car\n";
            cout << "2. Bike\n";
            cout << "Enter your choice: ";
            cin >> vehicleType;

            if (vehicleType == 1) {
                Car c;
                c.input();      
                c.addSeats();   
                c.display();    
                c.writeToFile();  
                cout << "Details written to file.\n";
            } else if (vehicleType == 2) {
                Bike b;
                b.input();      
                b.addEngine();  
                b.display();    
                b.writeToFile();  
                cout << "Details written to file.\n";
            } else {
                cout << "Invalid option.\n";
            }
        } else if (choice == 2) {
            displaySavedDetails();
        } else if (choice == 3) {
            cout << "Exiting the program.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
}

int main() {
    menu(); 
    return 0;
}

