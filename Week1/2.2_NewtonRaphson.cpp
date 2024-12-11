#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

// radius of circle = 1
// longer circular arc is double the length of chord
// let angle subtended by chord on centre = x
// length of chord = 2sin(x/2)
// length of longer arc = 2pi-x
// so we have to find the theta such that 2chord=arc => find root of 2chord-arc=0
// let the initial guess be at 90 degrees (pi/2)

double lengthc(double x) {
    return (2*sin(x/2));
}

double f(double x) {
    return (4*sin(x/2) + x - 2*numbers::pi);
}

double fprime(double x) {
    return (2*cos(x/2) + 1);
}

double nrm(double guess, const double& length_tolerance) {
    double x = guess - f(guess)/fprime(guess);
    cout << fixed << "Guess: " << guess << setprecision(30) << endl;
    while(abs(lengthc(x)-lengthc(guess)) > length_tolerance) {
        cout << x << endl;
        guess = x;
        x = guess - f(guess)/fprime(guess);
    }

    return x;
}

int main() {
    double guess{numbers::pi/2};
    double solution_x = nrm(guess, 5*1e-19);

    cout << solution_x << endl;
    cout << setprecision(18) << "\nLength of chord is approx: " << lengthc(solution_x) << endl;

    return 0;
}

/*
OUTPUT

Guess: 1.570796
2.351158878393946327634012050112
2.486962170105318392643312108703
2.492188874777865770226981112501
2.492196773093577011337629301124
2.492196773111624352736725995783
2.492196773111624352736725995783

Length of chord is approx: 1.895494267033980940

*/