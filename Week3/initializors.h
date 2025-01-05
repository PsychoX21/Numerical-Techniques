#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

void rho_default(vector<vector<double>> &rho, int n)
{
    int offset = n / 10;
    rho[n / 2 + offset][n / 2] = 10.0;
    rho[n / 2 - offset][n / 2] = -10.0;

    for (int j = 0; j < n; ++j)
    {
        rho[0][j] = 10.0;
        rho[n - 1][j] = -10.0;
    }
}

void rho_gaussian(vector<vector<double>> &rho, int n, double amplitude = 10.0, double spread = 0.025)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = (i - n / 2) * spread;
            double dy = (j - n / 2) * spread;
            rho[i][j] = amplitude * exp(-(dx * dx + dy * dy));
        }
    }
}

void rho_chess(vector<vector<double>> &rho, int n, double charge = 10.0)
{
    int block_size = n / 8;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int block_row = i / block_size;
            int block_col = j / block_size;

            rho[i][j] = ((block_row + block_col) % 2 == 0) ? charge : -charge;
        }
    }
}

void rho_spiral(vector<vector<double>> &rho, int n, double scale = 0.2, double charge = 10.0)
{
    int center = n / 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = i - center;
            double dy = j - center;
            double r = sqrt(dx * dx + dy * dy);
            double theta = atan2(dy, dx);
            rho[i][j] = (fmod(theta + scale * r, 2 * M_PI) < M_PI) ? charge : -charge;
        }
    }
}

void rho_magnetic_dipole(vector<vector<double>> &rho, int n, double charge = 10.0)
{
    int center = n / 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = i - center;
            double dy = j - center;
            double r = sqrt(dx * dx + dy * dy);
            if (r > 0)
            {
                double theta = atan2(dy, dx);
                rho[i][j] = charge * cos(theta) / r;
            }
            else
            {
                rho[i][j] = 0.0;
            }
        }
    }
}

void rho_vortex(vector<vector<double>> &rho, int n, double charge = 10.0)
{
    int center = n / 2;
    double rotation_scale = max(3.0, n / 30.0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = i - center;
            double dy = j - center;
            double r = sqrt(dx * dx + dy * dy);
            double theta = atan2(dy, dx);
            rho[i][j] = charge * sin(rotation_scale * theta);
        }
    }
}

void rho_sinusoidal_ripple(vector<vector<double>> &rho, int n, double charge = 10.0, double frequency = 0.2)
{
    int center = n / 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            double dx = i - center;
            double dy = j - center;
            double r = sqrt(dx * dx + dy * dy);
            rho[i][j] = charge * sin(frequency * r);
        }
    }
}