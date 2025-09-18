//Upper triangular Matrix using 1D array

#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    int arr[n*(n+1)/2];
    
    cout<<"Enter the non zero elements of the matrix (row wise): "<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin>>arr[(i*(2*n - i + 1))/2 + (j - i)];
        }
    }
    
    cout<<"The upper triangular matrix is: "<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                cout<<arr[(i*(2*n - i + 1))/2 + (j - i)]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}