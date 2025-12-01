#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n = 10;
    queue<string> q;
    q.push("1");

    while(n--) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }

    return 0;
}
