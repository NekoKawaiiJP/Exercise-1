#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n______________________________________________________" << endl;
        cout << "\nTittle: Lab 2" << endl;
        cout << "\nStudent Name: X" << endl;
        cout << "\nStuden ID: X" << endl;
        cout << "\nProgram: X" << endl;
        cout << "\n______________________________________________________" << endl;
        cout << "\nQuestion:\n";
        cout << "a. Calculation" << endl;
        cout << "b. lengths in inches" << endl;
        cout << "c. Exit" << endl;
        cout << "Quention number (1-2): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num1, num2;
                cout << "\nEnter the 1st number: ";
                cin >> num1;
                cout << "Enter the 2nd number: ";
                cin >> num2;

                 cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                 cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                 cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                 cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
                 cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;
                break;
            }
            case 2: {
                double inches;
                cout << "\nEnter length in inches: ";
                cin >> inches;
                double cm = inches * 2.54;
                cout << inches << " inches = " << cm << " centimeters" << endl;
                break;
            }
            case 3:
                cout << "Quit" << endl;
                break;
            default:
                cout << "Number Not Found" << endl;
        }
        system("pause");
    } while (choice != 3);
    return 0;
}
