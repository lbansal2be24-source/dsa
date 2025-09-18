// finding the missing number in an array of size n-1 containing numbers from 1 to n through binary search

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n-1];
    cout<<"Enter the elements of the array: ";
    
    for(int i=0; i<n-1; i++){
        cin>>arr[i];
    }
    int f=0, l=n-2,mid;
    
    while(f<=l){
        mid=(f+l)/2;
        if(arr[mid]==mid+1){
            f=mid+1;
        }
        else{
            l=mid-1;
        }
    }
    cout<<"The missing number is: "<<f+1<<endl;
    
    return 0;
}