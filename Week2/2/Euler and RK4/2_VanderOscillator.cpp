#include <fstream>
#include <cmath>
using namespace std;

double xdash(double mu, double x, double y) {
    return (mu * (x - pow(x, 3) / 3 - y));
}

double ydash(double mu, double x, double y) {
    return (x / mu);
}

void euler(double mu, double x, double y, double tinit, double tfinal, double dt, ofstream& out) {
    double t = tinit;

    out << t << " " << x << " " << y << endl;

    while (t +  dt/2 < tfinal) {
        x += dt * xdash(mu, x, y);
        y += dt * ydash(mu, x, y);
        t += dt;

        out << t << " " << x << " " << y << endl;
    }
}

void rungekutta(double mu, double x, double y, double tinit, double tfinal, double dt, ofstream& out) {
    double t = tinit;

    out << t << " " << x << " " << y << endl;

    while (t + dt/2 < tfinal) {
        double k1x = xdash(mu, x, y);
        double k1y = ydash(mu, x, y);

        double k2x = xdash(mu, x + 0.5 * dt * k1x, y + 0.5 * dt * k1y);
        double k2y = ydash(mu, x + 0.5 * dt * k1x, y + 0.5 * dt * k1y);

        double k3x = xdash(mu, x + 0.5 * dt * k2x, y + 0.5 * dt * k2y);
        double k3y = ydash(mu, x + 0.5 * dt * k2x, y + 0.5 * dt * k2y);

        double k4x = xdash(mu, x + dt * k3x, y + dt * k3y);
        double k4y = ydash(mu, x + dt * k3x, y + dt * k3y);

        x += dt * (k1x + 2.0 * k2x + 2.0 * k3x + k4x)/6;
        y += dt * (k1y + 2.0 * k2y + 2.0 * k3y + k4y)/6;
        t += dt;

        out << t << " " << x << " " << y << endl;
    }
}

int main() {
    double mu = 7.0;
    double x = 1.0;
    double y = 0.0;
    double tinit = 0.0;
    double tfinal = 15.0;
    double dt = 0.1;
    
    ofstream euler_out("euler_solution.txt");
    euler(mu, x, y, tinit, tfinal, dt, euler_out);

    ofstream rungekutta_out("rungekutta_solution.txt");
    rungekutta(mu, x, y, tinit, tfinal, dt, rungekutta_out);

    euler_out.close();
    rungekutta_out.close();
    
    return 0;
}