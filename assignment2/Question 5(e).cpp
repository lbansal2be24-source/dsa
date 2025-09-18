//symmetric matrix in one dimensional array

#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;

    int arr[n*(n+1)/2];
    
    cout<<"Enter the elements of the matrix (row wise): "<<endl;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin>>arr[(i*(2*n - i + 1))/2 + (j - i)];
        }
    }
    
    cout<<"The symmetric matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>=i){
                cout<<arr[(i*(2*n - i + 1))/2 + (j - i)]<<" ";
            }
            else{
                cout<<arr[(j*(2*n - j + 1))/2 + (i - j)]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}