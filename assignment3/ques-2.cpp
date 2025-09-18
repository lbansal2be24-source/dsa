//Reversal of string using stack

#include <iostream>
using namespace std;

int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;
    char stack[100];
    int top=-1;

    for(int i=0; i<str.length(); i++){
        stack[++top]=str[i];
    }

    cout<<"Reversed string is: ";
    for(int i=top; i>=0; i--){
        cout<<stack[i];
    }

    return 0;
}