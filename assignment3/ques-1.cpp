// program to implement stack operations using array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of stack: ";
    cin>>n;
    int stack[n];
    int top = -1;
    int ch, val;

    cout << "1. Push\n2. Pop\n3. Is Empty\n4. Is Full\n 5. Peek\n6. Display\n7. Exit\n";
    cin>>ch;

    while(ch != 7){
        
        switch(ch){
            
            case 1:
                
            if(top == n-1){
                cout<<"Stack is full"<<endl;
                }
           
            else{
                cout<<"Enter the value to be pushed: ";
                cin>>val;
                top++;
                stack[top] = val;
                cout<<val<<" pushed to stack"<<endl;
                }
            
                break;
            
            case 2:
                
            if(top == -1){
                    cout<<"Stack is empty"<<endl;
                }
                
            else{
                cout<<stack[top]<<" popped from stack"<<endl;
                top--;
                }
                
            break;
            
            case 3:
                
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                }
                
            else{
                cout<<"Stack is not empty"<<endl;
                }
            
            break;
            
            case 4:
            
            if(top == n-1){
                cout<<"Stack is full"<<endl;
                }
            else{
                cout<<"Stack is not full"<<endl;
                }
                
            break;
            
            case 5:
                
                if(top == -1){
                    cout<<"Stack is empty"<<endl;
                }
                
                else{
                    cout<<"Top element is: "<<stack[top]<<endl;
                }
                
                break;
            
            case 6:
                
                if(top == -1){
                    cout<<"Stack is empty"<<endl;
                }
                
                else{
                    cout<<"Stack elements are: ";
                    
                    for(int i=top; i>=0; i--){
                        cout<<stack[i]<<" ";
                    }
                    cout<<endl;
                }
                
                break;
            
            default:
                cout<<"Invalid choice"<<endl;
        }
        cout << "1. Push\n2. Pop\n3. Is Empty\n4. Is Full\n 5. Peek\n6. Display\n7. Exit\n";
        cin>>ch;
    }

    return 0;
}