#include <iostream>
using namespace std;

int main() {
char c;
cout << "Write the input: " << endl;
cin >> c;
do {
    cout << "Input is " << c << endl;
    cin >> c;
    } while (c != '!');
return 0;
}