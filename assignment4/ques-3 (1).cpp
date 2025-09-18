//program interleave the first half of the queue with second half

#include <iostream>
using namespace std;

int main(){
    
    int n,ch,val;
    cout<<"Enter size of queue: ";
    cin>>n;
    int q[n];
    int f=-1,l=-1;
    cout<<"Enter the elements of the queue:\n";
    for(int i=0;i<n;i++){
        cin>>val;
        if(f==-1){
            f=0;
        }
        l++;
        q[l]=val;
    }
    int half=n/2;
    int temp1[half],temp2[half];
    for(int i=0;i<half;i++){
        temp1[i]=q[f+i];
    }
    for(int i=0;i<half;i++){
        temp2[i]=q[f+half+i];
    }
    int k=0;
    for(int i=f;i<n;i++){
        if(i%2==0){
            q[i]=temp1[k];
        }
        else{
            q[i]=temp2[k];
            k++;
        }
    }
    
    cout<<"Interleaved queue is:\n";
    for(int i=f;i<n;i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}