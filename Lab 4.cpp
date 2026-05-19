#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    cout << "\n______________________________________________________" << endl;
    cout << "\nTitle: Lab 4" << endl;
    cout << "\nStudent Name: MUHAMMAD SYUHAIRUDEN BIN NAMRAH" << endl;
    cout << "\nStudent ID: 012025021052" << endl;
    cout << "\nProgram: BETE" << endl;
    cout << "\n______________________________________________________" << endl;

    double Test_1, Test_2;
    cout << "\nEnter the mark for TEST #1 (fullmark is 100): ";
    cin >> Test_1;
    cout << "Enter the mark for TEST #2 (fullmark is 100): ";
    cin >> Test_2;
    double Total_Test = (Test_1 + Test_2) / 200 * 20;

    double Assignment;
    cout << "Enter the mark for ASSIGNMENT (fullmark is 50): ";
    cin >> Assignment;
    double Assignment_Total = Assignment / 50 * 5;

    double Quiz_1, Quiz_2, Quiz_3;
    cout << "Enter the mark for QUIZ #1 (fullmark is 20): ";
    cin >> Quiz_1;
    cout << "Enter the mark for QUIZ #2 (fullmark is 20): ";
    cin >> Quiz_2;
    cout << "Enter the mark for QUIZ #3 (fullmark is 20): ";
    cin >> Quiz_3;
    double Quiz_Total = (Quiz_1 + Quiz_2 + Quiz_3) / 60 * 15;

    double Final_exam;
    cout << "Enter the mark for FINAL EXAM (fullmark is 100): ";
    cin >> Final_exam;
    double Final_Total = Final_exam / 100 * 60;

    double Carry_mark = Total_Test + Assignment_Total + Quiz_Total;

    cout << "\nSummary" << endl;
    cout << "TEST (20%) : " << Total_Test << endl;
    cout << "ASSIGNMENT (5%) : " << Assignment_Total << endl;
    cout << "QUIZ (15%) : " << Quiz_Total << endl;
    cout << "Carry mark (40%) : " << Carry_mark << endl;
    cout << "Final exam (60%) : " << Final_Total << endl;
    cout << "The final mark : " << Carry_mark + Final_Total << endl;

    return 0;
}
