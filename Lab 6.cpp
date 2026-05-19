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
    cout << "Lab 6";
    SetConsoleTextAttribute(h, 2);
    cout << "                                                         ※" << endl << "※";
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

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(h, 13);
    cout << "While Loop: " << endl;
    int i = 1;
    while (i <= 10) {
        SetConsoleTextAttribute(h,3);
        cout << i << " - Square: " << i * i << endl;
        i++;
        SetConsoleTextAttribute(h,13);
    }
    cout << endl;
    cout << "Do-While Loop: " << endl;
    i = 1;
    do {
        SetConsoleTextAttribute(h,3);
        cout << i << " - Square: " << i * i << endl;
        i++;
    } while (i <= 10);
    SetConsoleTextAttribute(h,13);
    cout << endl;
    cout << "For Loop:" << endl;
    for (int i = 1; i <= 10; i++) {
        SetConsoleTextAttribute(h,3);
        cout << i << " - Square: " << i * i << endl;
    }
}
