#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;


int main() {
    int choice = 0;
    do {
        cout << "\n    Question    \n";
        cout << "1. Calculate BMI\n";
        cout << "2. Exit\n";
        cout << "Select an option (1-2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please select 1 for Question and 2 for Exit.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                double weight = 0.0, height = 0.0, bmi = 0.0;

                cout << "Your weight in kilograms (kg): " << endl;
                cin >> weight;

                cout << "Want using meters(m) or centimeters(cm)?" << endl;
                cout << "Enter 1 for (m) or 2 for (cm): " << endl;
                int hUnit = 1;
                if (!(cin >> hUnit)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input for unit. Defaulting to meters.\n";
                    hUnit = 1;
                }

                if (hUnit == 1) {
                    cout << "Your height in meters (m): ";
                    cin >> height;
                } else {
                    double heightCm = 0.0;
                    cout << "Your height in centimeters (cm): ";
                    cin >> heightCm;
                    
                    height = heightCm / 100.0;
                }

                if (height <= 0) {
                    cout << "Invalid height. Height must be greater than 0.\n";
                    break;
                }

                bmi = weight / (height * height);

                cout << fixed << setprecision(2);
                cout << "\nYour weight: " << weight << " kg\n";
                cout << "Your height: " << height << " m\n";
                cout << "Your BMI: " << bmi << "\n" << endl;

                if (bmi < 16)
                    cout << "Status: You are Seriously underweight.\n";
                else if (bmi < 18)
                    cout << "Status: You are underweight.\n";
                else if (bmi < 24)
                    cout << "Status: You are normal weight.\n";
                else if (bmi < 29)
                    cout << "Status: You are overweight.\n";
                else if (bmi < 35)
                    cout << "Status: You are seriously overweight.\n";
                else
                    cout << "Status: You are gravely overweight.\n";
                cout << "\nPress any key to continue..." << flush;
                system("pause >nul");
                system("cls");
            } break;

            case 2:
                cout << "Exit\n";
                break;

            default:
                cout << "Unknown choice. Select 1 or 2.\n";
        }
    } while (choice != 2);

    return 0;
}