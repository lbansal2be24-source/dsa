#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};

// Function to read a sparse matrix in triplet form
vector<Triplet> readSparseMatrix(int rows, int cols, int nonZero) {
    vector<Triplet> mat;
    cout << "Enter (row col value) for " << nonZero << " non-zero elements:\n";
    for (int i = 0; i < nonZero; i++) {
        Triplet t;
        cin >> t.row >> t.col >> t.val;
        mat.push_back(t);
    }
    return mat;
}

// Function to display sparse matrix triplet
void displayTriplet(const vector<Triplet>& mat) {
    cout << "Row\tCol\tValue\n";
    for (auto &t : mat) {
        cout << t.row << "\t" << t.col << "\t" << t.val << "\n";
    }
}

// Transpose of sparse matrix
vector<Triplet> transposeSparseMatrix(const vector<Triplet>& mat) {
    vector<Triplet> trans;
    for (auto &t : mat) {
        Triplet newT;
        newT.row = t.col;
        newT.col = t.row;
        newT.val = t.val;
        trans.push_back(newT);
    }
    return trans;
}

// Addition of two sparse matrices
vector<Triplet> addSparseMatrix(const vector<Triplet>& A, const vector<Triplet>& B) {
    vector<Triplet> sum;
    sum.reserve(A.size() + B.size());

    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            sum.push_back(A[i++]);
        } 
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            sum.push_back(B[j++]);
        } 
        else {
            Triplet t = A[i];
            t.val += B[j].val;
            if (t.val != 0) sum.push_back(t);
            i++; j++;
        }
    }
    while (i < A.size()) sum.push_back(A[i++]);
    while (j < B.size()) sum.push_back(B[j++]);

    return sum;
}

// Multiplication of two sparse matrices
vector<Triplet> multiplySparseMatrix(const vector<Triplet>& A, const vector<Triplet>& B, int rowsA, int colsA, int colsB) {
    vector<Triplet> product;

    // Convert B to its transpose to make column access easier
    vector<Triplet> BT = transposeSparseMatrix(B);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (auto &a : A) {
                if (a.row == i) {
                    for (auto &b : BT) {
                        if (b.row == j && b.col == a.col) {
                            sum += a.val * b.val;
                        }
                    }
                }
            }
            if (sum != 0) {
                Triplet t = {i, j, sum};
                product.push_back(t);
            }
        }
    }
    return product;
}

int main() {
    int rowsA, colsA, nonZeroA;
    int rowsB, colsB, nonZeroB;

    cout << "Enter rows, cols and non-zero count for Matrix A: ";
    cin >> rowsA >> colsA >> nonZeroA;
    vector<Triplet> A = readSparseMatrix(rowsA, colsA, nonZeroA);

    cout << "Enter rows, cols and non-zero count for Matrix B: ";
    cin >> rowsB >> colsB >> nonZeroB;
    vector<Triplet> B = readSparseMatrix(rowsB, colsB, nonZeroB);

    cout << "\nMatrix A (Triplet Form):\n";
    displayTriplet(A);

    cout << "\nMatrix B (Triplet Form):\n";
    displayTriplet(B);

    // Transpose
    cout << "\nTranspose of A:\n";
    displayTriplet(transposeSparseMatrix(A));

    // Addition
    if (rowsA == rowsB && colsA == colsB) {
        cout << "\nA + B (Triplet Form):\n";
        displayTriplet(addSparseMatrix(A, B));
    } else {
        cout << "\nAddition not possible (Dimension mismatch).\n";
    }

    // Multiplication
    if (colsA == rowsB) {
        cout << "\nA * B (Triplet Form):\n";
        displayTriplet(multiplySparseMatrix(A, B, rowsA, colsA, colsB));
    } else {
        cout << "\nMultiplication not possible (Dimension mismatch).\n";
    }

    return 0;
}
