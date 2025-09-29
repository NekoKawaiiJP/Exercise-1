#include <iostream>
#include <windows.h>
#include <limits>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

// ===== Utility Functions =====
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

// Pause until Press Enter
void pressEnter(const string& message = "Press Enter to continue...") {
    cout << "\n" << message;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ===== Clean Animated Header =====
void printRainbowHeaderAnimated() {
    string header = "      Exercise Questions      ";
    int colors[] = {12, 14, 10, 11, 13, 9};
    int len = sizeof(colors) / sizeof(colors[0]);

    cout << "\n"; 
    for (size_t i = 0; i < header.size(); i++) {
        setColor(colors[i % len]);
        cout << header[i] << flush;
        Sleep(40); 
    }
    setColor(7);
    cout << "\n\n"; 
}

// ===== Animations =====
void rebootingAnimation() {
    clearScreen();
    setColor(10);
    for (int i = 0; i < 3; i++) {
        cout << "Checking";
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            cout << ".";
            cout.flush();
        }
        Sleep(500);
        clearScreen();
    }
}

void errorMessage() {
    setColor(12);
    for (int i = 0; i < 3; i++) {
        cout << "Error";
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            cout << ".";
            cout.flush();
        }
        Sleep(500);
        clearScreen();
    }
}

void errortext() {
    setColor(12);
    for (int i = 0; i < 2; i++) {
        cout << "System32 Failed To Detect";
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            cout << ".";
            cout.flush();
        }
        Sleep(500);
        clearScreen();
    }
}

void errorProgram() {
    setColor(12);
    for (int i = 0; i < 2; i++) {
        cout << "Process to reinstall Windows";
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            cout << ".";
            cout.flush();
        }
        Sleep(500);
        clearScreen();
    }
}

void formattingAnimation() {
    setColor(10);
    for (int i = 0; i <= 100; i++) {
        cout << "\rReinstalling Windows... " << i << "% [";
        int bars = i / 2;
        for (int j = 0; j < bars; j++) cout << "#";
        for (int j = bars; j < 50; j++) cout << " ";
        cout << "]";
        cout.flush();
        Sleep(50);
    }
    Sleep(1000);
    clearScreen();
}

void justKiddingMessage() {
    setColor(7);
    for (int i = 0; i < 2; i++) {
        cout << "Failed to reinstall Windows due to lack of disk space";
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            cout << ".";
            cout.flush();
        }
        Sleep(500);
        clearScreen();
    }
}

void Retry() {
    clearScreen();
    setColor(10);
    cout << "GG...Your Windows Is Now Dead Due Your Mistaken.\n";
    cout << "Please Buy A New Laptop/PC To Continue Using Windows OS.\n";
    cout << "Just Kidding, Please Choose The Correct Option Next Time.\n";
    system("pause");
}

// ===== Main Program =====
int main() {
    int choice;

    do {
        clearScreen();
        printRainbowHeaderAnimated();

        setColor(10);
        cout << "1. Calculate total and average of three numbers\n";
        cout << "2. Calculate volume of a box\n";
        cout << "3. Anas new salary with 5% increment\n";
        cout << "4. Supra gas mileage\n";
        cout << "5. Exit\n";
        setColor(7);

        cout << "Enter the question number (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: {
                int num1, num2, num3, total;
                float average;
                cout << "\nEnter the 1st number: ";
                cin >> num1;
                cout << "Enter the 2nd number: ";
                cin >> num2;
                cout << "Enter the 3rd number: ";
                cin >> num3;

                total = num1 + num2 + num3;
                average = static_cast<float>(total) / 3;

                cout << "Total: " << total << endl;
                cout << "Average: " << average << endl;
                pressEnter();
                break;
            }
            case 2: {
                int w, h, d, volume;
                cout << "\nEnter width: ";
                cin >> w;
                cout << "Enter height: ";
                cin >> h;
                cout << "Enter depth: ";
                cin >> d;

                volume = w * h * d;
                cout << "The volume of the box is: " << volume << endl;
                pressEnter();
                break;
            }
            case 3: {
                double salary, newSalary;
                cout << "\nEnter Anas current salary: ";
                cin >> salary;

                newSalary = salary + (salary * 0.05);
                cout << "Anas new salary after 5% increment: MYR/RM " << newSalary << endl;
                pressEnter();
                break;
            }
            case 4: {
                double distance = 234, gallons = 15, mpg;
                mpg = distance / gallons;
                cout << "\nDistance travelled: " << distance << " miles\n";
                cout << "Gas used: " << gallons << " gallons\n";
                cout << "Car travelled: " << mpg << " miles per gallon\n";
                pressEnter();
                break;
            }
            case 5: {
                clearScreen();
                setColor(10);
                for (int i = 0; i < 3; i++) {
                    cout << "Quitting";
                    for (int j = 0; j < 3; j++) {
                        Sleep(500);
                        cout << ".";
                        cout.flush();
                    }
                    Sleep(500);
                    clearScreen();
                }
                pressEnter("Press Enter to continue...");
                break;
            }
            default:
                rebootingAnimation();
                errorMessage();
                errortext();
                errorProgram();
                formattingAnimation();
                justKiddingMessage();
                Retry();
                break;
        }

    } while (choice != 5);

    return 0;
}
