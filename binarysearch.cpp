#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>vec,int target){
    int low=0,high=vec.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]<target){
            low=mid+1;
        }else if(vec[mid]>target){
            high=mid-1;

        }
        else{return mid;
    }
    
}
return -1;
}
int main(){
    vector<int>vec={-1,0,3,4,8,9,12,14};
int target=14;
int index=binarysearch( vec, target);
cout << index<<endl;
return 0;
}