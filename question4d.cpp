#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // to clear newline from input buffer

    vector<string> arr(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr.begin(), arr.end()); // Sort in alphabetical order

    cout << "\nStrings in alphabetical order:\n";
    for (const string &s : arr) {
        cout << s << endl;
    }

    return 0;
}
