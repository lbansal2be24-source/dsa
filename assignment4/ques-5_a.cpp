#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    int q1[n], q2[n];   
    int f1 = -1, r1 = -1; 
    int f2 = -1, r2 = -1; 

    int choice = 0, x;

    while (choice != 4) {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {  // Push
                cout << "Enter value: ";
                cin >> x;

                int size = (f1 == -1) ? 0 : (r1 - f1 + 1);
                if (size == n) {
                    cout << "Stack Overflow\n";
                    break;
                }

                if (f1 == -1) {
                    // first element
                    f1 = r1 = 0;
                    q1[r1] = x;
                } else {
                    // put new element in q2
                    f2 = 0; r2 = -1;
                    q2[++r2] = x;

                    // move all elements from q1 to q2
                    while (!(f1 == -1 || f1 > r1)) {
                        q2[++r2] = q1[f1++];
                    }

                    // copy back q2 into q1
                    f1 = 0; r1 = -1;
                    for (int i = f2; i <= r2; i++) {
                        q1[++r1] = q2[i];
                    }

                    // reset q2
                    f2 = r2 = -1; 
                }
                break;
            }

            case 2: {  // Pop
                if (f1 == -1 || f1 > r1) {
                    cout << "Stack Underflow\n";
                } else {
                    cout << "Popped: " << q1[f1++] << endl;
                    if (f1 > r1) { // reset after empty
                        f1 = r1 = -1;
                    }
                }
                break;
            }

            case 3: {  // Top
                if (f1 == -1 || f1 > r1) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Top element: " << q1[f1] << endl;
                }
                break;
            }

            case 4: {  // Exit
                cout << "Exiting...\n";
                break;
            }

            default: {  // Invalid
                cout << "Invalid choice!\n";
                break;
            }
        }
    }

    return 0;
}