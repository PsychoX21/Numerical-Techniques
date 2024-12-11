#include <complex>
#include <iomanip>
#include <iostream>
using namespace std;

double f(double x) {return x*x-8*x+11;}
double fprime(double x) {return 2*x-8;}

double nrm(double guess, const double& tolerance) {
    double x = guess - f(guess)/fprime(guess);
    cout << fixed << "Guess: " << guess << setprecision(10) << endl;
    while(abs(x-guess)>tolerance) {
        cout << x << endl;
        guess = x;
        x = guess - f(guess)/fprime(guess);
    }

    return x;
}

int main() {
    double guess{6};
    double solution = nrm(guess, 5*1e-6);
    cout << setprecision(5) << "\nRoot of given equation is approx: " << solution << endl;

    return 0;
}


/*
OUTPUT
Guess: 6.000000
6.2500000000
6.2361111111
6.2360679779

Root of given equation is approx: 6.23607

*/