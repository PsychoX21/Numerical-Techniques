#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <sstream>
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

void plot_animation(int frames, double mu0, double dmu) {
    ofstream gnuplot_script("animation.gnuplot");

    gnuplot_script << "set terminal gif animate size 1920,1440 delay 5\n";
    gnuplot_script << "set output 'output.gif'\n";
    gnuplot_script << "set xlabel 'x'\n";
    gnuplot_script << "set ylabel 'y'\n";
    gnuplot_script << "set xrange [-4:4]\n";
    gnuplot_script << "set yrange [-4:4]\n";

    for (int i = 0; i < frames; ++i){
        double mu = mu0 + i * dmu;
        string datafile = "Data/" + to_string(i) + ".txt";
        gnuplot_script << "plot '" << datafile << "' using 2:3 with lines title 'mu = " << mu << "'\n";
    }
    gnuplot_script.close();
    system("gnuplot animation.gnuplot");
}

int main() {
    double x = 2;
    double y = 0;
    double tinit = 0.0;
    double tfinal = 200.0;
    double dt = 0.1;
    double mu = 0.1;

    for (int iterations = 0; iterations <= 390; ++iterations, mu += 0.01) {
        ofstream rungekutta_out("Data/" + to_string(iterations) + ".txt");
        rungekutta(mu, x, y, tinit, tfinal, dt, rungekutta_out);
        rungekutta_out.close();
    }

    plot_animation(390, 0.1, 0.01);
    
    return 0;
}

