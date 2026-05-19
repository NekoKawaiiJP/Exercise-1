#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <limits>
using namespace std;

//Color Part
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE) {
        SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
    }
}

//Main Header
void printHeaderRepeated() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 2);
    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl << "※" << "                                                                                      ※" << "\n" << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Title        : ";
    SetConsoleTextAttribute(h, 11);
    cout << "Lab Report 1";
    SetConsoleTextAttribute(h, 2);
    cout << "                                                         ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Student Name : ";
    SetConsoleTextAttribute(h, 11);
    cout << "MUHAMMAD SYUHAIRUDEN BIN NAMRAH" << " | " << "MUHAMMAD ANAS MIRSAB BIN ABD GAPAR";
    SetConsoleTextAttribute(h, 2);
    cout << " ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Student ID   : ";
    SetConsoleTextAttribute(h, 11);
    cout << "012025021052" << "                    | " << "012025020271";
    SetConsoleTextAttribute(h, 2);
    cout << "                       ※" << endl << "※";
    SetConsoleTextAttribute(h, 14);
    cout << "  Program      : ";
    SetConsoleTextAttribute(h, 11);
    cout << "BETE" << "                            | " << "BETE";
    SetConsoleTextAttribute(h,2);
    cout << "                               ※";
    cout << "\n";
    SetConsoleTextAttribute(h, 2);
    cout << "※" << "                                                                                      ※" << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
    SetConsoleTextAttribute(h, 7);
}

//Clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Sales Report Part
void Sales_Report() {
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14);
    int products = 0, months = 0;
    cout << endl;
    cout << "Enter number of products: ";
    SetConsoleTextAttribute(h, 10);
    while (!(cin >> products) || products <= 0) {
        SetConsoleTextAttribute(h, 4);
        cout << "Error... Please enter a valid positive number for products: ";
        SetConsoleTextAttribute(h, 14);
        clearInput();
    }
    system("cls");
    
    cout << endl;
    SetConsoleTextAttribute(h, 14);
    cout << "Enter number of months: ";
    SetConsoleTextAttribute(h, 10);
    while (!(cin >> months) || months <= 0) {
        SetConsoleTextAttribute(h, 4);
        cout << "Error... Please enter a valid positive number for months: ";
        SetConsoleTextAttribute(h, 14);
        clearInput();
    }
    system("cls");
    
    SetConsoleTextAttribute(h, 14);
    int overallTotal = 0;
    for (int p = 1; p <= products; p++) {
        int productTotal = 0;
        cout << "\nEnter sales for Product ";
        SetConsoleTextAttribute(h, 10);
        cout << p << endl;
        SetConsoleTextAttribute(h, 14);
        for (int m = 1; m <= months; m++) {
            int sales = 0;
            cout << endl;
            cout << "Month " << m << ": ";
            while (!(cin >> sales) || sales < 0) {
                SetConsoleTextAttribute(h, 4);
                cout << "Error... Please enter a valid non-negative number for sales: ";
                SetConsoleTextAttribute(h, 7);
                clearInput();
            }
            productTotal += sales;
        }
        // Calculation Part
        double average = static_cast<double>(productTotal) / months;
        cout << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "---------Sale Report---------\n" << endl;
        cout << "Product: "; 
        SetConsoleTextAttribute(h, 10);
        cout << p << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Total: ";
        SetConsoleTextAttribute(h, 10);
        cout << productTotal << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Average: " << fixed << setprecision(2);
        SetConsoleTextAttribute(h, 10);
        cout << average << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "\n-----------------------------\n" << endl;
        overallTotal += productTotal;
        SetConsoleTextAttribute(h, 14);
    }
    // Result Part
    SetConsoleTextAttribute(h, 14);
    cout << "\nOverall Total Sales: ";
    SetConsoleTextAttribute(h, 10);
    cout << overallTotal << endl;
    SetConsoleTextAttribute(h, 14);
    system("pause");
}

