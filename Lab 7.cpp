#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n============================================" << endl;
        cout << "\nTitle: Lab 7" << endl;
        cout << "\nStudent Name: X" << endl;
        cout << "\nStudent ID: X" << endl;
        cout << "\nProgram: X" << endl;
        cout << "============================================" << endl;
        cout << "1. Multiplication Table" << endl;
        cout << "2. Quiz Program" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option (1-3): ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            int num;

            cout << "Enter a number: ";
            cin >> num;

            cout << "\nWhile Loop:\n";
            int i = 1;
            while (i <= 10) {
                cout << num << " x " << i << " = " << num * i << endl;
                i++;
            }

            cout << "\nDo-While Loop:\n";
            int j = 1;
            do {
                cout << num << " x " << j << " = " << num * j << endl;
                j++;
            } while (j <= 10);

            cout << "\nFor Loop:\n";
            for (int k = 1; k <= 10; k++) {
                cout << num << " x " << k << " = " << num * k << endl;
            }
            system("pause");
            system("cls");
        }

        else if (choice == 2) {
            int score = 0;
            char answer;
            cout << "Welcome to the Quiz!\n" << endl;
            cout << "Question 1:\n";
            cout << "What is the capital of France?\n";
            cout << "a) London\nb) Paris\nc) Rome\n";
            cout << "Your answer: ";
            cin >> answer;
            if (answer == 'b' || answer == 'B') score++;
            cout << "\n";
            system("pause");
            system("cls");
            
            cout << "Question 2:\n";
            cout << "What is the largest planet in our solar system?\n";
            cout << "a) Mars\nb) Earth\nc) Jupiter\n";
            cout << "Your answer: ";
            cin >> answer;
            if (answer == 'c' || answer == 'C') score++;
            cout << "\n";
            system("pause");
            system("cls");

            cout << "Question 3:\n";
            cout << "Who painted the Mona Lisa?\n";
            cout << "a) Leonardo da Vinci\nb) Vincent van Gogh\nc) Pablo Picasso\n";
            cout << "Your answer: ";
            cin >> answer;
            if (answer == 'a' || answer == 'A') score++;
            system("pause");
            system("cls");

            cout << "\nQuiz Results:\n";
            cout << "----------------\n";
            cout << "Correct Answers: " << score << endl;
            cout << "Incorrect Answers: " << 3 - score << endl;
            system("pause");
            system("cls");
        }

        else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
        }

        else {
            cout << "Invalid choice. Please select 1-3." << endl;
        }

        cout << endl;

    } while (choice != 3);

    return 0;
}
