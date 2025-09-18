//Write a program to convert a character from uppercase to lowercase.

#include <iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        char lowerCh = ch + 32;
        cout << "Lowercase character: " << lowerCh << endl;
    } else {
        cout << "The entered character is not an uppercase letter." << endl;
    }

    return 0;
}