#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

//Runge Kutta Coefficients
// 1
// 1/2 1/2
// 1/6 4/6 1/6
// 1/6 2/6 2/6 1/6

double f(double x, double y) {
    return (pow(x,3)*pow(exp(1),-2*x) - 2*y );
}

int main() {
    const double h = 0.1;
    double x = 0, y = 1;

    ofstream fout("rungekutta.txt");

    fout << fixed;

    for (int i = 0; i <= 1/h; i++) {
        fout << setprecision(1) << x << " " << setprecision(8) << y << endl;
        double k1 = h * f(x,y);
        double k2 = h * f(x+h/2,y+k1/2);
        double k3 = h * f(x+h/2,y+k2/2);
        double k4 = h * f(x+h,y+k3);

        y += (k1 + 2*k2 + 2*k3 + k4)/6;
        x += h ;
    }

    return 0;
}