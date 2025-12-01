#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {8, 4, 2, 1};
    int count = 0;

    for(int i=0;i<arr.size();i++)
        for(int j=i+1;j<arr.size();j++)
            if(arr[i] > arr[j])
                count++;

    cout << count;
    return 0;
}
