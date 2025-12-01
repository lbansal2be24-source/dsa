// priority queue using heaps

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // building max heap
    for(int i=1;i<n;i++){
        int childIndex = i;
        while(childIndex>0){
            int parentIndex = (childIndex-1)/2;
            if(arr[parentIndex]<arr[childIndex]){
                swap(arr[parentIndex],arr[childIndex]);
                childIndex = parentIndex;
            }
            else{
                break;
            }
        }
    }

    cout<<"Max Heap: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}