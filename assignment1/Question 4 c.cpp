//transpose of a matrix

#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    int arr[r][c];
    cout << "Enter elements of the matrix:\n";
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Transpose of the matrix:\n";
    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}