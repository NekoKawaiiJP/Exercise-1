#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

DWORD WINAPI rainbowHeader(LPVOID lpParam) {
    int colors[] = {12, 14, 10, 11, 13, 9}; // red, yellow, green, cyan, magenta, blue
    int len = sizeof(colors) / sizeof(colors[0]);

    while (1) {
        for (int i = 0; i < len; i++) {
            gotoxy(0, 0); // always print at top
            setColor(colors[i]);
            printf("===== Exercise Questions =====        "); // spaces to overwrite leftovers
            Sleep(500); // animation speed
        }
    }
    return 0;
}

// Color codes:
// 0 = Black
// 1 = Blue
// 2 = Green
// 3 = Aqua
// 4 = Red
// 5 = Purple
// 6 = Yellow
// 7 = White (default)
// 8 = Gray
// 9 = Light Blue
// 10 = Light Green
// 11 = Light Aqua
// 12 = Light Red
// 13 = Light Purple
// 14 = Light Yellow
// 15 = Bright White

void clearScreen() {
    system("cls");
}

void rebootingAnimation() {
    clearScreen();
    setColor(10);
    for (int i = 0; i < 3; i++) {
        printf("Rebooting");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf(".");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

void errorMessage() {
    setColor(12); 
    for (int i = 0; i < 3; i++) {
        printf("Error");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf(".");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

void errortext() {
    setColor(12);
    for (int i = 0; i < 3; i++) {
        printf("System Failure Detected");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf(".");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

void errorProgram() {
    setColor(12);
    for (int i = 0; i < 3; i++) {
        printf("Program will now format your PC");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf(".");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

void formattingAnimation() {
    setColor(10);
    for (int i = 0; i <= 100; i += 5) {
        printf("Formatting PC... %d%%\n", i);
        for(int i = 0; i <= 100; i++) {
            printf("\r[");
            int bars = i / 2;
            for(int j = 0; j < bars; j++) printf("#");
            for(int j = bars; j < 50; j++) printf(" ");
            printf("] %d%%", i);
            fflush(stdout);
            Sleep(100);
        }
        Sleep(1000); 
        clearScreen();
    }
}

void justKiddingMessage() {
    setColor(7);
    for (int i = 0; i < 3; i++) {
        printf("Just Kidding");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf(".");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

void Retry() {
    clearScreen();
    setColor(10);
    for (int i = 0; i < 3; i++) {
        printf("Try again by choose number from 1 to 5 ONLY");
        for (int j = 0; j < 3; j++) {
            Sleep(1000);
            printf("!");
            fflush(stdout);
        }
        Sleep(1000);
        clearScreen();
    }
}

int main() {
    int choice;
    HANDLE hThread = CreateThread(NULL, 0, rainbowHeader, NULL, 0, NULL);
    if (hThread == NULL) {
        printf("Error creating thread!\n");
        return 1;
    }
    do {
        gotoxy(0, 0); 
        setColor(7);
        printf("1. Calculate total and average of two numbers\n");
        printf("2. Calculate volume of a box\n");
        printf("3. Kanashi new salary with 5%% increment\n");
        printf("4. Itsuki gas mileage\n");
        printf("5. Exit\n");
        printf("Enter the question number (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int num1, num2, total;
                float average;
                printf("\nEnter the first value or number: ");
                scanf("%d", &num1);
                printf("Enter the second value or number: ");
                scanf("%d", &num2);

                total = num1 + num2;
                average = (float)total / 2;

                printf("Total: %d\n", total);
                printf("Average: %.2f\n", average);
                system("pause");
                break;
            }
            case 2: {
                int width, height, depth, volume;
                printf("\nEnter width: ");
                scanf("%d", &width);
                printf("Enter height: ");
                scanf("%d", &height);
                printf("Enter depth: ");
                scanf("%d", &depth);

                volume = width * height * depth;
                printf("The volume of the box is: %d\n", volume);
                system("pause");
                break;
            }
            case 3: {
                double Current_Salary, Salary_After_increment;
                printf("\nEnter Kanashi current salary: ");
                scanf("%lf", &Current_Salary);

                Salary_After_increment = Current_Salary + (Current_Salary * 0.05);
                printf("Kanashi new salary after 5%% increment: %.2f\n", Salary_After_increment);
                system("pause");
                break;
            }
            case 4: {
                double distance = 234; 
                double gallons = 15;   
                double miles;

                miles = distance / gallons;

                printf("\nDistance travelled: %.2f miles\n", distance);
                printf("Gas used: %.2f gallons\n", gallons);
                printf("Car travelled: %.2f miles per gallon\n", miles);
                system("pause");
                break;
            }
            case 5:
                clearScreen();
                setColor(10);
                for (int i = 0; i < 3; i++) {
                    printf("Exiting Program");
                    for (int j = 0; j < 3; j++) {
                        Sleep(1000);
                        printf(".");
                        fflush(stdout);
                    }
                    Sleep(1000);
                    clearScreen();
                }
                TerminateThread(hThread, 0); 
                CloseHandle(hThread);
                return 0;
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

        system("pause");
        system("cls");
    } while(choice != 5);

    return 0;
}
