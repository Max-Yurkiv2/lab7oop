#include "Matrix.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Example for int
    cout << "=== Matrix of type int ===\n";
    Matrix<int> A(2, 2), B(2, 2);
    A.input();
    B.input();

    cout << "\nA + B:\n";
    (A + B).print();

    cout << "\nA * B:\n";
    (A * B).print();

    vector<int> v = { 1, 2 };
    cout << "\nA * vector:\n";
    vector<int> res = A * v;
    for (auto valIt = res.begin(); valIt != res.end(); ++valIt) {
        cout << *valIt << " ";
    }
    cout << "\n";

    // Example for float
    cout << "\n=== Matrix of type float ===\n";
    Matrix<float> C(2, 2), D(2, 2);
    C.input();
    D.input();

    cout << "\nC + D:\n";
    (C + D).print();

    cout << "\nC * D:\n";
    (C * D).print();

    vector<float> vf = { 1.5, 2.5 };
    cout << "\nC * vector:\n";
    vector<float> resf = C * vf;
    for (auto valIt = resf.begin(); valIt != resf.end(); ++valIt) {
        cout << *valIt << " ";
    }
    cout << "\n";

    return 0;
}
