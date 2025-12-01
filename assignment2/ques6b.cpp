#include <iostream>
using namespace std;

int main() {
    int a[100][3], b[100][3], c[200][3];
    int na, nb, k = 0;

    cin >> na;
    for(int i=0;i<na;i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cin >> nb;
    for(int i=0;i<nb;i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    int i = 0, j = 0;

    while(i < na && j < nb) {
        if(a[i][0]==b[j][0] && a[i][1]==b[j][1]) {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2]+b[j][2];
            i++; j++; k++;
        }
        else if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            i++; k++;
        }
        else {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            j++; k++;
        }
    }

    while(i < na) {
        c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2];
        i++; k++;
    }

    while(j < nb) {
        c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2];
        j++; k++;
    }

    for(int t=0;t<k;t++)
        cout << c[t][0] << " " << c[t][1] << " " << c[t][2] << endl;
}
