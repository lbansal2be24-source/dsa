// menu driven program for queue operation on circular queue

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of circular queue: ";
    cin>>n;
    int cq[n];
    int f=-1, r=-1;
    int ch;
    cout<<"1.Enqueue\n2.Dequeue\n3.is empty\n4.is full\n5.display\n6.peek\n7.exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    while(ch!=7){
        switch(ch){
            case 1: 
                if((r+1)%n==f){
                    cout<<"Circular Queue is full\n";
                }
                else{
                    int val;
                    cout<<"Enter value to be inserted: ";
                    cin>>val;
                    if(f==-1){
                        f=0;
                    }
                    r=(r+1)%n;
                    cq[r]=val;
                    cout<<val<<" inserted\n";
                }
                break;
            case 2:
                if(f==-1){
                    cout<<"Circular Queue is empty\n";
                }
                else{
                    cout<<cq[f]<<" deleted\n";
                    if(f==r){
                        f=-1;
                        r=-1;
                    }
                    else{
                        f=(f+1)%n;
                    }
                }
                break;
            case 3:
                if(f==-1){
                    cout<<"Circular Queue is empty\n";
                }
                else{
                    cout<<"Circular Queue is not empty\n";
                }
                break;
            case 4:
                if((r+1)%n==f){
                    cout<<"Circular Queue is full\n";
                }
                else{
                    cout<<"Circular Queue is not full\n";
                }
                break;
            case 5:
                if(f==-1){
                    cout<<"Circular Queue is empty\n";
                }
                else{
                    cout<<"Elements in Circular Queue are: ";
                    int i=f;
                    while(true){
                        cout<<cq[i]<<" ";
                        if(i==r){
                            break;
                        }
                        i=(i+1)%n;
                    }
                    cout<<endl;
                }
                break;
            case 6:
                if(f==-1){
                    cout<<"Circular Queue is empty\n";
                }
                else{
                    cout<<"Front element is: "<<cq[f]<<endl;
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