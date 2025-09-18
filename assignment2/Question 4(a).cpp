//Write a program to concatenate one string to another string.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter the first string (without spaces): ";
    cin>> str1;
    cout << "\n Enter the second string (without spaces): ";
    cin>> str2;
    str1=str1+str2;
    cout << "\n Concatenated string: " << str1;
    return 0;
}