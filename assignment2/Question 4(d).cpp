//Write a program to sort the strings in alphabetical order

#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cout<<"Enter a string (without spaces): ";
    cin>> str;
    string str1 = "";
    for(int i=0; i<str.length(); i++){
        for(int j=i+1; j<str.length(); j++){
            if(str[i]>str[j]){
                swap(str[i], str[j]);
            }
        }
    }
    cout<<"Sorted string is: "<<str;
    return 0;
}