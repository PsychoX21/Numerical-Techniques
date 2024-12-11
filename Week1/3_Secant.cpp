#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

double f(double x) {
    return (pow(numbers::e,2*x) + x - 5);
}

double secant(double oldx, double newx, const double& tolerance = 0.01) {
    cout << "Initial Guess: " << oldx << ", " << newx << fixed << setprecision(5) << endl;
    while (abs(oldx - newx) > tolerance) {
        double temp = newx;
        newx = newx - (newx-oldx)/(f(newx)-f(oldx)) * f(newx);
        oldx = temp;

        cout << oldx << endl;
    }
    cout << newx << endl;
    return newx;
}

int main() {
    double oldx = 0;
    double newx = 1;

    double result = secant(oldx, newx);

    cout << setprecision(2) << "\nRoot of given equation is approx: " << result << endl;

    return 0;
}

*/
OUTPUT

Initial Guess: 0, 1
1.00000
0.54134
0.68246
0.73387
0.72595

Root of given equation is approx: 0.73

*/