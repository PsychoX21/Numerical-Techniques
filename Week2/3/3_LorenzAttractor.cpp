#include <fstream>
#include <cmath>
using namespace std;

double xdash(double sigma, double rho, double beta, double x, double y, double z) {
    return (sigma * (y - x));
}

double ydash(double sigma, double rho, double beta, double x, double y, double z) {
    return (x * (rho - z) - y);
}

double zdash(double sigma, double rho, double beta, double x, double y, double z) {
    return (x * y - beta * z);
}

void euler(double sigma, double rho, double beta, double x, double y, double z, double tinit, double tfinal, double dt, ofstream &out)
{
    double t = tinit;

    out << t << " " << x << " " << y << " " << z << endl;

    while (t + dt / 2 < tfinal)
    {
        x += dt * xdash(sigma, rho, beta, x, y, z);
        y += dt * ydash(sigma, rho, beta, x, y, z);
        z += dt * zdash(sigma, rho, beta, x, y, z);
        t += dt;

        out << t << " " << x << " " << y << " " << z << endl;
    }
}

void rungekutta(double sigma, double rho, double beta, double x, double y, double z, double tinit, double tfinal, double dt, ofstream &out)
{
    double t = tinit;

    out << t << " " << x << " " << y << " " << z << endl;

    while (t + dt / 2 < tfinal)
    {
        double k1x = xdash(sigma, rho, beta, x, y, z);
        double k1y = ydash(sigma, rho, beta, x, y, z);
        double k1z = zdash(sigma, rho, beta, x, y, z);

        double k2x = xdash(sigma, rho, beta, x + 0.5 * dt * k1x, y + 0.5 * dt * k1y, z + 0.5 * dt * k1z);
        double k2y = ydash(sigma, rho, beta, x + 0.5 * dt * k1x, y + 0.5 * dt * k1y, z + 0.5 * dt * k1z);
        double k2z = zdash(sigma, rho, beta, x + 0.5 * dt * k1x, y + 0.5 * dt * k1y, z + 0.5 * dt * k1z);
        
        double k3x = xdash(sigma, rho, beta, x + 0.5 * dt * k2x, y + 0.5 * dt * k2y, z + 0.5 * dt * k2z);
        double k3y = ydash(sigma, rho, beta, x + 0.5 * dt * k2x, y + 0.5 * dt * k2y, z + 0.5 * dt * k2z);
        double k3z = zdash(sigma, rho, beta, x + 0.5 * dt * k2x, y + 0.5 * dt * k2y, z + 0.5 * dt * k2z);

        double k4x = xdash(sigma, rho, beta, x + dt * k3x, y + dt * k3y, z + dt * k3z);
        double k4y = ydash(sigma, rho, beta, x + dt * k3x, y + dt * k3y, z + dt * k3z);
        double k4z = zdash(sigma, rho, beta, x + dt * k3x, y + dt * k3y, z + dt * k3z);

        x += dt * (k1x + 2.0 * k2x + 2.0 * k3x + k4x) / 6;
        y += dt * (k1y + 2.0 * k2y + 2.0 * k3y + k4y) / 6;
        z += dt * (k1z + 2.0 * k2z + 2.0 * k3z + k4z) / 6;
        t += dt;

        out << t << " " << x << " " << y << " " << z << endl;
    }
}

int main() {

    double sigma = 10.0;
    double rho = 28.0;
    double beta = 8.0 / 3.0;
    double x = 0.1;
    double y = 0.1;
    double z = 0.1;

    double tinit = 0.0;
    double tfinal = 100.0;
    double dt = 0.01;

    ofstream euler_out("euler_solution.txt");
    ofstream rungekutta_out("rungekutta_solution.txt");

    euler(sigma, rho, beta, x, y, z, tinit, tfinal, dt, euler_out);
    rungekutta(sigma, rho, beta, x, y, z, tinit, tfinal, dt, rungekutta_out);

    euler_out.close();
    rungekutta_out.close();


    // RK4 for different rho

    // ofstream rk_rho14_out("rk_rho14_solution.txt");
    // ofstream rk_rho100_out("rk_rho100_solution.txt");

    // rungekutta(sigma, 14.0, beta, x, y, z, tinit, tfinal, dt, rk_rho14_out);
    // rungekutta(sigma, 99.96, beta, x, y, z, tinit, tfinal, dt, rk_rho100_out);

    // rk_rho14_out.close();
    // rk_rho100_out.close();


    // Chaotic Behavior

    // ofstream rungekutta_1("rungekutta_1.txt");
    // ofstream rungekutta_2("rungekutta_2.txt");

    // rungekutta(sigma, rho, beta, x, y, z, tinit, tfinal, dt, rungekutta_1);
    // rungekutta(sigma, rho, beta, x+0.00001, y, z, tinit, tfinal, dt, rungekutta_2);

    // rungekutta_1.close();
    // rungekutta_2.close();

    return 0;
}