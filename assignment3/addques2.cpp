#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int mini;

void push(int x) {
    if(s.empty()) {
        s.push(x);
        mini = x;
    }
    else {
        if(x < mini) {
            s.push(2*x - mini);
            mini = x;
        }
        else s.push(x);
    }
}

void pop() {
    if(s.empty()) return;

    if(s.top() < mini) {
        mini = 2*mini - s.top();
    }
    s.pop();
}

int getMin() {
    if(s.empty()) return -1;
    return mini;
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);
    cout << getMin() << endl;
    pop();
    cout << getMin() << endl;
}
