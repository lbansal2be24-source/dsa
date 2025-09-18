//program to implement queue operations

#include <iostream>
using namespace std;

int main(){

    int n,ch,val;
    cout<<"Enter size of queue: ";
    cin>>n;
    int queue[n];
    int f=-1,l=-1;
    cout<<"1.Enqueue\n2.Dequeue\n3.is empty\n4. is full\n5.display\n6.peek\n7.exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    while(ch!=7){
        switch(ch){
            case 1: 
                if(l==n-1){
                    cout<<"Queue is full\n";
                }
                else{
                    cout<<"Enter value to be inserted: ";
                    cin>>val;
                    if(f==-1){
                        f=0;
                    }
                    l++;
                    queue[l]=val;
                    cout<<val<<" inserted\n";
                }
                break;
            case 2:
                if(f==-1 || f>l){
                    cout<<"Queue is empty\n";
                }
                else{
                    cout<<queue[f]<<" deleted\n";
                    if (f==l){
                        f=-1;
                        l=-1;
                        break;
                    }
                    else{
                    for (int i=f;i<l;i++){
                        queue[i]=queue[i+1];
                    }
                    }
                    l--;
                    
                }
                break;
            case 3:
                if(f==-1 || f>l){
                    cout<<"Queue is empty\n";
                }
                else{
                    cout<<"Queue is not empty\n";
                }
                break;
            case 4:
                if(l==n-1){
                    cout<<"Queue is full\n";
                }
                else{
                    cout<<"Queue is not full\n";
                }
                break;
            case 5:
                if(f==-1 || f>l){
                    cout<<"Queue is empty\n";
                }
                else{
                    cout<<"Queue elements are: ";
                    for(int i=f;i<=l;i++){
                        cout<<queue[i]<<" ";
                    }
                    cout<<endl;
                }
                break;
            case 6:
                if(f==-1 || f>l){
                    cout<<"Queue is empty\n";
                }
                else{
                    cout<<"Front element is: "<<queue[f]<<endl;
                }
                break;
            default:
                cout<<"Invalid choice\n";
        }
        cout<<"Enter your choice: ";
        cin>>ch;
    }
            
    return 0;
}