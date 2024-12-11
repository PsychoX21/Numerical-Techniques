#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

double diff(double x, double y) {
    return (pow(x,3)*pow(exp(1),-2*x) - 2*y );
}

int main() {
    const double h = 0.025;
    double x = 0;
    double y = 1;

    const string filename = "euler_" + to_string(h) + "_.txt";
    ofstream file(filename);

    file << fixed;

    for (int i = 0; i <= 1/h; i++) {
        file << setprecision(3) << x << " " << setprecision(8) << y << endl;
        y += h * diff(x,y);
        x += h ;
    }

    file.close();

    return 0;
}