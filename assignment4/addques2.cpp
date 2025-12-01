#include <iostream>
#include <queue>
using namespace std;

int findMin(queue<int>& q, int s) {
    int minVal = INT_MAX;
    int n = q.size();

    for(int i=0;i<n;i++) {
        int x = q.front();
        q.pop();
        if(x < minVal && i < s) minVal = x;
        q.push(x);
    }
    return minVal;
}

void insertMin(queue<int>& q, int minVal) {
    int n = q.size();
    bool flag = false;

    for(int i=0;i<n;i++) {
        int x = q.front();
        q.pop();
        if(x == minVal && !flag) flag = true;
        else q.push(x);
    }
    q.push(minVal);
}

int main() {
    queue<int> q;
    q.push(11); q.push(5); q.push(4); q.push(21);

    for(int i = q.size(); i > 0; i--) {
        int minVal = findMin(q, i);
        insertMin(q, minVal);
    }

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
