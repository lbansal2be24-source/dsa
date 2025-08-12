#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // ASCII difference between uppercase and lowercase
        cout << "Lowercase character: " << ch << endl;
    } else {
        cout << "The entered character is not uppercase." << endl;
    }

    return 0;
}
