#include <iostream>
using namespace std;

int main() {
    int a[100][3], b[100][3], c[100][3];
    int na, nb, k = 0;

    cin >> na;
    for(int i=0;i<na;i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    cin >> nb;
    for(int i=0;i<nb;i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];

    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(a[i][1] == b[j][0]){
                bool found = false;
                for(int x=0;x<k;x++){
                    if(c[x][0]==a[i][0] && c[x][1]==b[j][1]){
                        c[x][2] += a[i][2] * b[j][2];
                        found = true;
                        break;
                    }
                }
                if(!found){
                    c[k][0] = a[i][0];
                    c[k][1] = b[j][1];
                    c[k][2] = a[i][2] * b[j][2];
                    k++;
                }
            }
        }
    }

    for(int i=0;i<k;i++)
        cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << endl;
}
