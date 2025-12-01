#include <iostream>
using namespace std;

int main() {
    int t[100][3], r, c, nz;
    cin >> r >> c >> nz;

    for(int i=0;i<nz;i++)
        cin >> t[i][0] >> t[i][1] >> t[i][2];

    int trans[100][3];
    int k = 0;

    for(int col=0; col<c; col++) {
        for(int i=0;i<nz;i++) {
            if(t[i][1] == col) {
                trans[k][0] = t[i][1];
                trans[k][1] = t[i][0];
                trans[k][2] = t[i][2];
                k++;
            }
        }
    }

    for(int i=0;i<nz;i++)
        cout << trans[i][0] << " " << trans[i][1] << " " << trans[i][2] << endl;
}
