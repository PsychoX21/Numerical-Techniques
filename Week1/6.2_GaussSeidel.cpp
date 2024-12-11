#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> gauss_seidel (const vector<vector<double>>& A, const vector<double>& b,
                      vector<double>& x, int iterations, double tolerance) {
    int n = x.size();
    vector<double> oldx{x};

    cout << fixed << setprecision(8);

    for (int iteration{1}; iteration <= iterations; iteration++) {
        for (int i{0}; i < n; i++) {
            double sum{0};
            for (int j{0}; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        cout << "Iteration " << iteration << " : [ ";
        for (int i{0}; i < n-1; i++) { cout << x[i] << " , "; }
        cout << x[n-1] << " ]" << endl;

        double diff = 0.0;
        for (int i = 0; i < n; i++) {
            diff += (x[i] - oldx[i]) * (x[i] - oldx[i]);
        }

        if (diff < tolerance * tolerance) {
            return x;
        }

        oldx = x;
    }

    return x;
}

int main() {
    vector<vector<double>> A = {{4, -1, -1},{-2, 6, 1},{-1, 1, 7}};
    vector<double> b = {3, 9, -6};
    vector<double> x = {0, 0, 0};

    gauss_seidel(A, b, x, 100, 1e-5);

    cout << setprecision(6);
    cout << "\nSolution: ";
    for (int i{0}; i < x.size(); i++) {cout << x[i] << " ";}

    return 0;
}

/*
OUTPUT

Iteration 1 : [ 0.75000000 , 1.75000000 , -1.00000000 ]
Iteration 2 : [ 0.93750000 , 1.97916667 , -1.00595238 ]
Iteration 3 : [ 0.99330357 , 1.99875992 , -1.00077948 ]
Iteration 4 : [ 0.99949511 , 1.99996162 , -1.00006664 ]
Iteration 5 : [ 0.99997374 , 2.00000236 , -1.00000409 ]
Iteration 6 : [ 0.99999957 , 2.00000054 , -1.00000014 ]
Iteration 7 : [ 1.00000010 , 2.00000006 , -0.99999999 ]

Solution: 1.000000 2.000000 -1.000000

*/