//Hotel Payment Part
void Hotel_Payment() {
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        int roomChoice = 0;
        int roomColor;
        string roomType;
        SetConsoleTextAttribute(h, 7);
        cout << "\n---Hotel Package---\n";
        SetConsoleTextAttribute(h, 3);
        cout << "1. Standard ";
        SetConsoleTextAttribute(h, 10);
        cout << "(RM150)\n";
        SetConsoleTextAttribute(h, 6);
        cout << "2. Deluxe ";
        SetConsoleTextAttribute(h, 10);
        cout << "(RM250)\n";
        SetConsoleTextAttribute(h, 5);
        cout << "3. Suite ";
        SetConsoleTextAttribute(h, 10);
        cout << "(RM400)\n";
        SetConsoleTextAttribute(h, 4);
        cout << "4. Return to Main Menu\n" << endl;
        SetConsoleTextAttribute(h, 10);
        cout << "Select desired package (1-4): ";
        SetConsoleTextAttribute(h, 7);
        while (!(cin >> roomChoice) || roomChoice < 1 || roomChoice > 4) {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid number (1-4): ";
            SetConsoleTextAttribute(h, 7);
            clearInput();
        }
        if (roomChoice == 4) {
            break;
        }
        double rate = 0.0;
        switch (roomChoice) {
            case 1: {
                system("cls");
                
                int opt;
                SetConsoleTextAttribute(h, 7);
                cout << "\nYou selected ";
                SetConsoleTextAttribute(h, 3);
                cout << "Standard";
                SetConsoleTextAttribute(h, 7);
                cout << " Room.\n";
                SetConsoleTextAttribute(h, 14);
                cout << "1. Continue\n";
                SetConsoleTextAttribute(h, 4);
                cout << "2. Return to Room Menu\n";
                SetConsoleTextAttribute(h, 10);
                cout << "Enter selection: ";
                SetConsoleTextAttribute(h, 10);
                while (!(cin >> opt) || (opt != 1 && opt != 2)) {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Error... Please enter 1 to continue or 2 to return: ";
                    SetConsoleTextAttribute(h, 10);
                    clearInput();
                }
                if (opt == 2) {
                    system("cls");
                    
                    continue;
                }
                system("cls");
                rate = 150.0;
                break;
            }
            case 2: {
                system("cls");
                
                int opt;
                SetConsoleTextAttribute(h, 7);
                cout << "\nYou selected ";
                SetConsoleTextAttribute(h, 6);
                cout << "Deluxe";
                SetConsoleTextAttribute(h, 7);
                cout << " Room.\n";
                SetConsoleTextAttribute(h, 14);
                cout << "1. Continue\n";
                SetConsoleTextAttribute(h, 4);
                cout << "2. Return to Room Menu\n";
                SetConsoleTextAttribute(h, 10);
                cout << "Enter selection: ";
                while (!(cin >> opt) || (opt != 1 && opt != 2)) {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Error... Please enter 1 to continue or 2 to return: ";
                    SetConsoleTextAttribute(h, 10);
                    clearInput();
                }
                if (opt == 2) {
                    system("cls");
                    
                    continue;
                }
                system("cls");
                rate = 250.0;
                break;
            }
            case 3: {
                system("cls");
                
                int opt;
                SetConsoleTextAttribute(h, 7);
                cout << "\nYou selected ";
                SetConsoleTextAttribute(h, 5);
                cout << "Suite";
                SetConsoleTextAttribute(h, 7);
                cout << " Room.\n";
                SetConsoleTextAttribute(h, 14);
                cout << "1. Continue\n";
                SetConsoleTextAttribute(h, 4);
                cout << "2. Return to Room Menu\n";
                SetConsoleTextAttribute(h, 10);
                cout << "Enter selection: ";
                while (!(cin >> opt) || (opt != 1 && opt != 2)) {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Error... Please enter 1 to continue or 2 to return: ";
                    SetConsoleTextAttribute(h, 10);
                    clearInput();
                }
                if (opt == 2) {
                    system("cls");
                    
                    continue;
                }
                system("cls");
                rate = 400.0;
                break;
            }
            default:
                continue;
        }
        int nights = 0;
        int month = 0;
        int membershipColor;
        string membership;
        
        SetConsoleTextAttribute(h, 14);
        cout << "\nEnter number of nights: ";
        while (!(cin >> nights) || nights <= 0) {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid positive number for nights: ";
            SetConsoleTextAttribute(h, 7);
            clearInput();
        }
        SetConsoleTextAttribute(h, 14);
        cout << "\nEnter membership (";
        SetConsoleTextAttribute(h, 6);
        cout << "Gold";
        SetConsoleTextAttribute(h, 14);
        cout <<"/";
        SetConsoleTextAttribute(h, 9);
        cout <<"Silver";
        SetConsoleTextAttribute(h, 14);
        cout <<"/";
        SetConsoleTextAttribute(h, 13);
        cout <<"Bronze";
        SetConsoleTextAttribute(h, 14);
        cout <<"/";
        SetConsoleTextAttribute(h, 7);
        cout <<"None";
        SetConsoleTextAttribute(h, 14);
        cout <<"): ";
        cin >> membership;
        while (membership != "Gold" && membership != "Silver" && membership != "Bronze" && membership != "None") {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid membership (Gold/Silver/Bronze/None): ";
            SetConsoleTextAttribute(h, 7);
            cin >> membership;
        }
        SetConsoleTextAttribute(h, 14);
        cout << endl;
        cout << "Enter month (1-12): ";
        while (!(cin >> month) || month < 1 || month > 12) {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid month number (1-12): ";
            SetConsoleTextAttribute(h, 7);
            clearInput();
        }
        system("cls");
        
        SetConsoleTextAttribute(h, 14);
        double discountRate = 0.0;
        if (membership == "Gold") {
            if (nights >= 5) discountRate = 0.25;
        } else if (membership == "Silver") {
            if (nights >= 3) discountRate = 0.15;
        } else if (membership == "Bronze") {
            if (nights >= 2) discountRate = 0.10;
        } else {
            discountRate = 0.0;
        }
        double totalBeforeDiscount = rate * nights;
        double discountAmount = totalBeforeDiscount * discountRate;
        double afterDiscount = totalBeforeDiscount - discountAmount;
        double surchargeAmount = 0.0;
        if (month == 12) {
            surchargeAmount = afterDiscount * 0.10;
        }
        double finalAmount = afterDiscount + surchargeAmount;
        cout << fixed << setprecision(2);
        SetConsoleTextAttribute(h, 14);
        cout << "\n---------Payment Summary---------" << endl;
        cout << "Room Type: ";
                switch (roomChoice) {
            case 1:
                roomType = "Standard";
                roomColor = 3;
                break;
            case 2:
                roomType = "Deluxe";
                roomColor = 6;
                break;
            case 3:
                roomType = "Suite";
                roomColor = 5;
                break;
        }
        SetConsoleTextAttribute(h, roomColor);
        cout <<  roomType << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Membership             : ";
        if (membership == "Gold") {
            membershipColor = 6;
        } else if (membership == "Silver") {
            membershipColor = 9;
        } else if (membership == "Bronze") {
            membershipColor = 13;
        } else {
            membershipColor = 7;
        }
        SetConsoleTextAttribute(h, membershipColor);
        cout << membership << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Room rate per night    : ";
        SetConsoleTextAttribute(h, 10);
        cout << "RM" << rate << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Nights                 : ";
        SetConsoleTextAttribute(h, 10);
        cout << nights << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Total before discount  : ";
        SetConsoleTextAttribute(h, 10);
        cout << "RM" << totalBeforeDiscount << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Discount amount        : ";
        SetConsoleTextAttribute(h, 10);
        cout << "RM" << discountAmount << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Surcharge (if any)     : ";
        SetConsoleTextAttribute(h, 10);
        cout << "RM" << surchargeAmount << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Final amount to pay    : ";
        SetConsoleTextAttribute(h, 10);
        cout << "RM" << finalAmount << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "---------------------------------" << endl;
        SetConsoleTextAttribute(h, 7);
        system("pause");
        break;
    }
}

//Main Function
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice = 0;
    
    while (true) {
        SetConsoleTextAttribute(h, 11);
        cout << "\nQuestion:\n";
        SetConsoleTextAttribute(h, 7);
        cout << "1. Sales Report" << endl;
        cout << "2. Hotel Payment" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "3. Exit" << endl;
        SetConsoleTextAttribute(h, 10);
        cout << "Selection option (1-3): ";

        while (!(cin >> choice) || choice < 1 || choice > 3) {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid number (1-3): ";
            SetConsoleTextAttribute(h, 7);
            clearInput();
        }

        switch (choice) {
            case 1:
                system("cls");
                Sales_Report();
                break;
            case 2:
                system("cls");
                Hotel_Payment();
                break;
            case 3:
                system("cls");
                SetConsoleTextAttribute(h, 15);
                cout << "\nClosing the program...\n";
                return 0;
            default:
                break;
        }
        system("cls");
        
    }
    return 0;
}