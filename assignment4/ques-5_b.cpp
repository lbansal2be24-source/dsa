#include <iostream>
using namespace std;

int main() {
    int n, ch = 0, x;
    cout << "Enter size of stack: ";
    cin >> n;

    int q[100];  // single queue
    int f = -1, r = -1; // front and rear

    while (ch != 4) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1: // Push
                cout << "Enter value: ";
                cin >> x;

                if (r == n - 1 && f == 0) {   // queue completely full
                    cout << "Stack Overflow\n";
                    break;
                }

                if (f == -1) {  // first element
                    f = 0;
                    r = 0;
                    q[r] = x;
                } else {
                    q[++r] = x;

                    // Rotate the queue: bring new element to front
                    for (int i = f; i < r; i++) {
                        int temp = q[f];
                        for (int j = f; j < r; j++) {
                            q[j] = q[j + 1];
                        }
                        q[r] = temp;
                    }
                }
                break;

            case 2: // Pop
                if (f == -1 || f > r) {
                    cout << "Stack Underflow\n";
                } else {
                    cout << "Popped: " << q[f++] << endl;
                    // Reset when queue becomes empty
                    if (f > r) {
                        f = -1;
                        r = -1;
                    }
                }
                break;

            case 3: // Top
                if (f == -1 || f > r) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Top element: " << q[f] << endl;
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    }
}
;