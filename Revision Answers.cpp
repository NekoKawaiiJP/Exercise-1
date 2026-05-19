#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void printHeader() {
    cout << "\n______________________________________________________" << endl;
    cout << "\nTittle: Revision" << endl;
    cout << "\nStudent Name: MUHAMMAD SYUHAIRUDEN BIN NAMRAH" << endl;
    cout << "\nStuden ID: 012025021052" << endl;
    cout << "\nProgram: BETE" << endl;
    cout << "\n______________________________________________________" << endl;
}

int main() {
    int choice;
    do {
        printHeader();
        cout << "\nQuestion:\n";
        cout << "1. Arithmetic Operation" << endl;
        cout << "2. Pass Or Fail Decision" << endl;
        cout << "3. Sum 1-10" << endl;
        cout << "4. Sum And Average" << endl;
        cout << "5. Maximum Value" << endl;
        cout << "6. Pow() function" << endl;
        cout << "7. Quit" << endl;
        cout << "Quention number (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                printHeader();
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
                system("cls");
                printHeader();
                cout << endl;
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
                 cout << endl;
                 cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                printHeader();
                double marks;
                cout << "\nEnter the marks obtained: ";
                cin >> marks;
                if (marks >= 50) {
                    cout << "\nResult: Pass" << endl;
                } else {
                    cout << "\nResult: Fail" << endl;
                }
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 3: {
                system("cls");
                printHeader();
                int sum = 0;
                for (int i = 1; i <= 10; ++i) {
                    sum += i;
                }
                cout << "\nThe sum of numbers from 1 to 10 is: " << sum << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 4: {
                system("cls");
                printHeader();
                int n;
                cout << "\nEnter the number of values: ";
                cin >> n;
                double sum = 0.0, value;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter value " << (i + 1) << ": ";
                    cin >> value;
                    sum += value;
                }
                double average = sum / n;
                cout << fixed << setprecision(2);
                cout << "\nSum: " << sum << endl;
                cout << "Average: " << average << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 5: {
                system("cls");
                printHeader();
                int n;
                cout << "\nEnter the number of values: ";
                cin >> n;
                double maxVal = -1e9, value;
                for (int i = 0; i < n; ++i) {
                    cout << "Enter value " << (i + 1) << ": ";
                    cin >> value;
                    if (value > maxVal) {
                        maxVal = value;
                    }
                }
                cout << fixed << setprecision(2);
                cout << "\nMaximum Value: " << maxVal << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
            case 6: {
                system("cls");
                printHeader();
                double base;
                int exponent;
                cout << "\nEnter the base number: ";
                cin >> base;
                cout << "Enter the exponent (non-negative integer): ";
                cin >> exponent;
                double result = pow(base, exponent);
                cout << fixed << setprecision(2);
                cout << "\nResult: " << base << " raised to the power of " << exponent << " is " << result << endl;
                cout << "Press Enter to return to menu" << endl;
                system("pause >nul");
                system("cls");
                break;
            }
        }
    } while (choice != 7);
    return 0;
}