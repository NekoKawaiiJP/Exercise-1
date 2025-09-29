#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Utility functions
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

// Rainbow header (static colors, not animated)
void printRainbowHeader() {
    char header[] = "===== Exercise Questions =====";
    int colors[] = {12, 14, 10, 11, 13, 9}; // red, yellow, green, cyan, magenta, blue
    int len = sizeof(colors) / sizeof(colors[0]);

    gotoxy(0, 0);
    for (int i = 0; i < (int)strlen(header); i++) {
        setColor(colors[i % len]);
        printf("%c", header[i]);
    }
    setColor(7); // reset
    printf("\n");
}

// Animations
void rebootingAnimation() {
    clearScreen();
    setColor(10);
    for (int i = 0; i < 3; i++) {
        printf("Rebooting");
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            printf(".");
            fflush(stdout);
        }
        Sleep(500);
        clearScreen();
    }
}

void errorMessage() {
    setColor(12); 
    for (int i = 0; i < 3; i++) {
        printf("Error");
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            printf(".");
            fflush(stdout);
        }
        Sleep(500);
        clearScreen();
    }
}

void errortext() {
    setColor(12);
    for (int i = 0; i < 2; i++) {
        printf("System Failure Detected");
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            printf(".");
            fflush(stdout);
        }
        Sleep(500);
        clearScreen();
    }
}

void errorProgram() {
    setColor(12);
    for (int i = 0; i < 2; i++) {
        printf("Program will now format your PC");
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            printf(".");
            fflush(stdout);
        }
        Sleep(500);
        clearScreen();
    }
}

void formattingAnimation() {
    setColor(10);
    for (int i = 0; i <= 100; i++) {
        printf("\rFormatting PC... %d%% [", i);
        int bars = i / 2;
        for (int j = 0; j < bars; j++) printf("#");
        for (int j = bars; j < 50; j++) printf(" ");
        printf("]");
        fflush(stdout);
        Sleep(50);
    }
    Sleep(1000);
    clearScreen();
}

void justKiddingMessage() {
    setColor(7);
    for (int i = 0; i < 2; i++) {
        printf("Just Kidding");
        for (int j = 0; j < 3; j++) {
            Sleep(500);
            printf(".");
            fflush(stdout);
        }
        Sleep(500);
        clearScreen();
    }
}

void Retry() {
    clearScreen();
    setColor(10);
    printf("Try again by choosing number from 1 to 5 ONLY!\n");
    system("pause"); // wait for key press
}

// Main
int main() {
    int choice;

    do {
        clearScreen();
        printRainbowHeader(); // rainbow header

        // Menu in green
        setColor(10);
        printf("1. Calculate total and average of two numbers\n");
        printf("2. Calculate volume of a box\n");
        printf("3. Kanashi new salary with 5%% increment\n");
        printf("4. Itsuki gas mileage\n");
        printf("5. Exit\n");
        setColor(7);
        printf("Enter the question number (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int num1, num2, num3, total;
                float average;
                printf("\nEnter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                printf("Enter the third number: ");
                scanf("%d", &num3);

                total = num1 + num2 + num3;
                average = (float)total / 3;

                printf("Total: %d\n", total);
                printf("Average: %.2f\n", average);
                system("pause");
                break;
            }
            case 2: {
                int w, h, d, volume;
                printf("\nEnter width: ");
                scanf("%d", &w);
                printf("Enter height: ");
                scanf("%d", &h);
                printf("Enter depth: ");
                scanf("%d", &d);

                volume = w * h * d;
                printf("The volume of the box is: %d\n", volume);
                system("pause");
                break;
            }
            case 3: {
                double salary, newSalary;
                printf("\nEnter Kanashi current salary: ");
                scanf("%lf", &salary);

                newSalary = salary + (salary * 0.05);
                printf("Kanashi new salary after 5%% increment: MYR/RM %.2f\n", newSalary);
                system("pause");
                break;
            }
            case 4: {
                double distance = 234, gallons = 15, mpg;
                mpg = distance / gallons;
                printf("\nDistance travelled: %.2f miles\n", distance);
                printf("Gas used: %.2f gallons\n", gallons);
                printf("Car travelled: %.2f miles per gallon\n", mpg);
                system("pause");
                break;
            }
            case 5: {
                clearScreen();
                setColor(10);
                for (int i = 0; i < 3; i++) {
                    printf("Exiting Program");
                    for (int j = 0; j < 3; j++) {
                        Sleep(500);
                        printf(".");
                        fflush(stdout);
                    }
                    Sleep(500);
                    clearScreen();
                }
                system("pause"); // wait before closing
                system("exit");
                break; // exit the loop, then program ends
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

    } while(choice != 5);

    return 0;
}
