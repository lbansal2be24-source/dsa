//Lower triangular Matrix using one D array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    int arr[n*(n+1)/2];
    cout<<"Enter the non zero elements of the matrix (row wise): "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i*(i+1)/2 + j];
        }
    }

    cout<<"The lower triangular matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<=i){
                cout<<arr[i*(i+1)/2 + j]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}