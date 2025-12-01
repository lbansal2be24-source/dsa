#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] == 2) count++;

    for (int i = n - 1; i >= 0; i--) {
        int newPos = i + count;
        if (newPos < n) arr[newPos] = arr[i];
        if (arr[i] == 2) {
            count--;
            if (i + count < n)
                arr[i + count] = 2;
        }
    }

    for (int i : arr) cout << i << " ";
    return 0;
}
