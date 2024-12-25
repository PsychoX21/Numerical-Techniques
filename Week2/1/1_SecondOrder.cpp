#include <fstream>
#include <cmath>
using namespace std;

double doublediff (double x, double y, double ydash) {
    return (sin(x) + 2 * cos(x) - 3 * y - 4 * ydash);
}

void euler (double x, double y, double ydash, double h, double xfinal, ofstream &fout) {

    fout << x << " " << y << " " << ydash << endl;

    while(x < xfinal) {
        double newy = y + h * ydash;
        double newydash = ydash + h * doublediff(x, y, ydash);

        fout << x+h << " " << newy << " " << newydash << endl;

        x += h;
        y = newy;
        ydash = newydash;
    }
}

void rungeKutta (double x, double y, double ydash, double h, double xfinal, ofstream &fout) {

    fout << x << " " << y << " " << ydash << endl;

    while(x < xfinal) {
        double k1y = ydash;
        double k1ydash = doublediff(x, y, ydash);

        double k2y = ydash + 0.5 * h * k1ydash;
        double k2ydash = doublediff(x + 0.5 * h, y + 0.5 * h * k1y, ydash + 0.5 * h * k1ydash);

        double k3y = ydash + 0.5 * h * k2ydash;
        double k3ydash = doublediff(x + 0.5 * h, y + 0.5 * h * k2y, ydash + 0.5 * h * k2ydash);

        double k4y = ydash + h * k3ydash;
        double k4ydash = doublediff(x + h, y + h * k3y, ydash + h * k3ydash);

        double newy = y + (h / 6) * (k1y + 2 * k2y + 2 * k3y + k4y);
        double newydash = ydash + (h / 6) * (k1ydash + 2 * k2ydash + 2 * k3ydash + k4ydash);


        fout << x+h << " " << newy << " " << newydash << endl;

        x += h;
        y = newy;
        ydash = newydash;
    }
}

void exactSolution(double xinit, double xfinal, double h, ofstream &fout) {
    double x = xinit;
    while (x < xfinal) {
        double y = 3 * exp(-x) / 4 + exp(-3 * x) / 4 + sin(x) / 2;
        fout << x << " " << y << endl;
        x += h;
    }
}

int main () {
    double x = 0;
    double y = 1;
    double ydash = -1;

    ofstream euler1("euler_0.1_.txt");
    ofstream euler2("euler_0.01_.txt");
    ofstream rk("rk_0.1_.txt");
    ofstream exact("exact_solution.txt");

    euler(x, y, ydash, 0.1, 10, euler1);
    euler(x, y, ydash, 0.01, 10, euler2);
    rungeKutta(x, y, ydash, 0.1, 10, rk);
    exactSolution(0, 10, 0.01, exact);

    euler1.close();
    euler2.close();
    rk.close();
    exact.close();

    return 0;
}