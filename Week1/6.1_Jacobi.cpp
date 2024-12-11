#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> jacobi(const vector<vector<double>>& A, const vector<double>& b,
                      const vector<double>& guess, int iterations, double tolerance) {
    int n = guess.size();
    vector<double> x(n, 0.0);
    vector<double> oldx = guess;

    cout << fixed << setprecision(8);

    for (int iteration{1}; iteration <= iterations; iteration++) {
        for (int i{0}; i < n; i++) {
            double sum{0};
            for (int j{0}; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * oldx[j];
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
    vector<double> guess = {0, 0, 0};

    vector<double> solution = jacobi(A, b, guess, 100, 1e-5);

    cout << setprecision(6);
    cout << "\nSolution: ";
    for (int i{0}; i < solution.size(); i++) {cout << solution[i] << " ";}

    return 0;
}

/*
OUTPUT

Iteration 1 : [ 0.75000000 , 1.50000000 , -0.85714286 ]
Iteration 2 : [ 0.91071429 , 1.89285714 , -0.96428571 ]
Iteration 3 : [ 0.98214286 , 1.96428571 , -0.99744898 ]
Iteration 4 : [ 0.99170918 , 1.99362245 , -0.99744898 ]
Iteration 5 : [ 0.99904337 , 1.99681122 , -1.00027332 ]
Iteration 6 : [ 0.99913448 , 1.99972668 , -0.99968112 ]
Iteration 7 : [ 1.00001139 , 1.99965835 , -1.00008460 ]
Iteration 8 : [ 0.99989344 , 2.00001790 , -0.99994957 ]
Iteration 9 : [ 1.00001708 , 1.99995607 , -1.00001778 ]
Iteration 10 : [ 0.99998457 , 2.00000866 , -0.99999128 ]
Iteration 11 : [ 1.00000434 , 1.99999341 , -1.00000344 ]
Iteration 12 : [ 0.99999749 , 2.00000202 , -0.99999844 ]
Iteration 13 : [ 1.00000090 , 1.99999890 , -1.00000065 ]

Solution: 1.000001 1.999999 -1.000001

*/