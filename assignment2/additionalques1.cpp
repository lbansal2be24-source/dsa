#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;
    unordered_set<int> s;
    int count = 0;

    for (int x : arr) {
        if (s.count(x - k)) count++;
        if (s.count(x + k)) count++;
        s.insert(x);
    }

    cout << count;
    return 0;
}
