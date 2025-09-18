//Tri-diagonal Matrix using One D array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    int arr[3*n-2];
    int size=3*n-2;
    cout<<"Enter the non zero elements of the matrix (row wise): "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The tri-diagonal matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==1){
                cout<<arr[i-1]<<" ";
            }
            else if(i-j==0){
                cout<<arr[n-1+i]<<" ";
            }
            else if(i-j==-1){
                cout<<arr[2*n-1+i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}