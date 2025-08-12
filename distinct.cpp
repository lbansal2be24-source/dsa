#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,2,4,2,2,5,5,5,5};
    int n=10;
    int d=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                break;
        }if(j==n-1&&arr[i]!=arr[j]){
            d++;
        }else{continue;}
    }
    }
    cout<<"THE NUMBER OF DISTINCT ELEMENTS ARE : "<<d;
}
