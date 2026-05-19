#include <iostream>
using namespace std;

double calcAverage(double overallmarks, int TotalStudents);

int main() {
    double overallmarks, average;
    int TotalStudents;

    cout << "Enter overall marks: ";
    cin >> overallmarks;

    cout << "Enter number of Total Students: ";
    cin >> TotalStudents;

    average = calcAverage(overallmarks, TotalStudents);
    cout << "Average mark = " << average << endl;

    return 0;
}

double calcAverage(double overallmarks, int TotalStudents) {
    return overallmarks / TotalStudents;
}