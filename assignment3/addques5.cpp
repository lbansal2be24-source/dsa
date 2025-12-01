#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> A = {5, 1, 2, 3, 4};
    stack<int> S;
    int expected = 1;

    for(int i=0;i<A.size();i++) {
        S.push(A[i]);
        while(!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }
    }

    if(S.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
