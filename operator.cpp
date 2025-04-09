#include <iostream>
using namespace std;

class TimeException {
private:
    string message;
public:
    TimeException(string msg) : message(msg) {}

    string getMessage() {
        return message;
    }
};

class Time {
private:
    int hour, min, sec;

public:
    Time(int a = 0, int b = 0, int c = 0) {
        hour = a;
        min = b;
        sec = c;
    }

    Time operator+(Time t) {
        Time calc;
        calc.sec = sec + t.sec;
        int mm = calc.sec / 60;
        calc.sec = calc.sec % 60;

        calc.min = mm + min + t.min;
        int hh = calc.min / 60;
        calc.min = calc.min % 60;

        calc.hour = hour + t.hour + hh;
        return calc;
    }

    void operator>(Time t) {
        if (hour > t.hour || (hour == t.hour && min > t.min) || (hour == t.hour && min == t.min && sec > t.sec)) {
            cout << "t1 is greater than t2" << endl << "T1 = " << hour << ":" << min << ":" << sec << endl;
        } else {
            cout << "t2 is greater than t1" << endl << "T2 = " << t.hour << ":" << t.min << ":" << t.sec << endl;
        }
    }

    void display() {
        cout << "The total time = " << hour << ":" << min << ":" << sec << endl;
    }

    void validateTime() {
        if (hour > 24) {
            throw TimeException("Error: Invalid hour value Hours must be between 0 and 24.");
        }
        else if (min >= 60) {
            throw TimeException("Error: Invalid minute value Minutes must be between 0 and 59.");
        }
        else if (sec >= 60) {
            throw TimeException("Error: Invalid second value Seconds must be between 0 and 59.");
        }
    }
};

int main() {
    int hour1, min1, sec1, hour2, min2, sec2;

    while (true) {
        cout << "Enter first time (hour min sec): ";
        cin >> hour1 >> min1 >> sec1;
        Time t1(hour1, min1, sec1);
        try {
            t1.validateTime();
            break; 
        }
        catch (TimeException& e) {
            cout << e.getMessage() << endl;
            cout << "Invalid input! Please enter time again." << endl;
        }
    }

    while (true) {
        cout << "Enter second time (hour min sec): ";
        cin >> hour2 >> min2 >> sec2;
        Time t2(hour2, min2, sec2);
        try {
            t2.validateTime();
            break;  
        }
        catch (TimeException& e) {
            cout << e.getMessage() << endl;
            cout << "Invalid input! Please enter time again." << endl;
        }
    }

    Time t1(hour1, min1, sec1);
    Time t2(hour2, min2, sec2);
    Time t3 = t1 + t2;

    t3.display();
    t1 > t2;

    return 0;
}

