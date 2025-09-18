//program to evaluate postfix expression using stack

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the postfix expression: ";
    cin>>n;
    char postfix[n];
    cout<<"Enter the postfix expression: ";
    for(int i=0;i<n;i++){
        cin>>postfix[i];
    }
    int stack[n];
    int top=-1;
    for(int i=0;i<n;i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            stack[++top]=postfix[i]-'0';
        }
        else{
            int op2=stack[top--];
            int op1=stack[top--];
            switch(postfix[i]){
                case '+':
                    stack[++top]=op1+op2;
                    break;
                case '-':
                    stack[++top]=op1-op2;
                    break;
                case '*':
                    stack[++top]=op1*op2;
                    break;
                case '/':
                    stack[++top]=op1/op2;
                    break;
            }
        }
    }
    cout<<"The result of the postfix expression is: "<<stack[top]<<endl;
    
    return 0;
}