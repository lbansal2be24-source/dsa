//Write a program to delete all the vowels from the string

#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cout<<"Enter a string (without spaces): ";
    cin>> str;
    string str1= "";
    for(int i=0; i<str.length(); i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='A' && str[i]!='E' && str[i]!='I' && str[i]!='O' && str[i]!='U'){
            str1+=str[i];
        }
    }
    cout<<"String after deleting vowels: "<<str1;
    return 0;
}