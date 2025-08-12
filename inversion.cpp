#include<iostream>
using namespace std;
int main(){
    int arr[]={2,1,3,5,4,7,6,8};
    int n=8;
  int inv=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                inv++;
            }else{continue;}
            
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Number of inversions: "<<inv<<endl;
    return 0;
}