#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    stack<int> st;

    for(int i=0;i<arr.size();i++) {
        while(!st.empty() && st.top() >= arr[i])
            st.pop();

        if(st.empty()) cout << -1 << " ";
        else cout << st.top() << " ";

        st.push(arr[i]);
    }
    return 0;
}
