//Binary Search

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in sorted order: ";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int ele;
    cout<<"Enter the element to be searched: ";
    cin>>ele;
    int f=0,l=n-1,mid;
    
    while(f<=l){
        mid=(f+l)/2;
        if(arr[mid]==ele){
            cout<<"Element found at index "<<mid<<" or position "<<mid+1<<endl;
            return 0;
        }
        else if(arr[mid]<ele){
            f=mid+1;
        }
        else{
            l=mid-1;
        }
    }
    cout<<"Element not found"<<endl;
    
    return 0;
}