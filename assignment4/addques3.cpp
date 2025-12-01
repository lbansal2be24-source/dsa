#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);

    stack<int> s;
    int expected = 1;

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        if (f == expected) expected++;
        else {
            while (!s.empty() && s.top() == expected) {
                s.pop();
                expected++;
            }
            s.push(f);
        }
    }

    while (!s.empty() && s.top() == expected) {
        s.pop();
        expected++;
    }

    if (s.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
