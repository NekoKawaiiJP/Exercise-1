#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {
    int choice;
    do {
        cout << "\n______________________________________________________" << endl;
        cout << "\nTittle: Lab 3" << endl;
        cout << "\nStudent Name: MUHAMMAD SYUHAIRUDEN BIN NAMRAH" << endl;
        cout << "\nStuden ID: 012025021052" << endl;
        cout << "\nProgram: BETE" << endl;
        cout << "\n______________________________________________________" << endl;
        cout << "\nQuestion:\n";
        cout << "1. Volume Of A Sphere" << endl;
        cout << "2. Volume Of A Cylinder" << endl;
        cout << "3. Arithmetic Operation" << endl;
        cout << "4. Exit" << endl;
        cout << "Quention number (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double radius;
                cout << "\nCalculate the volume of a sphere" << endl;
                cout << "-----------------------------------" << endl;
                cout << "\nInput the radius of the sphere: ";
                cin >> radius;
                double volume = (4.0/3.0) * 3.14159 * radius * radius * radius;
                cout << fixed << setprecision(2);
                cout << "The volume of the sphere is: " << volume << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 2: {
                double radius, height;
                cout << "\nInput the radius of the cylinder: ";
                cin >> radius;
                cout << "Input the height of the cylinder: ";
                cin >> height;
                double volume = 3.14159 * radius * radius * height;
                cout << fixed << setprecision(2);
                cout << "The volume of the cylinder is: " << volume << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 3: {
                int num2, num3;
                double num1, num4;
                cout << "\nEnter the 1st number: ";
                cin >> num1; //3.7
                cout << "\nEnter the 2nd number: ";
                cin >> num2; // 5
                cout << "\nEnter the 3rd number: ";
                cin >> num3; //7
                cout << "\nEnter the 4th number: ";
                cin >> num4; //8.0
                cout << fixed << setprecision(2);
                cout << "\nArithmetic Operations Results:" << endl;
                 cout << num2 << " + " << num3 << " = " << (num2 + num3) << endl;
                 cout << num1 << " + " << num4 << " = " << (num1 + num4) << endl;
                 cout << num2 << " + " << num4 << " = " << (num2 + num4) << endl;
                 cout << num2 << " - " << num3 << " = " << (num2 - num3) << endl;
                 cout << num1 << " - " << num4 << " = " << (num1 - num4) << endl;
                 cout << num2 << " - " << num4 << " = " << (num2 - num4) << endl;
                 cout << num2 << " x " << num3 << " = " << (num2 * num3) << endl;
                 cout << num1 << " x " << num4 << " = " << (num1 * num4) << endl;
                 cout << num2 << " x " << num4 << " = " << (num2 * num4) << endl;
                 cout << num2 << " / " << num3 << " = " << (num2 / num3) << endl;
                 cout << num1 << " / " << num4 << " = " << (num1 / num4) << endl;
                 cout << num2 << " / " << num4 << " = " << (num2 / num4) << endl;
                 cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 4:
                cout << "Quit" << endl;
                break;
            default:
                cout << "Number Not Found" << endl; 
        }
    } while (choice != 4);
    return 0;
}