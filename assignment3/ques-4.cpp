// infix to postfix

#include<iostream>
using namespace std;

char stack[100];
int top = -1;

void push(char x){
    stack[++top] = x;
}

void pop(){
    stack[top]='\0';
    top--;
}

int main(){
    string x,infix, postfix;
    cout<<"Enter the infix expression: ";
    cin>>x;
    infix = '(' + x + ')';
    postfix = "";
    
    
    for(int i=0; i<infix.length(); i++){
        
        if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z')){
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/'){
            while(stack[top]=='*' || stack[top]=='/' || stack[top]=='+' || stack[top]=='-'){
                
                if((infix[i]=='+' || infix[i]=='-') && (stack[top]=='*' || stack[top]=='/')){
                    postfix+=stack[top];
                    pop();
                }
                
                else if((infix[i]=='+' || infix[i]=='-') && (stack[top]=='+' || stack[top]=='-')){
                    postfix+=stack[top];
                    pop();
                }
                
                else if((infix[i]=='*' || infix[i]=='/') && (stack[top]=='*' || stack[top]=='/')){
                    postfix+=stack[top];
                    pop();
                }
                
                else{
                    break;
                }
            }
            push(infix[i]);
        }
        
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix+=stack[top];
                pop();
            }
            pop();
        }
}

    cout<<"The postfix expression is: "<<postfix;
    return 0;
}