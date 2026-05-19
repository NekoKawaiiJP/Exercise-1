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

void printHeaderRepeated() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl << "※" << "                                                                                      ※" << "\n" << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Title        : ";
    SetConsoleTextAttribute(h, 11);
    cout << "Lab 8";
    SetConsoleTextAttribute(h, 2);
    cout << "                                                                ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Student Name : ";
    SetConsoleTextAttribute(h, 11);
    cout << "X";
    SetConsoleTextAttribute(h, 2);
    cout << "                                      ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Student ID   : ";
    SetConsoleTextAttribute(h, 11);
    cout << "X";
    SetConsoleTextAttribute(h, 2);
    cout << "                                                         ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Program      : ";
    SetConsoleTextAttribute(h, 11);
    cout << "X";
    SetConsoleTextAttribute(h,2);
    cout << "                                                                 ※";
    cout << "\n";
    SetConsoleTextAttribute(h, 2);
    cout << "※" << "                                                                                      ※" << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
    SetConsoleTextAttribute(h, 7);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int n;
    cout << "Enter the number of integers to be stored in the array: ";
    cin >> n;
    cout << fixed << setprecision(2);
    cout << endl;
    system("cls");
    

    while (cin.fail() || n <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
        cin >> n;
    }
    int* arr = new int[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << endl;
        cout << "Enter value for arr[" << i << "]: ";
        cin >> arr[i];
    }
    system("cls");
    
    cout << "You entered the following integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << endl;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
    delete[] arr;
}
