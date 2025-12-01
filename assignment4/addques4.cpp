#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    int c0 = 0, c1 = 0;

    for(int x : students) {
        if(x == 0) c0++;
        else c1++;
    }

    for(int x : sandwiches) {
        if(x == 0 && c0 > 0) c0--;
        else if(x == 1 && c1 > 0) c1--;
        else break;
    }

    cout << c0 + c1;
    return 0;
}
