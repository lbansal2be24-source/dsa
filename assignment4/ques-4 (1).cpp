// program to find first non-repeating character in a string using Queue

#include <iostream>
using namespace std;

int main(){
    
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    int freq[26] = {0};
    int n = str.length();
    char queue[n];
    int f=-1, r=-1;
    for(int i=0; i<n; i++){
        char ch = str[i];
        freq[ch - 'a']++;
        if(freq[ch - 'a'] == 1){
            r++;
            queue[r] = ch;
        }
        while(f < r && freq[queue[f+1] - 'a'] > 1){
            f++;
        }
        if(f < r){
            cout<<queue[f+1]<<" ";
        }
        else{
            cout<<"-1 ";
        }
    }

    return 0;
}