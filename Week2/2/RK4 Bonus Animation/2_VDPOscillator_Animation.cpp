#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

double xdash(double mu, double x, double y) {
    return (mu * (x - pow(x, 3) / 3 - y));
}

double ydash(double mu, double x, double y) {
    return (x / mu);
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
    double tinit = 0.0;
    double tfinal = 30.0;
    double dt = 0.01;
    double mu = 7;
    double W = 4.0;
    double H = 4.0;

    srand(time(0));

    for (int particles = 1; particles <= 50; ++particles) {
        double x = (rand()/double(RAND_MAX)) * 8 - 4;
        double y = (rand()/double(RAND_MAX)) * 8 - 4;

        ofstream rungekutta_out("Data/" + to_string(particles) + ".txt");
        rungekutta(mu, x, y, tinit, tfinal, dt, rungekutta_out);
        rungekutta_out.close();
    }
    
    return 0;
}