// finding the missing number in an array of size n-1 containing numbers from 1 to n through linear search

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
    
    int mn = -1;
    
    for(int i=1; i<=n; i++){
        bool found = false;
        
        for(int j=0; j<n-1; j++){
            if(arr[j] == i){
                found = true;
                break;
            }
        }
        
        if(!found){
            mn = i;
            break;
        }
    }

    cout<<"The missing number is: "<<mn<<endl;
    
    return 0;
}