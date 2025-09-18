// program to check if expression has balanced parentheses or not using stack

#include <iostream>
using namespace std;

int main(){

    string str;
    cout<<"Enter the expression: ";
    cin>>str;
    int n = str.length();
    char stk[n];
    int top = -1;
    bool T = true;
    for(int i=0; i<n; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            stk[++top] = str[i];
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(top == -1){
                T = false;
                break;
            }
            char temp = stk[top--];
            if((str[i] == ')' && temp != '(') || (str[i] == '}' && temp != '{') || (str[i] == ']' && temp != '[')){
                T = false;
                break;
            }
        }
    }

    if(top != -1){
        T = false;
    }
    if(T){
        cout<<"The expression has balanced parentheses."<<endl;
    }
    else{
        cout<<"The expression does not have balanced parentheses."<<endl;
    }
    
    return 0;
}