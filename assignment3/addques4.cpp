#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans(temp.size());
    stack<int> st;

    for(int i=0;i<temp.size();i++) {
        while(!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }

    for(int x : ans)
        cout << x << " ";

    return 0;
}
