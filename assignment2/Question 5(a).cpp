//Diagonal Matrix in one D array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the diagonal matrix (row wise): ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}