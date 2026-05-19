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
    cout << "Assignment 2 - Cafe Ratings & Book System";
    SetConsoleTextAttribute(h, 2);
    cout << "                            ※" << endl << "※";
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

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Cafe();
void Bookstore();

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int choice;
    
    while (true) {
        SetConsoleTextAttribute(h, 11);
        cout << "\nQuestion:\n";
        SetConsoleTextAttribute(h, 7);
        cout << "1. Cafe Rating" << endl;
        cout << "2. Bookstore" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "3. Exit" << endl;
        SetConsoleTextAttribute(h, 10);
        cout << "Selection option (1-3): ";
        SetConsoleTextAttribute(h, 7);
        while (!(cin >> choice) || choice < 1 || choice > 3) {
            SetConsoleTextAttribute(h, 4);
            cout << "Error... Please enter a valid number (1-3): ";
            SetConsoleTextAttribute(h, 7);
            clearInput();
        }
        switch (choice) {
            case 1:
                system("cls");
                Cafe();
                break;
            case 2:
                system("cls");
                Bookstore();
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

void Cafe() {
    
    const int DAYS = 30;
    int ratings[DAYS];
    int frequency[5] = {0};

    cout << "\nEnter Cafe Ratings (1-5)\n";

    for (int i = 0; i < DAYS; i++) {
        do {
            cout << "Enter rating for Day " << i + 1 << " (1-5): ";
            cin >> ratings[i];
        } while (ratings[i] < 1 || ratings[i] > 5);

        frequency[ratings[i] - 1]++;
    }

    double percentage[5];
    for (int i = 0; i < 5; i++) {
        percentage[i] = (frequency[i] / (double)DAYS) * 100;
    }

    int currentStreak = 1, maxStreak = 1;
    for (int i = 1; i < DAYS; i++) {
        if (ratings[i] > ratings[i - 1]) {
            currentStreak++;
            if (currentStreak > maxStreak)
                maxStreak = currentStreak;
        } else {
            currentStreak = 1;
        }
    }

    int firstDay5 = -1;
    for (int i = 0; i < DAYS; i++) {
        if (ratings[i] == 5) {
            firstDay5 = i + 1;
            break;
        }
    }

    system("cls");
    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 6);
    cout << "\n=============== RATING ANALYSIS ===============\n";
    SetConsoleTextAttribute(h, 7);
    cout << "Rating   Frequency   Percentage\n";
    SetConsoleTextAttribute(h, 6);
    cout << "--------------------------------------------\n";
    SetConsoleTextAttribute(h, 7);

    for (int i = 0; i < 5; i++) {
        cout << setw(4) << (i + 1)
             << setw(10) << frequency[i]
             << setw(12) << fixed << setprecision(1) << percentage[i] << "%\n";
    }

    cout << "\n[TRENDS] Longest Increasing Streak: ";
    SetConsoleTextAttribute(h, 10);
    cout << maxStreak;
    SetConsoleTextAttribute(h, 7);
    cout << " days\n";

    if (firstDay5 != -1) {
        SetConsoleTextAttribute(h, 7);
        cout << "[TOP RATING] Highest (5) first on Day "; 
        SetConsoleTextAttribute(h, 10);
        cout << firstDay5;
        SetConsoleTextAttribute(h, 7);
        cout << endl;
    } else {
        cout << "[TOP RATING] No rating of 5 recorded.\n";
    }
    cout << endl;
    system("pause");
    system("cls");
    
}

void Bookstore() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    const int SIZE = 20;
    int codes[SIZE] = {101,102,103,104,105,106,107,108,109,110,
                       111,112,113,114,115,116,117,118,119,120};

    string titles[SIZE] = {
        "The Silent Forest", "Code Masters", "Ocean Mysteries",
        "Space Explorers", "Digital World", "Ancient History",
        "Robot Wars", "Chemistry Basics", "Math Pioneers",
        "Art of Design", "The Galactic Empire", "Data Science Essentials",
        "Python Programming", "AI Revolution", "World War Chronicles",
        "Financial Freedom", "Creative Writing", "Climate Change",
        "Quantum Physics", "Modern Art"
    };

    double prices[SIZE] = {
        25.99,45.50,30.00,28.75,35.20,40.00,19.99,22.50,50.00,27.80,
        33.90,55.00,42.75,60.00,29.95,37.45,18.99,34.50,48.00,27.80
    };

    int discounts[SIZE] = {
        10,15,0,5,10,0,5,0,20,10,
        15,10,5,15,0,10,0,5,10,10
    };

    int cartQty[50], cartIndex[50];
    int cartCount = 0;
    char more;

    
    SetConsoleTextAttribute(h , 11);
    cout << "\nWELCOME TO PAGETURNER BOOKSTORE\n\n";
    SetConsoleTextAttribute(h , 7);

    do {
        int code, qty;
        int index = -1;

        while (true) {
            SetConsoleTextAttribute(h, 10);
            cout << "Enter book code: ";
            SetConsoleTextAttribute(h, 7);
            cin >> code;

            for (int i = 0; i < SIZE; i++) {
                if (codes[i] == code) {
                    index = i;
                    break;
                }
            }

            if (index != -1) break;

            SetConsoleTextAttribute(h, 4);
            cout << "Invalid book code! Please try again.\n";
            clearInput();
        }

        do {
            SetConsoleTextAttribute(h, 10);
            cout << "Enter quantity: ";
            SetConsoleTextAttribute(h, 7);
            cin >> qty;
        } while (qty <= 0);

        cartIndex[cartCount] = index;
        cartQty[cartCount] = qty;
        cartCount++;

        double totalPrice = prices[index] * qty;
        double itemDiscount = totalPrice * discounts[index] / 100.0;
        double afterDiscount = totalPrice - itemDiscount;

        SetConsoleTextAttribute(h, 11);
        cout << "\n" << titles[index] << endl;
        SetConsoleTextAttribute(h, 14);
        cout << fixed << setprecision(2);
        cout << "Price: RM ";
        SetConsoleTextAttribute(h, 10);
        cout << prices[index] << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Quantity: ";
        SetConsoleTextAttribute(h, 10);
        cout << qty << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Total Price: RM ";
        SetConsoleTextAttribute(h, 10);
        cout << totalPrice << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Item Discount: ";
        SetConsoleTextAttribute(h, 10);
        cout << discounts[index] << "% (RM " << itemDiscount << ")" << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Price After Discount: RM ";
        SetConsoleTextAttribute(h, 10);
        cout << afterDiscount << "\n\n";

        SetConsoleTextAttribute(h, 14);
        cout << "Add another book? (Y/N): ";
        SetConsoleTextAttribute(h, 7);
        cin >> more;
        cout << endl;

    } while (more == 'Y' || more == 'y');

    system("cls");
    

    char member;
    SetConsoleTextAttribute(h, 13);
    cout << "\nMembership card (Y/N): ";
    SetConsoleTextAttribute(h, 7);
    cin >> member;

    system("cls");
    

    double grandTotal = 0, itemSavings = 0;

    SetConsoleTextAttribute(h , 6);
    cout << "\n-----------------------------------------------------------\n";
    SetConsoleTextAttribute(h , 14);
    cout << "               PAGETURNER BOOKSTORE RECEIPT\n";
    SetConsoleTextAttribute(h , 6);
    cout << "-----------------------------------------------------------\n";
    SetConsoleTextAttribute(h , 11);
    cout << "Code  Title                     Qty  Price  Discount  Total\n";

    for (int i = 0; i < cartCount; i++) {
        int idx = cartIndex[i];
        int q = cartQty[i];

        double total = prices[idx] * q;
        double discountAmt = total * discounts[idx] / 100.0;
        double finalPrice = total - discountAmt;

        itemSavings += discountAmt;
        grandTotal += finalPrice;

        cout << left << setw(6) << codes[idx]
             << setw(22) << titles[idx]
             << right << setw(5) << q
             << setw(8) << fixed << setprecision(2) << prices[idx]
             << setw(6.5) << discounts[idx] << "%"
             << setw(11.5) << finalPrice << endl;
    }

    double memberDiscount = 0;
    if (member == 'Y' || member == 'y')
        memberDiscount = grandTotal * 0.05;

    double amountDue = grandTotal - memberDiscount;
    double payment;
    SetConsoleTextAttribute(h , 6);
    cout << "\n-----------------------------------------------------------\n";
    SetConsoleTextAttribute(h , 14);
    cout << "Grand Total: RM ";
    SetConsoleTextAttribute(h , 10);
    cout << grandTotal << endl;
    SetConsoleTextAttribute(h , 14);
    cout << "Total Item Discounts: RM ";
    SetConsoleTextAttribute(h , 10);
    cout << itemSavings << endl;
    SetConsoleTextAttribute(h , 14);
    cout << "Membership Discount (5%): RM ";
    SetConsoleTextAttribute(h , 10);
    cout << memberDiscount << endl;
    SetConsoleTextAttribute(h , 14);
    cout << "Amount Due: RM ";
    SetConsoleTextAttribute(h , 10);
    cout << amountDue << endl;
    SetConsoleTextAttribute(h , 14);
    cout << "Payment Received: RM ";
    SetConsoleTextAttribute(h , 10);
    cin >> payment;

    while (payment < amountDue) {
        SetConsoleTextAttribute(h, 4);
        cout << "Insufficient payment. " << endl;
        SetConsoleTextAttribute(h, 14);
        cout << "Enter the payment again: RM ";
        cin >> payment;
    }

    system("cls");
    
    SetConsoleTextAttribute(h , 6);
    cout << "\n------------------------ RECEIPT ------------------------\n";
    SetConsoleTextAttribute(h , 9);
    cout << "\nAmount Paid: RM ";
    SetConsoleTextAttribute(h , 10);
    cout << payment << endl;
    SetConsoleTextAttribute(h , 9);
    cout << "Balance: RM "; 
    SetConsoleTextAttribute(h , 10);
    cout << payment - amountDue << endl;
    SetConsoleTextAttribute(h , 9);
    cout << "You Saved: RM "; 
    SetConsoleTextAttribute(h , 10);
    cout << itemSavings + memberDiscount << endl;
    cout << endl;
    SetConsoleTextAttribute(h , 6);
    cout << "\n---------------------------------------------------------\n";
    SetConsoleTextAttribute(h , 14);
    cout << "                  Thank you for shopping.\n";
    cout << "                    Please come again!\n";
    SetConsoleTextAttribute(h , 6);
    cout << "---------------------------------------------------------\n\n";

    system("pause");
}