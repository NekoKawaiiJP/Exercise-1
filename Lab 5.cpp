#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <limits>
using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE) {
        SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int choice;
    do {
        cout << "\n______________________________________________________" << endl;
        cout << "\nTitle: Lab 5" << endl;
        cout << "\nStudent Name: 山本 里奈" << endl;
        cout << "\nStudent ID: X" << endl;
        cout << "\nProgram: X" << endl;
        cout << "\n______________________________________________________" << endl;
        cout << "\nQuestion:\n";
        cout << "1. Student Score" << endl;
        cout << "2. ATM Machine" << endl;
        cout << "3. Exit" << endl;
        cout << "Selection option (1-3): ";

        while (!(cin >> choice) || choice < 1 || choice > 3) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Error... Please enter a valid number (1-3): ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
                system("cls");
                cout << "Student Score" << endl;
                int score;
                cout << "Enter student score (0-100): ";
                while (!(cin >> score) || score < 0 || score > 100) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "Error. Please enter student score between 0 and 100: ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            char grade = 'F';
            if (score >= 101) grade = 'X';
            else if (score >= 90) grade = 'A';
            else if (score >= 80) grade = 'B';
            else if (score >= 70) grade = 'C';
            else if (score >= 60) grade = 'D';
            else grade = 'F';
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            cout << "\n______________________________________________________\n" << endl;
            cout << "The grade is: ";
            switch (grade) {
                case 'A':
                SetConsoleTextAttribute(h, 10);
                break;
                case 'B':
                SetConsoleTextAttribute(h, 11); 
                break;
                case 'C':
                SetConsoleTextAttribute(h, 14); 
                break;
                case 'D':
                SetConsoleTextAttribute(h, 13);
                break;
                case 'F':
                SetConsoleTextAttribute(h, 12); 
                break;
            }
            cout << grade << endl;
            SetConsoleTextAttribute(h, 7);
            cout << "\n______________________________________________________\n" << endl;
            cout << "Press Enter to continue..." << endl;
            system("pause >nul");
            system("cls");
            break;
            }
            case 2: {
                system("cls");
                cout << "ATM Machine" << endl;
                int pin = 1052, enteredPin, attempts = 0;
                double balance = 100000.0;
                bool authenticated = false;
                while (attempts < 3) {
                    cout << "Enter 4-digit PIN: ";
                    cin >> enteredPin;
                    if (enteredPin == pin) {
                        authenticated = true;
                        system("cls");
                        break;
                    } else {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        cout << "Invalid PIN. Try again." << endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        attempts++;
                        cout << endl;
                        cout << "Press any to continue..." << endl;
                        system("pause >nul");
                        system("cls");
                    }
                }
                if (!authenticated) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    cout << "Error. Too many attempts. Exiting..." << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    cout << endl;
                    cout << "Press any to continue..." << endl;
                    system("pause >nul");
                    system("cls");
                } else {
                    int option;
                    do {
                        cout << "\nATM:\n";
                        cout << "1. Check Balance\n";
                        cout << "2. Withdraw Money\n";
                        cout << "3. Change PIN\n";
                        cout << "4. Deposit\n";
                        cout << "5. Exit\n";
                        cout << "Select option (1-5): ";
                        while (!(cin >> option) || option < 1 || option > 5) {
                        cout << "Error. Please enter a valid option (1-5): ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                        switch (option) {
                            case 1: {
                                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                cout << "\n                                 \n";
                                cout << "Current balance: ¥";
                                SetConsoleTextAttribute(h, 10);
                                cout << fixed << setprecision(2) << balance;
                                SetConsoleTextAttribute(h, 7);
                                cout << "円" << endl;
                                cout << endl << "\n                         \n";
                                cout << "Press Enter to continue..." << endl;
                                system("pause >nul");
                                system("cls");
                                break;
                            }
                            case 2: {
                                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                double withdraw;
                                cout << endl;
                                cout << "Enter amount to withdraw: ¥";
                                cin >> withdraw;
                                system("cls");
                                if (withdraw <= 0) {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "Invalid amount." << endl;
                                    SetConsoleTextAttribute(h, 7);
                                } else if (withdraw > balance) {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "Insufficient balance." << endl;
                                    SetConsoleTextAttribute(h, 7);
                                } else {
                                    balance -= withdraw;
                                    cout << endl;
                                    cout << "Withdrawal successful. Remaining balance: ¥";
                                    SetConsoleTextAttribute(h, 2);
                                    cout << fixed << setprecision(2) << balance;
                                    SetConsoleTextAttribute(h, 7);
                                    cout << "円" << endl;
                                    cout << endl;
                                }
                                cout << "Press Enter to continue..." << endl;
                                system("pause >nul");
                                system("cls");
                                break;
                            }
                            case 3: {
                                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                int newPin;
                                cout << "Enter new 4-digit PIN: ";
                                cin >> newPin;
                                if (newPin >= 1000 && newPin <= 9999) {
                                    pin = newPin;
                                    SetConsoleTextAttribute(h, 6);
                                    cout << "PIN successfully changed." << endl;
                                    SetConsoleTextAttribute(h, 7);
                                } else {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "Invalid PIN format." << endl;
                                    SetConsoleTextAttribute(h, 7);
                                }
                                cout << "Press Enter to continue..." << endl;
                                system("pause >nul");
                                system("cls");
                                break;
                            }
                            case 4: {
                                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                                double deposit;
                                cout << endl;
                                cout << "Enter amount to deposit: ¥";
                                cin >> deposit;
                                system("cls");
                                if (deposit <= 0) {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "Invalid deposit amount." << endl;
                                    SetConsoleTextAttribute(h, 7);
                                } else {
                                    balance += deposit;
                                    cout << endl;
                                    cout << "Deposit successful. Balance: ¥";
                                    SetConsoleTextAttribute(h, 2);
                                    cout << fixed << setprecision(2) << balance;
                                    SetConsoleTextAttribute(h, 7);
                                    cout << "円" << endl;
                                    cout << endl;
                                }
                                cout << "Press any to continue..." << endl;
                                system("pause >nul");
                                system("cls");
                                break;
                            }
                            case 5:
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                cout << endl;
                                cout << "Thank you. Please take your receipt." << endl;
                                cout << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                                cout << "Press any to continue..." << endl;
                                system("pause >nul");
                                system("cls");
                                break;

                            default:
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                cout << "Invalid option." << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                    } while (option != 5);
                }
                break;
            }
            case 3:
                cout << endl;
                cout << "Closing the program." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
