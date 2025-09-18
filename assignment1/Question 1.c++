/* 

Develop a Menu driven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT
*/

#include <iostream>
using namespace std;

int main(){
    int ch,n,arr[n],x=1;
    while(x){
    cout<< "---- MENU ----" << endl;
    cout<< "1. CREATE" << endl;
    cout<< "2. DISPLAY" << endl;
    cout<< "3. INSERT" << endl;
    cout<< "4. DELETE" << endl;
    cout<< "5. LINEAR SEARCH" << endl;
    cout<< "6. EXIT" << endl;
    cout<< "Please select an option (1-6): ";
    cin >> ch;
    
    if (ch < 1 || ch > 6) {
        cout << "Invalid ch. Please select a number between 1 and 6." << endl;
        return 1;
    }

    if (ch == 1) {
        cout << "Creating an array..." << endl;
        cout<< "Enter the size of the array: ";
        cin >> n;
        int i=0;
        while (i < n) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
            i++;
        }
        cout << "Array created successfully." << endl;
    } 
    
    else if (ch == 2) {
        cout << "Displaying the array..." << endl;
        for (int i = 0; i < n; i++) {
            cout << "Element " << i + 1 << ": " << arr[i] << endl;
        }
    } 
    
    else if (ch == 3) {
        cout << "Inserting an element into the array..." << endl;
        int ele, pos;
        cout << "Enter the element to insert: ";
        cin >> ele;
        cout << "Enter the position to insert the element (1 to " << n + 1 << "): ";
        cin >> pos;
        if (pos <= 0 || pos > n+1) {
            cout << "Invalid position. Please enter a position between 1 and " << n + 1<< "." << endl;
            return 1;
        }
        for (int i = n; i > pos-1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos-1] = ele;
        n++;
        cout << "Element inserted successfully." << endl;
    } 
    
    else if (ch == 4) {
        cout << "Deleting an element from the array..." << endl;
        int pos;
        cout << "Enter the position of the element to delete (1 to " << n << "): ";
        cin >> pos;
        if (pos < 0 || pos >= n) {
            cout << "Invalid position. Please enter a position between 1 and " << n << "." << endl;
            return 1;
        }
        for (int i = pos-1; i < n ; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        cout << "Element deleted successfully." << endl;

    } 
    
    else if (ch == 5) {
        cout << "Performing linear search in the array..." << endl;
        int ele, found = -1;
        cout << "Enter the element to search: ";
        cin >> ele;
        for (int i = 0; i < n; i++) {
            if (arr[i] == ele) {
                found = i;
                break;
            }
        }
        if (found != -1) {
            cout << "Element found at position: " << found + 1 << endl;
        } else {
            cout << "Element not found in the array." << endl;
        }
    } 
    
    else if (ch == 6) {
        cout << "Exiting the program." << endl;
        break;
    }
}
    return 0;
}