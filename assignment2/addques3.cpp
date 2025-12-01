#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b) cout << "YES";
    else cout << "NO";

    return 0;
}
