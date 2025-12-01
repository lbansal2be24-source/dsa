#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    for(int i = 0; i < n/2; i++) {
        int minIndex = i;
        int maxIndex = i;

        for(int j = i; j < n - i; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
            if(arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        swap(arr[i], arr[minIndex]);

        if(maxIndex == i)
            maxIndex = minIndex;

        swap(arr[n - i - 1], arr[maxIndex]);
    }

    for(int x : arr)
        cout << x << " ";

    return 0;
}
